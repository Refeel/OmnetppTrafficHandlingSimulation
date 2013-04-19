/*
 * SchedulerRoundRobin.cpp
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "SchedulerRoundRobin.h"

namespace omnetpptraffichandlingsimulation {

SchedulerRoundRobin::SchedulerRoundRobin() {
    // TODO Auto-generated constructor stub

}

SchedulerRoundRobin::~SchedulerRoundRobin() {
    // TODO Auto-generated destructor stub
}

void SchedulerRoundRobin::initialize() {

    packetQueues = new std::vector<std::queue<SimplePacket> >();

}

void SchedulerRoundRobin::handleMessage(cMessage *msg) {


    SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

    if (sPacket->getDST() == getIndex()) {
        EV << "Packet " << sPacket << " arrived\n";

        delete sPacket;
    }


}

void SchedulerRoundRobin::finish() {

}

} /* namespace omnetpptrafficgenerators */
