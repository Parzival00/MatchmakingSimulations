In this repository you can find two projects made in OMNet++.
The first is the model using dedicated servers to host a simulated "game" of 10 players exchanging information with the server.
The other project models a peer-to-peer system with the same goal.

The goal for this project is to gain an understanding of each model's strengths and weaknessess. It will evaluate 
which model works best for hosting game sessions for small groups of players. Additionally, while testing which architectures works best, 
different matchmaking protocols will also be tested to understand the benefits of using skill-based matchmaking as opposed to randomly 
matching players. 

To elvaluate each model, we will run multiple trials using each model with each matchmaking protocol, then compile the results data 
provided by OMNet++ in the project itself. Some changes may still be made moving forward to ensure the accuracy and validity of these 
simulations based on research gathered. As actual matchmaking systems at a large scale isn't best suited by OMNet++, to simulate different
matchmaking protocols, each player will be assigned their ELO rating according to a normal distribution using a mean of 1500 and a standard
deviation of 200. To simulate skill-based matchmaking, the mean will vary slightly from match to match, and use a smaller standard deviation,
simulating finding a match of players, closer together in skill level. The final satisfaction index will be calculated as a result of a 
calculation using data such as the averaging ping, packet loss, and difference in average skill level between teams. A simple draft of the 
formula would look something like the following:

(AveragePing * AveragePacketLoss)/(1 + AbsoluteValue(AverageDifferenceInSkill))

The new UML document is located in the same directory in the repository as this README file. The changes to it are as follows:
Parameters such as location, networking speed, and processing speed, are being removed from the explicit parameters enumerated in the client
class because the data impacted by these parameters can be controlled more precisely and clearly through settings included in OMNet++. 
The same is true for the server class.

Also linked in the repository is the Literature review which as of now has no changes made. 

Here is another link to the repo if you are reading this from the D2L submission:
https://github.com/Parzival00/MatchmakingSimulations
