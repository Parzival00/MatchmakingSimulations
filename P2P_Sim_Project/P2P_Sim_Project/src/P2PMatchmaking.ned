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

package p2p_sim_project;

network P2PMatchmaking
{
    parameters:
        int numPeers = default(10);  
    submodules:
        peer[numPeers]: Peer {
            parameters:
                @display("p=100,100+i*50");
        }
connections allowunconnected:
    peer[0].out --> peer[1].in; peer[1].out --> peer[0].in;
    peer[0].out --> peer[2].in; peer[2].out --> peer[0].in;
    peer[0].out --> peer[3].in; peer[3].out --> peer[0].in;
    peer[0].out --> peer[4].in; peer[4].out --> peer[0].in;
    peer[0].out --> peer[5].in; peer[5].out --> peer[0].in;
    peer[0].out --> peer[6].in; peer[6].out --> peer[0].in;
    peer[0].out --> peer[7].in; peer[7].out --> peer[0].in;
    peer[0].out --> peer[8].in; peer[8].out --> peer[0].in;
    peer[0].out --> peer[9].in; peer[9].out --> peer[0].in;

    peer[1].out --> peer[2].in; peer[2].out --> peer[1].in;
    peer[1].out --> peer[3].in; peer[3].out --> peer[1].in;
    peer[1].out --> peer[4].in; peer[4].out --> peer[1].in;
    peer[1].out --> peer[5].in; peer[5].out --> peer[1].in;
    peer[1].out --> peer[6].in; peer[6].out --> peer[1].in;
    peer[1].out --> peer[7].in; peer[7].out --> peer[1].in;
    peer[1].out --> peer[8].in; peer[8].out --> peer[1].in;
    peer[1].out --> peer[9].in; peer[9].out --> peer[1].in;

    peer[2].out --> peer[3].in; peer[3].out --> peer[2].in;
    peer[2].out --> peer[4].in; peer[4].out --> peer[2].in;
    peer[2].out --> peer[5].in; peer[5].out --> peer[2].in;
    peer[2].out --> peer[6].in; peer[6].out --> peer[2].in;
    peer[2].out --> peer[7].in; peer[7].out --> peer[2].in;
    peer[2].out --> peer[8].in; peer[8].out --> peer[2].in;
    peer[2].out --> peer[9].in; peer[9].out --> peer[2].in;

    peer[3].out --> peer[4].in; peer[4].out --> peer[3].in;
    peer[3].out --> peer[5].in; peer[5].out --> peer[3].in;
    peer[3].out --> peer[6].in; peer[6].out --> peer[3].in;
    peer[3].out --> peer[7].in; peer[7].out --> peer[3].in;
    peer[3].out --> peer[8].in; peer[8].out --> peer[3].in;
    peer[3].out --> peer[9].in; peer[9].out --> peer[3].in;

    peer[4].out --> peer[5].in; peer[5].out --> peer[4].in;
    peer[4].out --> peer[6].in; peer[6].out --> peer[4].in;
    peer[4].out --> peer[7].in; peer[7].out --> peer[4].in;
    peer[4].out --> peer[8].in; peer[8].out --> peer[4].in;
    peer[4].out --> peer[9].in; peer[9].out --> peer[4].in;

    peer[5].out --> peer[6].in; peer[6].out --> peer[5].in;
    peer[5].out --> peer[7].in; peer[7].out --> peer[5].in;
    peer[5].out --> peer[8].in; peer[8].out --> peer[5].in;
    peer[5].out --> peer[9].in; peer[9].out --> peer[5].in;

    peer[6].out --> peer[7].in; peer[7].out --> peer[6].in;
    peer[6].out --> peer[8].in; peer[8].out --> peer[6].in;
    peer[6].out --> peer[9].in; peer[9].out --> peer[6].in;

    peer[7].out --> peer[8].in; peer[8].out --> peer[7].in;
    peer[7].out --> peer[9].in; peer[9].out --> peer[7].in;

    peer[8].out --> peer[9].in; peer[9].out --> peer[8].in;