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

simtime_t Scheduler::serviceMsg(SimplePacket *sp) {
    return (0.1 * sp->getLength());  // service time proportional to packet length
}


void Scheduler::initialize() {

    this->msgServiced = new cMessage("msgServiced");
    packetQueues = new std::vector<std::queue<SimplePacket *> *>();
    packetQueue = new std::queue<SimplePacket *> ();
    isMsgServiced = false;

    numOfPriorityClasses = par("numOfPriorityClasses");
    maxPacketsInQueue = par("maxPacketsInQueue");

    for(int i=0;i<numOfPriorityClasses;i++)
        packetQueues->push_back(new std::queue<SimplePacket *>());
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
