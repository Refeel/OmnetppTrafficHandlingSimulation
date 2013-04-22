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

#include "AdmissionControlTailDrop.h"

namespace omnetpptraffichandlingsimulation {

void AdmissionControlTailDrop::handleMessage(cMessage *msg) {

    if (msg==sendMessage)
        {
            send( msgServiced, "out" );
            if (packetQueue.empty())
            {
                msgServiced = NULL;
            }
            else
            {
                msgServiced = (cMessage *) packetQueue.pop();
                scheduleAt( simTime()+3.0, sendMessage );
            }
        }
        else if (!msgServiced)
        {

            msgServiced = msg;
            scheduleAt( simTime()+3.0, sendMessage );
        }
    else {
            int queueLength = packetQueue.length();
            if(queueLength >= maxPacketsInQueue) {
                delete(msg);
                ev << "DropTail: Delete Message" << endl;
            }
            else{
                packetQueue.insert(check_and_cast<SimplePacket *> (msg));
            }
    }

}

} /* namespace omnetpptraffichandlingsimulation */
