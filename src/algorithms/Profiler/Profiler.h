/*
 * Profiler.h
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#ifndef PROFILER_H_
#define PROFILER_H_

#include <SimplePacket_m.h>
#include <omnetpp.h>
#include <PacketPriority.h>


namespace omnetpptraffichandlingsimulation {

class Profiler : public cSimpleModule{
public:
    Profiler();
    virtual ~Profiler();
    void forwardPacket(SimplePacket *sp);


protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);  // to override
    virtual void finish();


};

Define_Module(Profiler);

} /* namespace omnetpptrafficgenerators */
#endif /* PROFILER_H_ */
