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

    if (msg==sendMessage)
        {

            if (packetQueue.getLength() > 0)
                send(check_and_cast<SimplePacket *>(packetQueue.pop()), "out", 0);
                EV<<"Current AdmissionControl size: " << packetQueue.length();
                scheduleAt(simTime() + 10, sendMessage);

        }
    else {
            int queueLength = packetQueue.length();
            int priority=(check_and_cast<SimplePacket *> (msg)->getPriority())+1;
            double dropProbability = ((double)intuniform(15*priority, (25*priority))) / 100;

            if(dropProbability <= ((double)queueLength)/maxPacketsInQueue) {
                delete(msg);
                ev << "WRED: Delete Message" << endl;
                EV<<"Probability: " << dropProbability;
                EV<<" Current AdmissionControl size: " << packetQueue.length();
            }
            else{
                packetQueue.insert(check_and_cast<SimplePacket *> (msg));
                EV<<"Current AdmissionControl size: " << packetQueue.length();
            }
    }

}

} /* namespace omnetpptraffichandlingsimulation */
