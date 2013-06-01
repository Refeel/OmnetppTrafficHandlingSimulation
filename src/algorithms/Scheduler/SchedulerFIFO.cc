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

#include "SchedulerFIFO.h"

namespace omnetpptraffichandlingsimulation {

SchedulerFIFO::SchedulerFIFO() {
    // TODO Auto-generated constructor stub

}

SchedulerFIFO::~SchedulerFIFO() {
    // TODO Auto-generated destructor stub
}

void SchedulerFIFO::handleMessage(cMessage *msg) {

    if(msg==this->msgServiced)
    {
        if(packetQueue->empty())
        {
            isMsgServiced = false;
        }
        else
        {
            simtime_t serviceTime = serviceMsg(packetQueue->front());
            packetQueue->pop();
            isMsgServiced = true;
            scheduleAt(simTime() + serviceTime, msgServiced);
        }
    }
    else if(!isMsgServiced) {
        SimplePacket *sp = check_and_cast<SimplePacket *> (msg);
        sp->setInTime(simTime().dbl());
        numIncPackets++;

        simtime_t serviceTime = serviceMsg(sp);
        isMsgServiced = true;
        scheduleAt(simTime() + serviceTime, msgServiced);
    }
    else {
        SimplePacket *sp = check_and_cast<SimplePacket *> (msg);
        sp->setInTime(simTime().dbl());
        numIncPackets++;

        if(packetQueue->size() < this->maxPacketsInQueue)   // if queue is not full
            packetQueue->push(sp);
        else {// reject packet
            msg = NULL;
            numRejectedPackets++;
            bubble("packet rejected");
        }
    }

    EV<<"qsize: " << packetQueue->size();
}

} /* namespace omnetpptraffichandlingsimulation */
