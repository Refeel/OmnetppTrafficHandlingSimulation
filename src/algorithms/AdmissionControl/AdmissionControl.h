/*
 * AdmissionControl.h
 *
 *  Created on: 19-04-2013
 *      Author: Rafa?
 */

#ifndef ADMISSIONCONTROL_H_
#define ADMISSIONCONTROL_H_

#include <SimplePacket_m.h>
#include <omnetpp.h>
//#include <PacketPriority.h>


namespace omnetpptraffichandlingsimulation {

class AdmissionControl : public cSimpleModule{
public:
    AdmissionControl();
    virtual ~AdmissionControl();


protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);  // to override
    virtual void finish();


    cMessage *msgServiced;
    cMessage *sendMessage;
    cQueue packetQueue;
    bool isMsgServiced;
    int maxPacketsInQueue;

};

Define_Module(AdmissionControl);

} /* namespace omnetpptrafficgenerators */
#endif /* ADMISSIONCONTROL_H_ */
