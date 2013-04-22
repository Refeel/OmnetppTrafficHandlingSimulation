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

}

void Profiler::forwardPacket(SimplePacket *sp) {
    send(sp, "out", 0); // for single output
}

void Profiler::handleMessage(cMessage *msg) {
    send(msg, "out", 0);
}

void Profiler::finish() {

}

} /* namespace omnetpptrafficgenerators */
