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

#include "LeakyBucketProfiler.h"
#include <SimplePacket_m.h>

namespace omnetpptraffichandlingsimulation {

LeakyBucketProfiler::LeakyBucketProfiler() {
    // TODO Auto-generated constructor stub

}

LeakyBucketProfiler::~LeakyBucketProfiler() {
    // TODO Auto-generated destructor stub
}

void LeakyBucketProfiler::initialize() {
    this->capacity = par("capacity");
    this->sendDelay = par("sendDelay");
    this->event = new cMessage("event");

    scheduleAt(simTime(), event);
}

void LeakyBucketProfiler::handleMessage(cMessage *msg) {
    if (msg == event) { // received timing message
        if (queue.getLength() > 0)
            forwardPacket(check_and_cast<SimplePacket *>(queue.pop()));

        scheduleAt(simTime() + this->sendDelay, event);

    }

    else { // received true packet
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast
        if (queue.getLength() < this->capacity) {
            queue.insert(sPacket);
        } else {
            delete sPacket;
            std::string buf;
            sprintf((char*) buf.c_str(), "Packet deleted");
            EV<< buf.c_str();
            bubble(buf.c_str());
        }
    }
}

void LeakyBucketProfiler::finish() {

}

} /* namespace omnetpptraffichandlingsimulation */
