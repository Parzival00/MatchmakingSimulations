//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Peer.h"

Define_Module(Peer);

void Peer::initialize()
{
    peerID = getIndex();
    elo = par("elo");
    packetLossProbability = par("packetLossProbability").doubleValue();

    // Register signals for statistics
    rttSignal = registerSignal("rtt");
    packetLossSignal = registerSignal("packetLoss");

    cMessage *startMatchmakingMsg = new cMessage("startMatchmaking");
    scheduleAt(simTime() + uniform(0, 1), startMatchmakingMsg);
}

void Peer::handleMessage(cMessage *msg) {
    if (strcmp(msg->getName(), "startMatchmaking") == 0) {
        performMatchmaking();
        delete msg;
    } else if (strcmp(msg->getName(), "ping") == 0) {
        // Simulate packet loss on reception
        if (uniform(0, 1) < packetLossProbability) {
            packetsLost++;
            EV << "Packet lost on reception at peer " << peerID << "\n";
            emit(packetLossSignal, packetsLost);
            delete msg;
            return;
        }

        packetsReceived++;
        send(msg, "out");  // Send back as a reply (pong)
    } else if (strcmp(msg->getName(), "pong") == 0) {
        // This is the reply to a ping we sent
        simtime_t rtt = simTime() - msg->getCreationTime();
        emit(rttSignal, rtt.dbl());  // Record RTT
        delete msg;
    }
}

void Peer::performMatchmaking() {
    int totalPeers = getParentModule()->par("numPeers").intValue();
    bool matchFound = false;

    for (int i = 0; i < totalPeers; ++i) {
        if (i != peerID) {
            Peer *otherPeer = check_and_cast<Peer *>(getParentModule()->getSubmodule("peer", i));
            int otherElo = otherPeer->par("elo");

            if (abs(elo - otherElo) < 50) {
                EV << "Matched peer " << peerID << " with peer " << i << "\n";
                matchFound = true;
                sendPing(i);
                break;
            }
        }
    }

    if (!matchFound) {
        EV << "No match found for peer " << peerID << "\n";
    }
}

void Peer::sendPing(int targetPeer) {
    // Create and schedule a ping message
    cMessage *pingMsg = new cMessage("ping");

    // Simulate packet loss on sending
    if (uniform(0, 1) < packetLossProbability) {
        packetsLost++;
        EV << "Packet lost on sending from peer " << peerID << "\n";
        emit(packetLossSignal, packetsLost);
        delete pingMsg;
    } else {
        packetsSent++;
        send(pingMsg, "out");
    }
}
