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

#ifndef SCHEDULERWEIGHTEDROUNDROBIN_H_
#define SCHEDULERWEIGHTEDROUNDROBIN_H_

#include "Scheduler.h"
#include <algorithm>

namespace omnetpptraffichandlingsimulation {

class SchedulerWeightedRoundRobin : public Scheduler {
public:
    SchedulerWeightedRoundRobin();
    virtual ~SchedulerWeightedRoundRobin();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);  // to override

private:
    int cycle=0;
    std::vector<double> weights;
    std::vector<double> meanPacketLens;

};

Define_Module(SchedulerWeightedRoundRobin);

} /* namespace omnetpptraffichandlingsimulation */
#endif /* SCHEDULERWEIGHTEDROUNDROBIN_H_ */
