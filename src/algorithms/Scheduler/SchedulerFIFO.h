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

#ifndef SCHEDULERFIFO_H_
#define SCHEDULERFIFO_H_

#include "Scheduler.h"

namespace omnetpptraffichandlingsimulation {

class SchedulerFIFO : public Scheduler{
public:
    SchedulerFIFO();
    virtual ~SchedulerFIFO();

protected:
    virtual void handleMessage(cMessage *msg);  // to override
    virtual void finish();
};

} /* namespace omnetpptraffichandlingsimulation */
#endif /* SCHEDULERFIFO_H_ */
