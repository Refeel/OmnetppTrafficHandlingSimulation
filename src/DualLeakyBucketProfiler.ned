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

package omnetpptraffichandlingsimulation;

simple DualLeakyBucketProfiler extends Profiler
{
    parameters:
        int capacity1;  //capacity1 < capacity2
    	int capacity2;
    	int sendDelay1; //sendDelay1 < sendDelay2
    	int sendDelay2;
        
    @class(DualLeakyBucketProfiler);
}