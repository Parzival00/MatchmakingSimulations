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


network DedicatedServerNetwork
{
    parameters:
        int n;
        @display("bgb=534,1103");
    submodules:
        client[n]: PlayerClient {
            parameters:
                playerId = parent.n;
                @display("i=device/laptop;p=24,44,col,100");
        }
        server: Server {
            @display("i=device/server;p=494,518");
        }
    connections:
        client[0].port++ <--> server.port++;
        client[1].port++ <--> server.port++;
        client[2].port++ <--> server.port++;
        client[3].port++ <--> server.port++;
        client[4].port++ <--> server.port++;
        client[5].port++ <--> server.port++;
        client[6].port++ <--> server.port++;
        client[7].port++ <--> server.port++;
        client[8].port++ <--> server.port++;
        client[9].port++ <--> server.port++;
}
