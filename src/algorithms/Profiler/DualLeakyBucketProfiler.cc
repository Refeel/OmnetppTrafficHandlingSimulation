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

#include "DualLeakyBucketProfiler.h"

namespace omnetpptraffichandlingsimulation {

DualLeakyBucketProfiler::DualLeakyBucketProfiler() {
    // TODO Auto-generated constructor stub

}

DualLeakyBucketProfiler::~DualLeakyBucketProfiler() {
    // TODO Auto-generated destructor stub
}

void DualLeakyBucketProfiler::initialize() {
    this->capacity1 = par("capacity1");
    this->capacity2 = par("capacity2");
    this->sendDelay1 = par("sendDelay1");
    this->sendDelay2 = par("sendDelay2");
    this->event1 = new cMessage("event1");
    this->event2 = new cMessage("event2");

    scheduleAt(simTime(), event1);
    scheduleAt(simTime(), event2);
}

void DualLeakyBucketProfiler::handleMessage(cMessage *msg) {
    if (msg == event1) { // received timing message for bucket 1
        if (queue1.getLength() > 0) {
            SimplePacket *packet = check_and_cast<SimplePacket *>(queue1.pop());
            std::string buf;
            sprintf((char*) buf.c_str(), "Packet deleted from queue 1");
            EV<< buf.c_str();
            bubble(buf.c_str());
            if (queue2.getLength() < capacity2)
                queue2.insert(packet);
            else {
                delete packet;
                std::string buf;
                sprintf((char*) buf.c_str(), "Packet deleted");
                EV<< buf.c_str();
                bubble(buf.c_str());
            }
        }
        scheduleAt(simTime() + this->sendDelay1, event1);

    } else if (msg == event2) { // received timing message for bucket 2
        if (queue2.getLength() > 0)
            forwardPacket(check_and_cast<SimplePacket *>(queue2.pop()));

        scheduleAt(simTime() + this->sendDelay2, event2);

    } else { // received true packet
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast
        if (queue1.getLength() < this->capacity1) {
            queue1.insert(sPacket);
            std::string buf;
            sprintf((char*) buf.c_str(), "Packet added to queue 1");
            EV<< buf.c_str();
            bubble(buf.c_str());
        } else {
            delete sPacket;
            std::string buf;
            sprintf((char*) buf.c_str(), "Packet deleted");
            EV<< buf.c_str();
            bubble(buf.c_str());
        }
    }
}

void DualLeakyBucketProfiler::finish() {

}

} /* namespace omnetpptraffichandlingsimulation */
