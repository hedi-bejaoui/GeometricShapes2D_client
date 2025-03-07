/**
 * @file WinsockSingleton.cpp
 * @brief Singleton class to manage Winsock initialization and cleanup.
 *
 * This file defines the WinsockSingleton class that ensures the Winsock library is
 * initialized exactly once using the Singleton design pattern. The constructor initializes
 * Winsock with WSAStartup, and the destructor cleans up with WSACleanup.
 */

#include <winsock2.h>
#include <stdexcept>

/**
 * @class WinsockSingleton
 * @brief Manages the initialization and cleanup of the Winsock library.
 *
 * This class implements the Singleton design pattern to guarantee that the Winsock library
 * is initialized only once during the application lifetime. The private constructor
 * initializes Winsock, while the destructor performs cleanup.
 */
class WinsockSingleton {
    /**
     * @brief Private constructor that initializes the Winsock library.
     *
     * Calls WSAStartup with version 2.2 and throws a runtime_error if the initialization fails.
     */
    WinsockSingleton() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("Winsock initialization failed.");
        }
    }

    /**
     * @brief Private destructor that cleans up the Winsock library.
     *
     * Calls WSACleanup to free resources allocated by WSAStartup.
     */
    ~WinsockSingleton() {
        WSACleanup();
    }

public:
    /**
     * @brief Retrieves the singleton instance of WinsockSingleton.
     *
     * This method returns a reference to the single instance of WinsockSingleton.
     * The instance is created on the first call and is reused on subsequent calls.
     * @return Reference to the WinsockSingleton instance.
     */
    static WinsockSingleton& getInstance() {
        static WinsockSingleton instance;
        return instance;
    }

    // Delete copy constructor and assignment operator to enforce singleton behavior
    WinsockSingleton(const WinsockSingleton&) = delete;             /**< Deleted copy constructor. */
    WinsockSingleton& operator=(const WinsockSingleton&) = delete;  /**< Deleted assignment operator. */
};
