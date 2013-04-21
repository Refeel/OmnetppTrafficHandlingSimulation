#
# OMNeT++/OMNEST Makefile for OmnetppTrafficHandlingSimulation
#
# This file was generated with the command:
#  opp_makemake -f --deep
#

# Name of target to be created (-o option)
TARGET = OmnetppTrafficHandlingSimulation$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Ialgorithms \
    -Ialgorithms/AdmissionControl \
    -Ialgorithms/Profiler \
    -Ialgorithms/Scheduler \
    -Igenerators \
    -Ipacket

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/Txc.o \
    $O/algorithms/AdmissionControl/AdmissionControl.o \
    $O/algorithms/AdmissionControl/AdmissionControlTailDrop.o \
    $O/algorithms/Profiler/DualLeakyBucketProfiler.o \
    $O/algorithms/Profiler/HTBProfiler.o \
    $O/algorithms/Profiler/LeakyBucketProfiler.o \
    $O/algorithms/Profiler/Profiler.o \
    $O/algorithms/Profiler/TokenBucketProfiler.o \
    $O/algorithms/Scheduler/Scheduler.o \
    $O/algorithms/Scheduler/SchedulerDeficitRoundRobin.o \
    $O/algorithms/Scheduler/SchedulerFIFO.o \
    $O/algorithms/Scheduler/SchedulerRoundRobin.o \
    $O/algorithms/Scheduler/SchedulerWeightedRoundRobin.o \
    $O/generators/ExponentialPacketGenerator.o \
    $O/generators/MarkovPacketGenerator.o \
    $O/generators/OnOffPacketGenerator.o \
    $O/generators/PacketGenerator.o \
    $O/generators/PoissonPacketGenerator.o \
    $O/packet/SimplePacket_m.o

# Message files
MSGFILES = \
    packet/SimplePacket.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f OmnetppTrafficHandlingSimulation OmnetppTrafficHandlingSimulation.exe libOmnetppTrafficHandlingSimulation.so libOmnetppTrafficHandlingSimulation.a libOmnetppTrafficHandlingSimulation.dll libOmnetppTrafficHandlingSimulation.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f algorithms/*_m.cc algorithms/*_m.h
	$(Q)-rm -f algorithms/AdmissionControl/*_m.cc algorithms/AdmissionControl/*_m.h
	$(Q)-rm -f algorithms/Profiler/*_m.cc algorithms/Profiler/*_m.h
	$(Q)-rm -f algorithms/Scheduler/*_m.cc algorithms/Scheduler/*_m.h
	$(Q)-rm -f generators/*_m.cc generators/*_m.h
	$(Q)-rm -f packet/*_m.cc packet/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc algorithms/*.cc algorithms/AdmissionControl/*.cc algorithms/Profiler/*.cc algorithms/Scheduler/*.cc generators/*.cc packet/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/Txc.o: Txc.cc \
	Txc.h
$O/algorithms/AdmissionControl/AdmissionControl.o: algorithms/AdmissionControl/AdmissionControl.cc \
	algorithms/AdmissionControl/AdmissionControl.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/AdmissionControl/AdmissionControlTailDrop.o: algorithms/AdmissionControl/AdmissionControlTailDrop.cc \
	algorithms/AdmissionControl/AdmissionControl.h \
	algorithms/AdmissionControl/AdmissionControlTailDrop.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Profiler/DualLeakyBucketProfiler.o: algorithms/Profiler/DualLeakyBucketProfiler.cc \
	algorithms/Profiler/DualLeakyBucketProfiler.h \
	algorithms/Profiler/Profiler.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Profiler/HTBProfiler.o: algorithms/Profiler/HTBProfiler.cc \
	algorithms/Profiler/HTBProfiler.h \
	algorithms/Profiler/Profiler.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Profiler/LeakyBucketProfiler.o: algorithms/Profiler/LeakyBucketProfiler.cc \
	algorithms/Profiler/LeakyBucketProfiler.h \
	algorithms/Profiler/Profiler.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Profiler/Profiler.o: algorithms/Profiler/Profiler.cc \
	algorithms/Profiler/Profiler.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Profiler/TokenBucketProfiler.o: algorithms/Profiler/TokenBucketProfiler.cc \
	algorithms/Profiler/Profiler.h \
	algorithms/Profiler/TokenBucketProfiler.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Scheduler/Scheduler.o: algorithms/Scheduler/Scheduler.cc \
	algorithms/Scheduler/Scheduler.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Scheduler/SchedulerDeficitRoundRobin.o: algorithms/Scheduler/SchedulerDeficitRoundRobin.cc \
	algorithms/Scheduler/Scheduler.h \
	algorithms/Scheduler/SchedulerDeficitRoundRobin.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Scheduler/SchedulerFIFO.o: algorithms/Scheduler/SchedulerFIFO.cc \
	algorithms/Scheduler/Scheduler.h \
	algorithms/Scheduler/SchedulerFIFO.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Scheduler/SchedulerRoundRobin.o: algorithms/Scheduler/SchedulerRoundRobin.cc \
	algorithms/Scheduler/Scheduler.h \
	algorithms/Scheduler/SchedulerRoundRobin.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/algorithms/Scheduler/SchedulerWeightedRoundRobin.o: algorithms/Scheduler/SchedulerWeightedRoundRobin.cc \
	algorithms/Scheduler/Scheduler.h \
	algorithms/Scheduler/SchedulerWeightedRoundRobin.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/generators/ExponentialPacketGenerator.o: generators/ExponentialPacketGenerator.cc \
	generators/ExponentialPacketGenerator.h \
	generators/PacketGenerator.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/generators/MarkovPacketGenerator.o: generators/MarkovPacketGenerator.cc \
	generators/MarkovPacketGenerator.h \
	generators/PacketGenerator.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/generators/OnOffPacketGenerator.o: generators/OnOffPacketGenerator.cc \
	generators/OnOffPacketGenerator.h \
	generators/PacketGenerator.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/generators/PacketGenerator.o: generators/PacketGenerator.cc \
	generators/PacketGenerator.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/generators/PoissonPacketGenerator.o: generators/PoissonPacketGenerator.cc \
	generators/PacketGenerator.h \
	generators/PoissonPacketGenerator.h \
	packet/PacketPriority.h \
	packet/SimplePacket_m.h
$O/packet/SimplePacket_m.o: packet/SimplePacket_m.cc \
	packet/SimplePacket_m.h

