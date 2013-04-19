/*
 * SchedulerRoundRobin.h
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#ifndef SCHEDULERROUNDROBIN_H_
#define SCHEDULERROUNDROBIN_H_

#include <PacketGenerator.h>
#include <packet/SimplePacket_m.h>
#include "Scheduler.h"
#include <omnetpp.h>


namespace omnetpptraffichandlingsimulation {

class SchedulerRoundRobin : public Scheduler {
public:
    SchedulerRoundRobin();
    virtual ~SchedulerRoundRobin();
};

} /* namespace omnetpptrafficgenerators */
#endif /* SCHEDULERROUNDROBIN_H_ */
