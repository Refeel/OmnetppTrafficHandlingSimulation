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

#ifndef DUALLEAKYBUCKETPROFILER_H_
#define DUALLEAKYBUCKETPROFILER_H_

#include "Profiler.h"
#include <omnetpp.h>

namespace omnetpptraffichandlingsimulation{

class DualLeakyBucketProfiler : public Profiler  {
public:
    DualLeakyBucketProfiler();
    virtual ~DualLeakyBucketProfiler();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

private:
    cPacketQueue queue1;
    cPacketQueue queue2;

    cMessage *event1; // pointer to the event object which we'll use for timing for bucket1
    cMessage *event2; // pointer to the event object which we'll use for timing for bucket2

    //PARAMS:
    int capacity1;  //capacity1 < capacity2
    int capacity2;
    int sendDelay1; //sendDelay1 < sendDelay2
    int sendDelay2;
};

Define_Module(DualLeakyBucketProfiler);

} /* namespace omnetpptraffichandlingsimulation */
#endif /* DUALLEAKYBUCKETPROFILER_H_ */
