//
// Created by bejaoui on 12/28/2024.
//

#include "WinsockSingleton.h"
#include <iostream>
#include <string>
#include <winsock2.h>

class TCPClient {
    SOCKET sock;

public:
    TCPClient() : sock(INVALID_SOCKET) {
        WinsockSingleton::getInstance(); // Ensure Winsock is initialized
    }

    void connect(const std::string& address, int port) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET) {
            throw std::runtime_error("Socket creation failed.");
        }

        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = inet_addr(address.c_str());

        if (::connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            throw std::runtime_error("Connection failed.");
        }
    }

    void send(const std::string& message) {
        if (::send(sock, message.c_str(), message.size(), 0) == SOCKET_ERROR) {
            throw std::runtime_error("Send failed.");
        }
    }

    void disconnect() {
        closesocket(sock);
    }

    ~TCPClient() {
        if (sock != INVALID_SOCKET) {
            disconnect();
        }
    }
};
