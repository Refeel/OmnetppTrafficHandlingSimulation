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

#include "TokenBucketProfiler.h"

namespace omnetpptraffichandlingsimulation {

TokenBucketProfiler::TokenBucketProfiler() {
    // TODO Auto-generated constructor stub

}

TokenBucketProfiler::~TokenBucketProfiler() {
    // TODO Auto-generated destructor stub
}

void TokenBucketProfiler::initialize() {
    this->tokenPutDelay = par("tokenPutDelay");
    this->maxTokenNumber = par("maxTokenNumber");
    this->event = new cMessage("event");
    tokenCount = maxTokenNumber;

    scheduleAt(simTime(), event);
}

void TokenBucketProfiler::handleMessage(cMessage *msg) {
    if (msg == event) { // received timing message
        if (tokenCount < maxTokenNumber) {
            tokenCount++;
            std::string buf;
            sprintf((char*) buf.c_str(), "Token count: %d", tokenCount);
            EV << buf.c_str();
            bubble(buf.c_str());
            if(queue.getLength() > 0) {
                forwardPacket(check_and_cast<SimplePacket *>(queue.pop()));
                tokenCount--;
            }
        }
        scheduleAt(simTime() + this->tokenPutDelay, event);

    }

    else { // received true packet
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast
        if(tokenCount > 0) {
            forwardPacket(sPacket);
            tokenCount--;
        }
        else
            queue.insert(sPacket);

    }
}

void TokenBucketProfiler::finish() {

}

} /* namespace omnetpptraffichandlingsimulation */
