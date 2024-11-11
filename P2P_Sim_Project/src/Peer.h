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

#ifndef __P2P_SIM_PROJECT_PEER_H_
#define __P2P_SIM_PROJECT_PEER_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Peer : public cSimpleModule
{
    private:
        int elo;
        int peerID;
        double packetLossProbability;  // Probability of packet loss
        int packetsSent = 0;
        int packetsReceived = 0;
        int packetsLost = 0;  // Counter for lost packets
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        void performMatchmaking();
        void sendPing(int targetPeer);
    private:
        simsignal_t rttSignal;        // Signal for recording RTT (ping)
        simsignal_t packetLossSignal; // Signal for recording packet loss
};

#endif
