/*
 * AdmissionControl.cc
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "AdmissionControl.h"

namespace omnetpptraffichandlingsimulation {

simtime_t serviceMsg(SimplePacket *sp) {
    return (0.1 * sp->getLength());  // service time proportional to packet length
}

AdmissionControl::AdmissionControl() {
    // TODO Auto-generated constructor stub

}

AdmissionControl::~AdmissionControl() {
    // TODO Auto-generated destructor stub
}


void AdmissionControl::initialize() {
    this->msgServiced = new cMessage("msgServiced");
    packetQueue = new std::queue<SimplePacket *> ();
    isMsgServiced = false;

    maxPacketsInQueue = 20;


}

void AdmissionControl::handleMessage(cMessage *msg) {


    SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

    if (sPacket->getDST() == getIndex()) {
        EV << "Packet " << sPacket << " arrived\n";

        delete sPacket;
    }


}

void AdmissionControl::finish() {

}



} /* namespace omnetpptrafficgenerators */
