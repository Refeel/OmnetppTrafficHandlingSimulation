/*
 * AdmissionControl.cc
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "AdmissionControl.h"

namespace omnetpptraffichandlingsimulation {


simtime_t AdmissionControl::serviceMsg(SimplePacket *sp) {
    return (0.01 * sp->getLength());  // service time proportional to packet length
}

AdmissionControl::AdmissionControl() {
    // TODO Auto-generated constructor stub

}

AdmissionControl::~AdmissionControl() {
    // TODO Auto-generated destructor stub
}


void AdmissionControl::initialize() {
    this->sendMessage = new cMessage("msgSended");
    this->msgServiced = new cMessage("msgServiced");
    packetQueue.setName("queue");
    isMsgServiced=false;
    maxPacketsInQueue = 20;


}

void AdmissionControl::handleMessage(cMessage *msg) {
    send(msg, "out", 0);
}

void AdmissionControl::finish() {

}



} /* namespace omnetpptrafficgenerators */
