/*
 * Scheduler.h
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <SimplePacket_m.h>
#include <PacketPriority.h>
//#include <omnetpp.h>
#include <vector>
#include <queue>

namespace omnetpptraffichandlingsimulation {

class Scheduler : public cSimpleModule{
public:
    Scheduler();
    virtual ~Scheduler();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);  // to override
    virtual void finish();


    virtual simtime_t serviceMsg(SimplePacket *sp);

    cMessage *msgServiced;
    std::vector <std::queue<SimplePacket *> *> *packetQueues;
    std::queue<SimplePacket *> *packetQueue;
    bool isMsgServiced;

    int numOfPriorityClasses;
    int maxPacketsInQueue;

};

Define_Module(Scheduler);

} /* namespace omnetpptrafficgenerators */
#endif /* SCHEDULER_H_ */
