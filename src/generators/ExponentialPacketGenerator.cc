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

#include "ExponentialPacketGenerator.h"

namespace omnetpptraffichandlingsimulation {

ExponentialPacketGenerator::ExponentialPacketGenerator() {
    // TODO Auto-generated constructor stub

}

ExponentialPacketGenerator::~ExponentialPacketGenerator() {
    // TODO Auto-generated destructor stub
}

simtime_t ExponentialPacketGenerator::getDelay() {
    simtime_t time = exponential(par("exponentialDelayTime").doubleValue());
    return time;
}


SimplePacket *ExponentialPacketGenerator::generatePacket() {

    int dest = 0;
    int src = 0;

    char msgname[20];
    sprintf(msgname, "EXP%d", this->_packetsCount++);

    SimplePacket *sp = new SimplePacket(msgname);

    sp->setDST(dest);
    sp->setSRC(src);
    sp->setSessionId(0);
    sp->setPacketId(this->_packetsCount);
    sp->setPriority(this->_packetsPriority);
    sp->setLength(intuniform(1, this->_packetsLength));
    sp->setPayload("payload");

    return sp;
}

void ExponentialPacketGenerator::handleMessage(cMessage *msg) {
    if (msg == event) { // received timing message
        if (this->_packetsCount < this->_packetsNumber) {
            this->generatedPacket = generatePacket(); // generate periodic packet

            forwardPacket(this->generatedPacket); // send to random node

            this->generatedPacket = NULL; // remove after send


            simtime_t delay = getDelay();
            hist.collect(delay);
            //vec.record(delay);
            scheduleAt(simTime() + delay, event);

            std::string buf;
            sprintf((char*) buf.c_str(), "Packet number %d generated with delay %lf", this->_packetsCount, delay.dbl());
            EV << buf.c_str();
            bubble(buf.c_str());

        }

    } else { // received true packet
        // processing received packet....
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

        if (sPacket->getDST() == getIndex()) {
            EV << "Packet " << sPacket << " arrived\n";

            delete sPacket;
        } else {
            forwardPacket(sPacket);
        }

    }
}

} /* namespace omnetpptraffichandlingsimulation */
