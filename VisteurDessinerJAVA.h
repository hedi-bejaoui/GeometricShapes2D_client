/**
 * @file VisiteurSauvegarderFichierTXTImplementation.h
 * @brief Declaration and implementation of a concrete visitor for drawing shapes via Java.
 *
 * This file defines the concrete visitor class VisiteurDessinerJAVA, which implements the Visiteur
 * interface for drawing various geometric shapes. It uses a TCPClient to send drawing commands to a
 * Java-based drawing server at 127.0.0.1:8080.
 *
 * @note Although the file name implies "sauvegarder" (saving) functionality, the implemented methods
 * send "DRAW" commands to the server.
 */

#ifndef VISITEURSAUVEGARDERFICHIERTXTIMPLEMENTATION_H
#define VISITEURSAUVEGARDERFICHIERTXTIMPLEMENTATION_H

#include "TCPClient.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Segment.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

/**
 * @class VisiteurDessinerJAVA
 * @brief Concrete visitor for drawing shapes via a Java TCP server.
 *
 * This class implements the Visiteur interface by sending drawing commands to a Java-based drawing
 * server. Each visit method constructs a specific request string for the corresponding shape and
 * sends it over a TCP connection.
 */
class VisiteurDessinerJAVA : public Visiteur {

    /**
     * @brief Visits a Cercle object to draw it.
     * @param c The Cercle object to be drawn.
     *
     * Constructs a drawing command for a circle and sends it via TCP to the server.
     */
    void visit(const Cercle &c) const override {
        TCPClient client;
        client.connect("127.0.0.1", 8080);

        std::ostringstream request;
        request << "DRAW CIRCLE "
                << c.center.x << " "
                << c.center.y << " "
                << c.radius << " "
                << c.getColor() << "\n";
        client.send(request.str());
        client.disconnect();
    }

    /**
     * @brief Visits a Polygone object to draw it.
     * @param p The Polygone object to be drawn.
     *
     * Constructs a drawing command for a polygon, verifying that it has points before sending.
     * If the polygon has no points, a runtime_error is thrown.
     */
    void visit(const Polygone &p) const override {
        // Initialize TCP client
        TCPClient client;

        try {
            client.connect("127.0.0.1", 8080);

            // Build the request string
            std::ostringstream request;
            request << "DRAW POLYGONE";
            // Verify that the polygon has points
            if (p.getPoints().empty()) {
                throw std::runtime_error("Le polygone n'a aucun point.");
            }

            for (const auto& point : p.getPoints()) {
                request << " " << point.x << " " << point.y;
            }

            // Append the color
            request << " " <<  p.getColor() << "\n";

            // Send the request to the server
            client.send(request.str());

            // Proper disconnect
            client.disconnect();
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de l'envoi du polygone : " << e.what() << std::endl;
            client.disconnect();
        }
    }

    /**
     * @brief Visits a Triangle object to draw it.
     * @param t The Triangle object to be drawn.
     *
     * Constructs a drawing command for a triangle with its vertices and color, then sends it via TCP.
     */
    void visit(const Triangle &t) const override {
        TCPClient client;
        client.connect("127.0.0.1", 8080);

        std::ostringstream request;
        request << "DRAW TRIANGLE "
                << t.getP1().x << " " << t.getP1().y << " "
                << t.getP2().x << " " << t.getP2().y << " "
                << t.getP3().x << " " << t.getP3().y << " "
                << t.getColor() << "\n";
        client.send(request.str());

        client.disconnect();
    }

    /**
     * @brief Visits a Groupe object to draw it.
     * @param g The Groupe object to be drawn.
     *
     * For each shape in the group, the method delegates the drawing operation by invoking the
     * shape's draw method with a new instance of VisiteurDessinerJAVA.
     */
    void visit(const Groupe &g) const override {
        VisiteurDessinerJAVA monVisiteur;
        for (const auto& forme : g.getFormes()) {
            forme->draw(&monVisiteur);
        }
    }

    /**
     * @brief Visits a Segment object to draw it.
     * @param s The Segment object to be drawn.
     *
     * Constructs a drawing command for a segment with its endpoints and color, then sends it via TCP.
     */
    void visit(const Segment &s) const override {
        TCPClient client;
        client.connect("127.0.0.1", 8080);

        std::ostringstream request;
        request << "DRAW SEGMENT "
                << s.getP1().x << " " << s.getP1().y << " "
                << s.getP2().x << " " << s.getP2().y << " "
                << s.getColor() << "\n";
        client.send(request.str());

        client.disconnect();
    }
};

#endif // VISITEURSAUVEGARDERFICHIERTXTIMPLEMENTATION_H
