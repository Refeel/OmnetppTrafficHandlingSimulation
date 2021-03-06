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

#ifndef POISSONPACKETGENERATOR_H_
#define POISSONPACKETGENERATOR_H_

#include <PacketGenerator.h>
//#include <SimplePacket_m.h>
//#include <omnetpp.h>

namespace omnetpptraffichandlingsimulation {

class PoissonPacketGenerator : public PacketGenerator {
public:
    PoissonPacketGenerator();
    virtual ~PoissonPacketGenerator();

    virtual SimplePacket *generatePacket(); // overrided
    virtual simtime_t getDelay();   // overrided



protected:
    virtual void handleMessage(cMessage *msg);  // overrided


};

Define_Module(PoissonPacketGenerator);

} /* namespace omnetpptraffichandlingsimulation */
#endif /* POISSONPACKETGENERATOR_H_ */
