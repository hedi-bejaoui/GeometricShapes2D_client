//
// Created by bejaoui on 12/28/2024.
//

#include <winsock2.h>

class WinsockSingleton {
    WinsockSingleton() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("Winsock initialization failed.");
        }
    }

    ~WinsockSingleton() {
        WSACleanup();
    }

public:
    static WinsockSingleton& getInstance() {
        static WinsockSingleton instance;
        return instance;
    }

    WinsockSingleton(const WinsockSingleton&) = delete;
    WinsockSingleton& operator=(const WinsockSingleton&) = delete;
};
