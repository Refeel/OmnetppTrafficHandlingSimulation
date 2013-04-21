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

#include "HTBProfiler.h"

namespace omnetpptraffichandlingsimulation {

HTBProfiler::HTBProfiler() {
    // TODO Auto-generated constructor stub

}

HTBProfiler::~HTBProfiler() {
    // TODO Auto-generated destructor stub
}

void HTBProfiler::initialize() {
    this->tokenPutDelay = par("tokenPutDelay");
    this->maxTokenNumber = par("maxTokenNumber");
    this->priorityNumber = par("priorityNumber");
    this->event = new cMessage("event");
    this->tokenCount = new int[this->priorityNumber];
    this->queue = new cPacketQueue[this->priorityNumber];

    for (int i = 0; i < this->priorityNumber; i++)
        tokenCount[i] = this->maxTokenNumber;

    scheduleAt(simTime(), event);
}

void HTBProfiler::handleMessage(cMessage *msg) {
    if (msg == event) { // received timing message
        for (int i = 0; i < this->priorityNumber; i++) {
            if (tokenCount[i] < maxTokenNumber) {
                tokenCount[i]++;
                std::string buf;
                sprintf((char*) buf.c_str(), "Token count: %d", tokenCount[i]);
                EV<< buf.c_str();
                bubble(buf.c_str());
                if (queue[i].getLength() > 0) {
                    forwardPacket(
                            check_and_cast<SimplePacket *>(queue[i].pop()));
                    tokenCount[i]--;
                }
            }
        }
        scheduleAt(simTime() + this->tokenPutDelay, event);

    }

    else { // received true packet
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast
        if (tokenCount[sPacket->getPriority()] > 0) {
            forwardPacket(sPacket);
            tokenCount[sPacket->getPriority()]--;
        } else if (checkOtherNodes(sPacket->getPriority())) {
            forwardPacket(sPacket);
        } else
            queue[sPacket->getPriority()].insert(sPacket);

    }
}

bool HTBProfiler::checkOtherNodes(int level) {
    bool isFound = false;
    for (int i = level - 1; i >= 0 && !isFound; i--) {
        if (tokenCount[i] > 0) {
            tokenCount[i]--;
            isFound = true;
        }
    }
    return isFound;
}

void HTBProfiler::finish() {

}
} /* namespace omnetpptraffichandlingsimulation */
