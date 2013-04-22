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

#include "SchedulerDeficitRoundRobin.h"

namespace omnetpptraffichandlingsimulation {

SchedulerDeficitRoundRobin::SchedulerDeficitRoundRobin() {
    // TODO Auto-generated constructor stub

}

SchedulerDeficitRoundRobin::~SchedulerDeficitRoundRobin() {
    // TODO Auto-generated destructor stub
}

void SchedulerDeficitRoundRobin::initialize() {
    Scheduler::initialize();

    deficits.resize(numOfPriorityClasses);
    for(int i=0; i<numOfPriorityClasses; i++)
        deficits[i] = 0;

    lengthQuant = (int)par("lengthQuant");  // quant of bytes

}

void SchedulerDeficitRoundRobin::handleMessage(cMessage *msg)
{
        if(msg==this->msgServiced)
        {
            for(int i=0;i<=numOfPriorityClasses; i++) {
                cycle = (cycle + 1) % numOfPriorityClasses;
                if(!(packetQueues->at(cycle)->empty()))
                    break;
                else
                    deficits[cycle] = 0;
            }

            std::queue <SimplePacket *> *queue = packetQueues->at(cycle);

            deficits[cycle] += lengthQuant;

            if(queue->empty())
            {
                isMsgServiced = false;
            }
            else
            {
                simtime_t serviceTime = 0;

                size_t qsize = queue->size();
                for(unsigned int i=0; i < qsize; i++)
                {
                    if(deficits[cycle] >= queue->front()->getLength())
                    {
                        serviceTime += serviceMsg(queue->front());
                        deficits[cycle] -= queue->front()->getLength();
                        queue->pop();
                        isMsgServiced = true;
                    }
                    else
                        break;
                }

                scheduleAt(simTime() + serviceTime, msgServiced);

                EV << "\ncycle " << cycle;
                for(int i=0;i<numOfPriorityClasses;i++)
                    EV <<"\nqueue"<<i<<" :" << packetQueues->at(i)->size() <<"deficit: " << deficits[i];
            }
        }
        else if(!isMsgServiced)
        {
            simtime_t serviceTime = serviceMsg(check_and_cast<SimplePacket *> (msg));
            isMsgServiced = true;
            scheduleAt(simTime() + serviceTime, msgServiced);
        }
        else
        {
            SimplePacket *sp = check_and_cast<SimplePacket *> (msg);

            if(packetQueues->at(sp->getPriority())->size() < this->maxPacketsInQueue) // if queue is not full
                packetQueues->at(sp->getPriority())->push(sp);
            else {   // else reject packet
                sp = NULL;
                bubble("packet rejected");
            }
        }


}

} /* namespace omnetpptraffichandlingsimulation */
