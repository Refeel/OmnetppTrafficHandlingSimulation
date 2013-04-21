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

#include "DeficitRoundRobin.h"

namespace omnetpptraffichandlingsimulation {

DeficitRoundRobin::DeficitRoundRobin() {
    // TODO Auto-generated constructor stub

}

DeficitRoundRobin::~DeficitRoundRobin() {
    // TODO Auto-generated destructor stub
}

void DeficitRoundRobin::initialize() {
    Scheduler::initialize();

    deficits.resize(numOfPriorityClasses);
    for(int i=0; i<numOfPriorityClasses; i++)
        deficits[i] = 0;

}

void DeficitRoundRobin::handleMessage(cMessage *msg) {

        if(msg==this->msgServiced)
        {
            for(int i=0;i<numOfPriorityClasses; i++) {
                cycle = (cycle + 1) % numOfPriorityClasses;
                if(!(packetQueues->at(cycle)->empty()))
                    break;
            }

            std::queue <SimplePacket *> *queue = packetQueues->at(cycle);

            if(queue->empty())
            {
                isMsgServiced = false;
            }
            else
            {
                simtime_t serviceTime = 0;

                for(int i=0; i<weights[cycle]; i++) {
                    if(!queue->empty())
                    {
                        serviceTime += serviceMsg(queue->front());
                        queue->pop();
                    }
                    else
                        break;
                }

                isMsgServiced = true;
                scheduleAt(simTime() + serviceTime, msgServiced);
            }
        }
        else if(!isMsgServiced) {
            simtime_t serviceTime = serviceMsg(check_and_cast<SimplePacket *> (msg));
            isMsgServiced = true;
            scheduleAt(simTime() + serviceTime, msgServiced);
        }
        else {
            SimplePacket *sp = check_and_cast<SimplePacket *> (msg);
            packetQueues->at(sp->getPriority())->push(sp);

        }

}

} /* namespace omnetpptraffichandlingsimulation */
