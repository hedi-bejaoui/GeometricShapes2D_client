/**
 * @file TCPClient.cpp
 * @brief Implementation of a simple TCP client using Winsock.
 *
 * This file defines the TCPClient class which provides functionalities to connect to a server,
 * send messages, and disconnect. It utilizes the WinsockSingleton to ensure that the Winsock library
 * is initialized only once.
 */

#include "WinsockSingleton.h"
#include <iostream>
#include <string>
#include <winsock2.h>

/**
 * @class TCPClient
 * @brief A simple TCP client for establishing a connection, sending data, and disconnecting.
 *
 * The TCPClient class encapsulates the creation and management of a TCP socket.
 * It provides methods for connecting to a server, sending messages, and disconnecting.
 * Winsock is ensured to be initialized by calling the WinsockSingleton.
 */
class TCPClient {
    SOCKET sock; /**< The TCP socket used for communication. */

public:
    /**
     * @brief Constructs a TCPClient and initializes Winsock.
     *
     * The constructor initializes the socket to an invalid state and ensures that the
     * Winsock library is properly initialized by invoking the WinsockSingleton.
     */
    TCPClient() : sock(INVALID_SOCKET) {
        WinsockSingleton::getInstance(); // Ensure Winsock is initialized
    }

    /**
     * @brief Connects to the specified server.
     * @param address The IP address of the server.
     * @param port The port number to connect to.
     * @throws std::runtime_error if socket creation or connection fails.
     *
     * This method creates a TCP socket, sets up the server address, and attempts to establish a connection.
     */
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

    /**
     * @brief Sends a message to the connected server.
     * @param message The message to send.
     * @throws std::runtime_error if sending the message fails.
     *
     * This method sends the provided message over the TCP connection to the server.
     */
    void send(const std::string& message) {
        if (::send(sock, message.c_str(), message.size(), 0) == SOCKET_ERROR) {
            throw std::runtime_error("Send failed.");
        }
    }

    /**
     * @brief Disconnects the TCP client by closing the socket.
     */
    void disconnect() {
        closesocket(sock);
    }

    /**
     * @brief Destructor that ensures the socket is closed.
     *
     * If the socket is still valid when the TCPClient object is destroyed, it will automatically disconnect.
     */
    ~TCPClient() {
        if (sock != INVALID_SOCKET) {
            disconnect();
        }
    }
};
