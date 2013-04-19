/*
 * Scheduler.cc
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "Scheduler.h"

namespace omnetpptraffichandlingsimulation {

Scheduler::Scheduler() {
    // TODO Auto-generated constructor stub

}

Scheduler::~Scheduler() {
    // TODO Auto-generated destructor stub
}


void Scheduler::initialize() {

}

void Scheduler::handleMessage(cMessage *msg) {


    SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

    if (sPacket->getDST() == getIndex()) {
        EV << "Packet " << sPacket << " arrived\n";

        delete sPacket;
    }


}

void Scheduler::finish() {

}



} /* namespace omnetpptrafficgenerators */
