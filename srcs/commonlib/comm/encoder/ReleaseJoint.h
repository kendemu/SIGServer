/*
 * Created by okamoto on 2011-03-25
 */

#ifndef Comm_Encoder_ReleaseJoint_h
#define Comm_Encoder_ReleaseJoint_h

#include <string>

#include "Encoder.h"

namespace CommData {

class RequestReleaseJoint : public Encoder
{
	enum { BUFSIZE = 256, }; //TODO: Magic number
private:
	typedef std::string S;
private:
	S	m_agentName;
	S	m_jointName;
public:
	RequestReleaseJoint(const char *agentName, const char *jointName) :
		Encoder(COMM_REQUEST_RELEASE_JOINT, BUFSIZE),
		m_agentName(agentName), m_jointName(jointName) {}

	int 	packetNum() { return 1; }
	char *	encode(int seq, int &);
};

} // namespace

typedef CommData::RequestReleaseJoint CommRequestReleaseJointEncoder;

#endif // Comm_Encoder_ReleaseJoint_h
 

