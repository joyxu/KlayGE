// Socket.hpp
// KlayGE 套接字 头文件
// Ver 1.4.8.4
// 版权所有(C) 龚敏敏, 2003
// Homepage: http://klayge.sourceforge.net
//
// 1.4.8.3
// 增加了同步Socket (2003.3.8)
//
// 1.4.8.1
// 初次建立 (2003.1.23)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef	_SOCKET_HPP
#define	_SOCKET_HPP

#ifndef KLAYGE_CORE_SOURCE
#define KLAYGE_LIB_NAME KlayGE_Core
#include <KlayGE/config/auto_link.hpp>
#endif

#include <string>

#if defined KLAYGE_PLATFORM_WINDOWS
	#ifndef _WINSOCKAPI_
	#include <winsock.h>
	#endif
	typedef int socklen_t;
#elif defined KLAYGE_PLATFORM_LINUX
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <sys/ioctl.h>
	#include <netdb.h>
	typedef sockaddr SOCKADDR;
	typedef sockaddr_in SOCKADDR_IN;
	typedef in_addr IN_ADDR;
	typedef int SOCKET;
#endif

namespace KlayGE
{
	KLAYGE_CORE_API SOCKADDR_IN TransAddr(std::string const & address, uint16_t port);
	KLAYGE_CORE_API std::string TransAddr(SOCKADDR_IN const & sockAddr, uint16_t& port);
	KLAYGE_CORE_API IN_ADDR Host();

	// 同步套接字
	///////////////////////////////////////////////////////////////////////////////
	class KLAYGE_CORE_API Socket
	{
	public:
		Socket();
		~Socket();

		void Create(int socketType = SOCK_STREAM, int protocolType = 0, int addressFormat = PF_INET);
		void Close();

		void Accept(Socket& connectedSocket);
		void Accept(Socket& connectedSocket, SOCKADDR_IN& sockAddr);
		void Bind(SOCKADDR_IN const & sockAddr);

		void Connect(SOCKADDR_IN const & sockAddr);

		void IOCtl(long command, uint32_t* argument);
		void Listen(int connectionBacklog = 5);

		int Receive(void* buf, int len, int flags = 0);
		int Send(void const * buf, int len, int flags = 0);

		int ReceiveFrom(void* buf, int len, SOCKADDR_IN& sockFrom, int flags = 0);
		int SendTo(void const * buf, int len, SOCKADDR_IN const & sockTo, int flags = 0);

		enum ShutDownMode
		{
			SDM_Receives = 0,
			SDM_Sends = 1,
			SDM_Both = 2,
		};
		void ShutDown(ShutDownMode how = SDM_Sends);

		void PeerName(SOCKADDR_IN& sockAddr, socklen_t& len);
		void SockName(SOCKADDR_IN& sockAddr, socklen_t& len);

		void SetSockOpt(int optionName, void const * optionValue,
			socklen_t optionLen, int level = SOL_SOCKET);
		void GetSockOpt(int optionName, void* optionValue,
			socklen_t& optionLen, int level = SOL_SOCKET);

		void NonBlock(bool nonBlock)
		{
			uint32_t on(nonBlock);
			this->IOCtl(FIONBIO, &on);
		}

		void TimeOut(uint32_t microSecs);
		uint32_t TimeOut();

	private:
		SOCKET		socket_;
	};
}

#endif			// _SOCKET_HPP
