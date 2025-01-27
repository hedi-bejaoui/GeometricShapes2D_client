//
// Created by geffe on 27/01/2025.
//

#ifndef VISITEURSAUVEGARDERFICHIERTXTIMPLEMENTATION_H
#define VISITEURSAUVEGARDERFICHIERTXTIMPLEMENTATION_H
#include "TCPClient.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Segment.h"


class VisiteurDessinerJAVA : public Visiteur{

    void visit(const Cercle &c) const override{
        TCPClient client;
        client.connect("127.0.0.1", 8080);

        std::ostringstream request;
        request << "DRAW CIRCLE " << c.center.x << " " << c.center.y << " " << c.radius << " " << c.center.color << "\n";
        client.send(request.str());

        client.disconnect();
    }


    void visit(const Polygone &p) const override {
        // Initialisation du client TCP
        TCPClient client;

        try {
            client.connect("127.0.0.1", 8080);

            // Construction de la requête
            std::ostringstream request;
            request << "DRAW POLYGONE";
            // Vérification que le polygone a des points
            if (p.getPoints().empty()) {
                throw std::runtime_error("Le polygone n'a aucun point.");
            }

            for (const auto& point : p.getPoints()) {
                request << " " << point.x << " " << point.y;
            }

            // Ajout de la couleur
            request << " " <<  p.getColor() << "\n";

            // Envoi de la requête au serveur
            client.send(request.str());

            // Déconnexion propre
            client.disconnect();
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de l'envoi du polygone : " << e.what() << std::endl;
            client.disconnect(); // Assurez-vous que la déconnexion est toujours appelée
        }
    }

    void visit(const Triangle &t) const override {
        TCPClient client;
        client.connect("127.0.0.1", 8080);



        std::ostringstream request;
        request << "DRAW TRIANGLE " << t.getP1().x << " " << t.getP1().y << " " << t.getP2().x << " " << t.getP2().y << " " << t.getP3().x << " " << t.getP3().y << " " << t.getColor() << "\n";
        client.send(request.str());

        client.disconnect();
    }

    void visit(const Groupe &g) const override {
       /* for (const auto& forme : g.getFormes()) {
            forme->draw();
        }*/

        //todo
    }

    void visit(const Segment &s) const override {
        TCPClient client;
        client.connect("127.0.0.1", 8080);

        std::ostringstream request;
        request << "DRAW SEGMENT " << s.getP1().x << " " << s.getP1().y << " " << s.getP2().x << " " << s.getP2().y << " " << s.getColor() << "\n";
        client.send(request.str());

        client.disconnect();
    }
};



#endif //VISITEURSAUVEGARDERFICHIERTXTIMPLEMENTATION_H
