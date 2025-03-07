/**
 * @file VisiteurEnregistrer.h
 * @brief Declaration of the VisiteurEnregistrer class for saving shapes to text files.
 *
 * This file defines the concrete visitor class VisiteurEnregistrer that implements the Visiteur interface.
 * It provides methods to save the string representation of various geometric shapes (Cercle, Polygone, Segment,
 * Triangle, Groupe) into corresponding text files located in the specified directory.
 */

#ifndef VISITEURENREGISTRER_H
#define VISITEURENREGISTRER_H

#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Segment.h"
#include <fstream>
#include <iostream>
#include <string>

const std::string nomDossier = "../sauvegarde/";

/**
 * @class VisiteurEnregistrer
 * @brief Concrete visitor for saving geometric shapes to text files.
 *
 * The VisiteurEnregistrer class implements the Visiteur interface to save the string representation
 * of each shape into a corresponding text file. Each shape is appended to its respective file, and
 * a confirmation message is output to the console upon success.
 */
class VisiteurEnregistrer : public Visiteur {
public:

    /**
     * @brief Visits a Cercle object and saves its representation to a file.
     * @param c The Cercle object to be saved.
     *
     * Constructs a filename for circles, opens the file in append mode, writes the circle's string representation,
     * and outputs a success or error message.
     */
    void visit(const Cercle &c) const override {
        const std::string filename = nomDossier + "cercles.txt"; // File name for saving circles

        std::ofstream file(filename, std::ios::app); // Open file in append mode
        if (file) {
            file << c.toString() << "\n"; // Write formatted output
            file.close();
            std::cout << "Cercle sauvegardé dans " << filename << std::endl;
        } else {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
        }
    }

    /**
     * @brief Visits a Polygone object and saves its representation to a file.
     * @param p The Polygone object to be saved.
     *
     * Constructs a filename for polygons, opens the file in append mode, writes the polygon's string representation,
     * and outputs a success or error message.
     */
    void visit(const Polygone &p) const override {
        const std::string filename = nomDossier + "polygones.txt"; // File name for saving polygons

        std::ofstream file(filename, std::ios::app); // Open file in append mode
        if (file) {
            file << p.toString() << "\n"; // Write the polygon representation with a newline
            file.close();
            std::cout << "Polygone sauvegardé dans " << filename << std::endl;
        } else {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
        }
    }

    /**
     * @brief Visits a Segment object and saves its representation to a file.
     * @param s The Segment object to be saved.
     *
     * Constructs a filename for segments, opens the file in append mode, writes the segment's string representation,
     * and outputs a success or error message.
     */
    void visit(const Segment &s) const override {
        const std::string filename = nomDossier + "segments.txt"; // File name for saving segments

        std::ofstream file(filename, std::ios::app); // Open file in append mode
        if (file) {
            file << s.toString() << "\n"; // Write formatted output
            file.close();
            std::cout << "Segment sauvegardé dans " << filename << std::endl;
        } else {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
        }
    }

    /**
     * @brief Visits a Triangle object and saves its representation to a file.
     * @param t The Triangle object to be saved.
     *
     * Constructs a filename for triangles, opens the file in append mode, writes the triangle's string representation,
     * and outputs a success or error message.
     */
    void visit(const Triangle &t) const override {
        const std::string filename = nomDossier + "triangles.txt"; // File name for saving triangles

        std::ofstream file(filename, std::ios::app); // Open file in append mode
        if (file) {
            file << t.toString() << "\n"; // Write the triangle representation on one line
            file.close();
            std::cout << "Triangle sauvegardé dans " << filename << std::endl;
        } else {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
        }
    }

    /**
     * @brief Visits a Groupe object and saves its representation to a file.
     * @param g The Groupe object to be saved.
     *
     * Constructs a filename for groups, opens the file in append mode, writes the group's string representation
     * along with a closing brace, and outputs a success or error message.
     */
    void visit(const Groupe &g) const override {
        const std::string filename = nomDossier + "groupes.txt"; // File name for saving groups

        std::ofstream file(filename, std::ios::app); // Open file in append mode
        if (file) {
            file << g.toString() << " }\n"; // Write the group's representation with a closing brace and newline
            file.close();
            std::cout << "Groupe sauvegardé dans " << filename << std::endl;
        } else {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
        }
    }
};

#endif // VISITEURENREGISTRER_H
