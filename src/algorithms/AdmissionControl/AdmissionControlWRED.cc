//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "AdmissionControlWRED.h"

namespace omnetpptraffichandlingsimulation {

void AdmissionControlWRED::handleMessage(cMessage *msg) {

    if(msg==this->msgServiced)
    {
        if(packetQueue.isEmpty())
        {
            isMsgServiced = false;
        }
        else
        {

            simtime_t serviceTime = serviceMsg(check_and_cast<SimplePacket *>(packetQueue.front()));
            packetQueue.pop();
            isMsgServiced = true;
            scheduleAt(simTime() + serviceTime, msgServiced);
        }
    }
    else if(!isMsgServiced) {
        simtime_t serviceTime = serviceMsg(check_and_cast<SimplePacket *> (msg));
        isMsgServiced = true;
        scheduleAt(simTime() + serviceTime, msgServiced);
    }
    else {
            int queueLength = packetQueue.length();
            int priority=(check_and_cast<SimplePacket *> (msg)->getPriority())+1;
            double dropProbability = ((double)intuniform(15*priority, (25*priority)-1)) / 100;

            if(dropProbability <= ((double)queueLength)/maxPacketsInQueue) {
                delete(msg);
                ev << "WRED: Delete Message" << endl;
            }
            else{
                packetQueue.insert(check_and_cast<SimplePacket *> (msg));
            }
    }

}

} /* namespace omnetpptraffichandlingsimulation */
