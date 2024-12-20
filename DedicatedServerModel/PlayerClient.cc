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

#include "PlayerClient.h"
#include <random>
#include <cmath>

Define_Module(PlayerClient);

void PlayerClient::initialize()
{
    bool usingSBMM = false;
    static int playerCounter = 0;
    static std::default_random_engine generator;
    double deviation = 0;

    if(usingSBMM){
        deviation = 50;
    }
    else{
        deviation = 200;
    }
    std::normal_distribution<double> distribution(1500.0, deviation); //gets a random number with a mean of 1500 and a standard deviation of 200 to represent the players ELO score
    elo = distribution(generator); //assigns the randomly generated ELO to the player based on the normal distribution



    eloVector.setName("ELO");
    eloVector.record(elo);

    playerId = playerCounter++;
    teamNumber = playerId%2; //Assigns the player to a team based on their ID in the lobby
    teamVector.setName("TeamNumber");
    teamVector.record(teamNumber);

    pingVector.setName("Ping");

    cMessage *information = new cMessage();
    startTime = simTime();
    send(information, "port$o", 0); //Starts the timer for ping when the first message is sent
}

void PlayerClient::handleMessage(cMessage *msg) //Response to receiving a message from the server
{
    endTime = simTime(); // Captures the time the message is received
    timeTaken += endTime.inUnit(SIMTIME_MS) - startTime.inUnit(SIMTIME_MS); // Records the difference in time between when it is received and sent
    averageMessage = abs(timeTaken/++messagesReceived); //Calculates the overall average ping
    pingVector.record(averageMessage);

    EV << "Message Received";
    cMessage *answer = new cMessage();

    startTime = simTime();
    sendDelayed(answer, uniform(10,60), "port$o", 0);

    delete msg;
}
