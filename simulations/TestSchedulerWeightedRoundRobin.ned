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

package omnetpptraffichandlingsimulation.simulations;

import omnetpptraffichandlingsimulation.AdmissionControl;
import omnetpptraffichandlingsimulation.AdmissionControlTailDrop;
import omnetpptraffichandlingsimulation.AdmissionControlFrontDrop;
import omnetpptraffichandlingsimulation.AdmissionControlRandomDrop;
import omnetpptraffichandlingsimulation.AdmissionControlRED;
import omnetpptraffichandlingsimulation.AdmissionControlWRED;
//TODO

import omnetpptraffichandlingsimulation.Profiler;
import omnetpptraffichandlingsimulation.LeakyBucketProfiler;
import omnetpptraffichandlingsimulation.DualLeakyBucketProfiler;
import omnetpptraffichandlingsimulation.TokenBucketProfiler;
import omnetpptraffichandlingsimulation.HTBProfiler;

import omnetpptraffichandlingsimulation.Scheduler;
import omnetpptraffichandlingsimulation.SchedulerFIFO;
import omnetpptraffichandlingsimulation.SchedulerRoundRobin;
import omnetpptraffichandlingsimulation.SchedulerWeightedRoundRobin;
import omnetpptraffichandlingsimulation.SchedulerDeficitRoundRobin;

import omnetpptraffichandlingsimulation.PacketGenerator;
import omnetpptraffichandlingsimulation.ExponentialPacketGenerator;
import omnetpptraffichandlingsimulation.PoissonPacketGenerator;
import omnetpptraffichandlingsimulation.OnOffPacketGenerator;
import omnetpptraffichandlingsimulation.MarkovPacketGenerator;


network TestSchedulerWeightedRoundRobin
{
    @display("bgb=531,302");
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }

    submodules:
        scheduler: SchedulerWeightedRoundRobin { // CHOOSE IMPLEMENTATION OF SCHEDULER
            @display("p=333,146");
        }

        markovPacketGenerator1: MarkovPacketGenerator {
            @display("p=92,38");
        }
        markovPacketGenerator2: MarkovPacketGenerator {
            @display("p=92,107");
        }
        markovPacketGenerator3: MarkovPacketGenerator {
            @display("p=92,171");
        }
        markovPacketGenerator4: MarkovPacketGenerator {

            @display("p=92,241");
        }
        
        
    connections:

        markovPacketGenerator1.out++ --> Channel --> scheduler.in++;
        markovPacketGenerator2.out++ --> Channel --> scheduler.in++;
        markovPacketGenerator3.out++ --> Channel --> scheduler.in++;
        markovPacketGenerator4.out++ --> Channel --> scheduler.in++;

}