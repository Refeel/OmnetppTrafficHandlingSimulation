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

#ifndef HTBPROFILER_H_
#define HTBPROFILER_H_

#include "Profiler.h"
#include <omnetpp.h>


namespace omnetpptraffichandlingsimulation {

class HTBProfiler : public Profiler  {
public:
    HTBProfiler();
    virtual ~HTBProfiler();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();


private:
    cMessage *event; // pointer to the event object which we'll use for timing
    int *tokenCount;  //token count per class/priority
//    cPacketQueue *queue;   //packets queue per class/priority

    //PARAMS:
    int tokenPutDelay;
    int maxTokenNumber;
    int priorityNumber;

    bool checkOtherNodes(int level);

};

Define_Module(HTBProfiler);

} /* namespace omnetpptraffichandlingsimulation */
#endif /* HTBPROFILER_H_ */
