/*
 * SchedulerRoundRobin.cpp
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "SchedulerRoundRobin.h"

namespace omnetpptraffichandlingsimulation {

SchedulerRoundRobin::SchedulerRoundRobin() {
    // TODO Auto-generated constructor stub

}

SchedulerRoundRobin::~SchedulerRoundRobin() {
    // TODO Auto-generated destructor stub
}

void SchedulerRoundRobin::handleMessage(cMessage *msg) {

        if(msg==this->msgServiced)
        {
            for(int i=0;i<=numOfPriorityClasses; i++) {
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
                simtime_t serviceTime = serviceMsg(queue->front());
                queue->pop();
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

            if(packetQueues->at(sp->getPriority())->size() < this->maxPacketsInQueue) // if queue is not full
                packetQueues->at(sp->getPriority())->push(sp);
            else {   // else reject packet
                sp = NULL;
                numRejectedPackets++;
                bubble("packet rejected");
            }

        }

        for(int i=0;i<numOfPriorityClasses;i++)
            EV <<"\nqueue"<<i<<" :" << packetQueues->at(i)->size();

}


} /* namespace omnetpptrafficgenerators */
