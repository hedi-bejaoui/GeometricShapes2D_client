//
// Created by geffe on 27/01/2025.
//

#ifndef VISITEURENREGISTRER_H
#define VISITEURENREGISTRER_H


#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Segment.h"

const string nomDossier = "../sauvegarde/";


class VisiteurEnregistrer : public Visiteur{
public:



    void visit(const Cercle &c) const override {
        const string filename = nomDossier + "cercles.txt"; // Nom du fichier où sauvegarder

        ofstream file(filename, ios::app); // Ouvre le fichier en mode ajout
        if (file) {
            file << c.toString() << "\n"; // Écriture formatée
            file.close();
            cout << "Cercle sauvegardé dans " << filename << endl;
        } else {
            cerr << "Erreur d'ouverture du fichier !" << endl;
        }
    }


    void visit(const Polygone &p) const override {
        const string filename = nomDossier + "polygones.txt"; // Nom du fichier où sauvegarder

        ofstream file(filename, ios::app); // Ouvre le fichier en mode ajout
        if (file) {
            file << p.toString() << "\n"; // Saut de ligne pour le prochain polygone
            file.close();
            cout << "Polygone sauvegardé dans " << filename << endl;
        } else {
            cerr << "Erreur d'ouverture du fichier !" << endl;
        }
    }


    void visit(const Segment &s) const override {
        const string filename = nomDossier + "segments.txt"; // Nom du fichier où sauvegarder

        ofstream file(filename, ios::app); // Ouvre le fichier en mode ajout
        if (file) {
            file << s.toString() << "\n"; // Écriture formatée
            file.close();
            cout << "Segment sauvegardé dans " << filename << endl;
        } else {
            cerr << "Erreur d'ouverture du fichier !" << endl;
        }
    }


    void visit(const Triangle &t) const override {
        const string filename = nomDossier + "triangles.txt"; // Nom du fichier où sauvegarder

        ofstream file(filename, ios::app); // Ouvre le fichier en mode ajout
        if (file) {
            file << t.toString() << "\n"; // Écrit le triangle sur une ligne
            file.close();
            cout << "Triangle sauvegardé dans " << filename << endl;
        } else {
            cerr << "Erreur d'ouverture du fichier !" << endl;
        }
    }

    void visit(const Groupe &g) const override {
        const string filename = nomDossier + "groupes.txt"; // Nom du fichier où sauvegarder

        ofstream file(filename, ios::app); // Ouvre le fichier en mode ajout
        if (file) {
            file << g.toString() << " }\n"; // Fermeture du groupe et saut de ligne
            file.close();
            cout << "Groupe sauvegardé dans " << filename << endl;
        } else {
            cerr << "Erreur d'ouverture du fichier !" << endl;
        }
    }

};



#endif //VISITEURENREGISTRER_H
