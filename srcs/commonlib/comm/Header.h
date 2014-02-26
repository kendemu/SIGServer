/* $Id: Header.h,v 1.1.1.1 2011-03-25 02:18:50 okamoto Exp $ */ 
#ifndef CommDataHeader_h
#define CommDataHeader_h

#include <string>

#include "CommDataType.h"

struct CommDataHeader
{
	unsigned short packetSize;
	CommDataType type;
	unsigned short packetNum;
	unsigned short seq;
	unsigned short forwardFlags;
	std::string    forwardTo;
	double	       forwardReachRadius;
};

namespace CommData {
	int  getHeader(char *data, int n, CommDataHeader &h);
	bool isPacketEnd(char *);
}


#endif // CommDataHeader_h
 
