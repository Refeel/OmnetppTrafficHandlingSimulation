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
