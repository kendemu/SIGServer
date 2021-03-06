/*
 * Created by Okamoto on 2011-03-25
 */

#ifndef CTReader_h
#define CTReader_h

#include "systemdef.h"
#include "Source.h"
#include "CommDataDecoder.h"


class CTReader
{
public:
	class ConnectionClosedException {};
	enum ControllerDataType{
	  SEND_MESSAGE = 0x0001,
	  START_SIM    = 0x0002,
	  STOP_SIM     = 0x0003,
	};
private:
	class Buffer
	{
	private:
		char *	m_buf[2];
		int	m_bufsize;
		char *	m_readHead;
		int	m_curr;
	public:
		Buffer(int size);
		~Buffer();

		char * 	data() { return m_buf[m_curr]; }
		int	datasize() { return m_readHead - data(); }

		int 	read(SOCKET s);
		int 	read(SOCKET s, int bytes);
		void 	setDecodedByte(int decoded);
	};

	typedef CommDataDecoder::Result Result;
private:
	SOCKET m_sock;
	Source m_source;
	CommDataDecoder &m_decoder;
	Buffer *	m_buf;

public:
	CTReader(SOCKET s, CommDataDecoder &d, int bufsize);
	~CTReader();

	bool 		read();

	bool   recvData(SOCKET sock, char* msg, int size);

	Result *	readSync();
};

#endif // CTReader_h
 

