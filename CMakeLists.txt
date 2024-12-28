cmake_minimum_required(VERSION 3.29)
project(GeometricShapes2D)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GeometricShapes2D
        Forme.h
        Segment.h
        Segment.cpp
        Forme.cpp
        Triangle.h
        Cercle.cpp
        Triangle.cpp
        Groupe.h
        Groupe.cpp
        Polygone.cpp
        Polygone.h
        TestGeometricShapes.cpp
        Homothetie.cpp
        Rotation.h
        Translation.h
        Translation.cpp
        Rotation.cpp
        TCPClient.h
        WinsockSingleton.h
        ShapeFactory.h)

# Link Winsock library
target_link_libraries(GeometricShapes2D PRIVATE ws2_32)