/*
 * AdmissionControl.cc
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#include "AdmissionControl.h"

namespace omnetpptraffichandlingsimulation {



AdmissionControl::AdmissionControl() {
    // TODO Auto-generated constructor stub

}

AdmissionControl::~AdmissionControl() {
    // TODO Auto-generated destructor stub
}


void AdmissionControl::initialize() {
    this->msgServiced = new cMessage("msgServiced");
    this->sendMessage = new cMessage("msgSended");
    packetQueue.setName("queue");
    isMsgServiced = false;

    maxPacketsInQueue = 20;


}

void AdmissionControl::handleMessage(cMessage *msg) {
    send(msg, "out", 0);
}

void AdmissionControl::finish() {

}



} /* namespace omnetpptrafficgenerators */
