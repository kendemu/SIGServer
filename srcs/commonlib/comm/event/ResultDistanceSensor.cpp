/* $Id: ResultDistanceSensor.cpp,v 1.12 2011-09-26 05:30:54 okamoto Exp $ */ 
#include "ResultDistanceSensor.h"
#include "CommDataType.h"
#include "binary.h"
#include "SimObj.h"

#define FREE(P) if (P) { delete P; P = 0; }

bool ResultDistanceSensorEvent::set(int packetNum, int seq, char *data, int n)
{
	char *p = data;

	unsigned char dis = BINARY_GET_DATA_S_INCR(p, short);
	m_distance = dis;
	return true;
}

void ResultDistanceSensorEvent::free_()
{
  //FREE(m_distance);
}

