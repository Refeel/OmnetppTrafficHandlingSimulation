//
// Generated file, do not edit! Created by opp_msgc 4.3 from packet/SimplePacket.msg.
//

#ifndef _SIMPLEPACKET_M_H_
#define _SIMPLEPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0403
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif


namespace omnetpptraffichandlingsimulation {

/**
 * Class generated from <tt>packet/SimplePacket.msg</tt> by opp_msgc.
 * <pre>
 * packet SimplePacket
 * {
 *      int DST;
 *      int SRC;
 *      int sessionId;
 *      int packetId;
 *      int priority;
 *      int length;
 *      string payload; 
 *      
 *      double inTime;
 * };
 * </pre>
 */
class SimplePacket : public ::cPacket
{
  protected:
    int DST_var;
    int SRC_var;
    int sessionId_var;
    int packetId_var;
    int priority_var;
    int length_var;
    opp_string payload_var;
    double inTime_var;

  private:
    void copy(const SimplePacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SimplePacket&);

  public:
    SimplePacket(const char *name=NULL, int kind=0);
    SimplePacket(const SimplePacket& other);
    virtual ~SimplePacket();
    SimplePacket& operator=(const SimplePacket& other);
    virtual SimplePacket *dup() const {return new SimplePacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getDST() const;
    virtual void setDST(int DST);
    virtual int getSRC() const;
    virtual void setSRC(int SRC);
    virtual int getSessionId() const;
    virtual void setSessionId(int sessionId);
    virtual int getPacketId() const;
    virtual void setPacketId(int packetId);
    virtual int getPriority() const;
    virtual void setPriority(int priority);
    virtual int getLength() const;
    virtual void setLength(int length);
    virtual const char * getPayload() const;
    virtual void setPayload(const char * payload);
    virtual double getInTime() const;
    virtual void setInTime(double inTime);
};

inline void doPacking(cCommBuffer *b, SimplePacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SimplePacket& obj) {obj.parsimUnpack(b);}

}; // end namespace omnetpptraffichandlingsimulation

#endif // _SIMPLEPACKET_M_H_
