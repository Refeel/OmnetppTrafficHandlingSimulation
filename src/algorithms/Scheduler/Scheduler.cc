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
    double delay = simTime().dbl() - sp->getInTime();
    histDelay.collect(delay);
    switch(sp->getPriority())
    {
        case 0: {histDelayPriority0.collect(delay); break;}
        case 1: {histDelayPriority1.collect(delay); break;}
        case 2: {histDelayPriority2.collect(delay); break;}
        case 3: {histDelayPriority3.collect(delay); break;}
    }
    return (0.04 * sp->getLength());  // service time proportional to packet length
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


    histDelay.setName("delayHist");
    histDelay.setRangeAutoUpper(0, 1000, 2.0);
    histDelayPriority0.setName("delayHistPriority0");
    histDelayPriority0.setRangeAutoUpper(0, 1000, 2.0);
    histDelayPriority1.setName("delayHistPriority1");
    histDelayPriority1.setRangeAutoUpper(0, 1000, 2.0);
    histDelayPriority2.setName("delayHistPriority2");
    histDelayPriority2.setRangeAutoUpper(0, 1000, 2.0);
    histDelayPriority3.setName("delayHistPriority3");
    histDelayPriority3.setRangeAutoUpper(0, 1000, 2.0);
    vecRejected.setName("histRejected");

    numIncPackets = 0;
    numRejectedPackets = 0;

    for(int i=0; i< numOfPriorityClasses; i++)
    {
        numIncPacketsPriority.push_back(0);
        numRejectedPacketsPriority.push_back(0);
    }

}

void Scheduler::handleMessage(cMessage *msg) {


    SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

    if (sPacket->getDST() == getIndex()) {
        EV << "Packet " << sPacket << " arrived\n";

        delete sPacket;
    }


}

void Scheduler::finish() {
    histDelay.recordAs("packets_delay");
    histDelayPriority0.recordAs("packets_delay_priority0");
    histDelayPriority1.recordAs("packets_delay_priority1");
    histDelayPriority2.recordAs("packets_delay_priority2");
    histDelayPriority3.recordAs("packets_delay_priority3");

//    vecRejected.recordAs("rejected_packets");

    EV<<"num incomming packets: " << numIncPackets;
    EV<<"\nnum rejected packets: " << numRejectedPackets;
    EV<<"\npacket loss: " << (double)numRejectedPackets / (double)numIncPackets;
    EV<<"\nOverall packet success: " <<(double)(numIncPackets-numRejectedPackets) / 4000.0f;
    EV<<"\nOverall packet loss: " <<(double)((4000.0f - numIncPackets) + numRejectedPackets) / 4000.0f;

    for(int i=0; i<numOfPriorityClasses; i++)
    {
        EV<<"\nPriority "<<i<<":\n";
        EV<<"num incomming packets: " << numIncPacketsPriority[i];
        EV<<"\nnum rejected packets: " << numRejectedPacketsPriority[i];
        EV<<"\npacket loss: " << (double)numRejectedPacketsPriority[i] / (double)numIncPacketsPriority[i];
    }
}





} /* namespace omnetpptrafficgenerators */
