/*
 * Scheduler.h
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <SimplePacket_m.h>
#include <omnetpp.h>
#include <PacketPriority.h>


namespace omnetpptraffichandlingsimulation {

class Scheduler : public cSimpleModule{
public:
    Scheduler();
    virtual ~Scheduler();


protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);  // to override
    virtual void finish();


};

} /* namespace omnetpptrafficgenerators */
#endif /* SCHEDULER_H_ */
