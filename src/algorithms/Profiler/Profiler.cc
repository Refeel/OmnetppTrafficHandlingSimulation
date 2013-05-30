/*
 * Profiler.cc
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "Profiler.h"

namespace omnetpptraffichandlingsimulation {

Profiler::Profiler() {
    // TODO Auto-generated constructor stub

}

Profiler::~Profiler() {
    // TODO Auto-generated destructor stub
}

void Profiler::initialize() {
    hist.setName("delayStats");
    hist.setRangeAutoUpper(0,40000,2.0);
    inputHist.setName("inputStats");
    inputHist.setRangeAutoUpper(0,1000,2.0);
    outputHist.setName("outputStats");
    outputHist.setRangeAutoUpper(0,1000,2.0);
    deletedCount = 0;
    packetsSum = 0;
}

void Profiler::forwardPacket(SimplePacket *sp) {
    double delay = simTime().dbl() - timeStampQueue.front();
    timeStampQueue.pop();
    hist.collect(delay);
    outputHist.collect(simTime().dbl());
    send(sp, "out", 0); // for single output
}

void Profiler::addTimeStamp() {
    timeStampQueue.push(simTime().dbl());
}

void Profiler::handleMessage(cMessage *msg) {
    send(msg, "out", 0);
}

void Profiler::finish() {
    hist.recordAs("delays_count");
    inputHist.recordAs("input_count");
    outputHist.recordAs("output_count");
    recordScalar("deletedMessagesRate", (double)deletedCount/packetsSum);
}

} /* namespace omnetpptrafficgenerators */
