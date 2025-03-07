/**
* @file InputStreamProvider.h
 * @brief Declaration of the external input stream pointer.
 *
 * This file declares an external pointer to an std::istream, which is intended to be used as the global
 * current input stream across the application.
 */

#ifndef INPUTSTREAMPROVIDER_H
#define INPUTSTREAMPROVIDER_H

#include <istream>

/**
 * @brief Pointer to the current input stream.
 *
 * This external variable allows different parts of the program to access the same input stream.
 */
extern std::istream* currentInputStream;

#endif // INPUTSTREAMPROVIDER_H
