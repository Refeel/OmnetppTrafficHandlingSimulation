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

void Profiler::handleMessage(cMessage *msg) {


    SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

    if (sPacket->getDST() == getIndex()) {
        EV << "Packet " << sPacket << " arrived\n";

        delete sPacket;
    }


}

void Profiler::finish() {

}



} /* namespace omnetpptrafficgenerators */
