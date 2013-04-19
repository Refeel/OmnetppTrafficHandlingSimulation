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
import omnetpptraffichandlingsimulation.Profiler;
import omnetpptraffichandlingsimulation.Scheduler;
import omnetpptraffichandlingsimulation.ExponentialPacketGenerator;
import omnetpptraffichandlingsimulation.PoissonPacketGenerator;
import omnetpptraffichandlingsimulation.OnOffPacketGenerator;
import omnetpptraffichandlingsimulation.MarkovPacketGenerator;

//import omnetpptraffichandlingsimulation.TestNetworkFullStructures;

simple AdmissionControl
{
    gates:
        input in[];
        output out[];
}

simple Profiler
{
    gates:
        input in[];
        output out[];
}

simple Scheduler
{
    gates:
        input in[];
        output out[];
}

simple ExponentialPacketGenerator
{
    parameters:
        int exponentialDelayTime;
        int packetsNumber;

    gates:
        output out[];
}

simple PoissonPacketGenerator
{
    parameters:
        int poissonDelayTime;
        int packetsNumber;

    gates:
        output out[];
}

simple OnOffPacketGenerator
{
    parameters:
        int onOffDelayTime;
        int onOffStateDurationTime;
        int packetsNumber;

    gates:
        output out[];
}

simple MarkovPacketGenerator
{
    parameters:
        int markovStateDurationTime;
        int markovMinStateDurationTime;
        int markovMaxStateDurationTime;
        int statesNum;
        int spaceBeetweenStates;

        int packetsNumber;

    gates:
        output out[];
}


//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network TestNetworkFull
{
    @display("bgb=531,302");
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }

    submodules:
        admissionControl: AdmissionControl { // TODO
            @display("p=237,146");
        }
        profiler: Profiler { // TODO
            @display("p=333,146");
        }
        scheduler: Scheduler {

            @display("p=449,146");
        }
        exponentialPacketGenerator: ExponentialPacketGenerator {
            @display("p=92,38");
        }
        poissonPacketGenerator: PoissonPacketGenerator {
            @display("p=92,107");
        }
        onOffPacketGenerator: OnOffPacketGenerator {
            @display("p=92,171");
        }
        markovPacketGenerator: MarkovPacketGenerator {

            @display("p=92,241");
        }
    connections:

        exponentialPacketGenerator.out++ --> Channel --> admissionControl.in++;
        poissonPacketGenerator.out++ --> Channel --> admissionControl.in++;
        onOffPacketGenerator.out++ --> Channel --> admissionControl.in++;
        markovPacketGenerator.out++ --> Channel --> admissionControl.in++;

        admissionControl.out++ --> Channel --> profiler.in++;
        profiler.out++ --> Channel --> scheduler.in++;




}


