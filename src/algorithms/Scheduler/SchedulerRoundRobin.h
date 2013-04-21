/*
 * SchedulerRoundRobin.h
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#ifndef SCHEDULERROUNDROBIN_H_
#define SCHEDULERROUNDROBIN_H_

#include "Scheduler.h"

namespace omnetpptraffichandlingsimulation {

class SchedulerRoundRobin : public Scheduler {
public:
    SchedulerRoundRobin();
    virtual ~SchedulerRoundRobin();


protected:
    virtual void handleMessage(cMessage *msg);  // to override
    virtual void finish();


private:
    int cycle=0;

};

Define_Module(SchedulerRoundRobin);

} /* namespace omnetpptrafficgenerators */
#endif /* SCHEDULERROUNDROBIN_H_ */
