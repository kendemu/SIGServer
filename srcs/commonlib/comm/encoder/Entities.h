/* $Id: Entities.h,v 1.1.1.1 2011-03-25 02:18:50 okamoto Exp $ */ 
#ifndef Entities_h
#define Entities_h

#include "Encoder.h"

#include <vector>

class SimObjBase;
class SimWorld;

namespace CommData {

class GetAllEnitiesRequest : public NoDataEncoder
{
public:
	GetAllEnitiesRequest() : NoDataEncoder(COMM_REQUEST_GET_ALL_ENTITIES) {;}
};

class SendEndities : public Encoder
{
private:
	enum { BUFSIZE = 1024, RESIZE = BUFSIZE, };
private:
	typedef std::vector<SimObjBase *> C;
private:
	double	m_time;
	C	m_objs;
public:
	SendEndities(CommDataType type, double t)
		: Encoder(type, BUFSIZE), m_time(t) {}

	void push(SimObjBase *p) { m_objs.push_back(p); }

	int packetNum()	{ return m_objs.size(); }
	char *encode(int seq, int &sz);
};


class GetAllEntitiesResult : public SendEndities
{
private:
	typedef SendEndities Super;
public:
	GetAllEntitiesResult(const SimWorld &w);
};

class UpdateEntitiesRequest : public SendEndities
{
public:
	UpdateEntitiesRequest(double t)
		: SendEndities(COMM_REQUEST_UPDATE_ENTITIES, t) {;}
};

} // namespace 

typedef CommData::GetAllEnitiesRequest CommRequestGetAllEntitiesEncoder;
//typedef CommData::GetAllEntitiesResult CommResultGetAllEntitiesEncoder;
typedef CommData::UpdateEntitiesRequest CommRequestUpdateEntitiesEncoder;


#endif // Entities_h
 
