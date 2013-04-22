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

    virtual simtime_t serviceMsg(SimplePacket *sp);

    cMessage *sendMessage;
    cMessage *msgServiced;
    cQueue packetQueue;
    int maxPacketsInQueue;
    bool isMsgServiced;

};

Define_Module(AdmissionControl);

} /* namespace omnetpptrafficgenerators */
#endif /* ADMISSIONCONTROL_H_ */
