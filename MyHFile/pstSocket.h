#ifndef __WINSOCK2_H__
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#endif // !WINSOCK2_H

#ifndef __STDLIB_H__
#include <stdlib.h>
#endif // !STDLIB_H

#pragma once

class UdpClient
{
public:
	UdpClient(const char* serverIp, int serverPort);
	~UdpClient();

	void sendMsg(char* msg, int length) {
		sendto(sockClient, msg, length, 0, (SOCKADDR*)& servAddr, servAddr_length);
	}

	void recvMsg(char* msg, int length) {
		recvfrom(sockClient, msg, length, 0, (SOCKADDR*)& servAddr, &servAddr_length);
	}

private:
	SOCKADDR_IN servAddr;
	int servAddr_length;
	SOCKET sockClient;
};

UdpClient::UdpClient(const char* serverIp, int serverPort)
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(1, 1), &wsd);

	sockClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.S_un.S_addr = inet_addr(serverIp);
	servAddr.sin_port = htons(serverPort);

	servAddr_length = sizeof(servAddr);
}

UdpClient::~UdpClient()
{
	closesocket(sockClient);
	WSACleanup();
}

class UdpServer {
public:
	UdpServer(int listenPort) {
		// init
		WSADATA wsd;
		if (0 != WSAStartup(MAKEWORD(1, 1), &wsd)) {
			success = false;
		}
		success = true;
		sockServ = socket(AF_INET, SOCK_DGRAM, 0);

		sockAddrIn_length = sizeof(servAddr);

		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		servAddr.sin_port = htons(listenPort);

		bind(sockServ, (SOCKADDR*) &servAddr, sockAddrIn_length);
	}
	~UdpServer() {
		closesocket(sockServ);
		WSACleanup();
	}

	SOCKADDR_IN& recvMsg(char* msg, int length) {
		SOCKADDR_IN *clientAddr = (SOCKADDR_IN*)malloc(sizeof(SOCKADDR_IN));
		recvfrom(sockServ, msg, length, 0, (SOCKADDR*)clientAddr, &sockAddrIn_length);
		return *clientAddr;
	}

	void sendMsg(char* msg, int length, SOCKADDR_IN clientAddr) {
		sendto(sockServ, msg, length, 0, (SOCKADDR*) &clientAddr, sockAddrIn_length);
	}
	
	bool ready() {
		return success;
	}

private:
	SOCKADDR_IN servAddr;
	int sockAddrIn_length;
	SOCKET sockServ;
	bool success;
};