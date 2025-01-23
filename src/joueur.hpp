/**
 * @file joueur.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Joueur
 * @version 0.1
 * @date 2025-01-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef joueur_hpp
#define joueur_hpp

#include <string>
#include <iostream>

class Joueur {
    public:
        Joueur();
        Joueur(std::string nom, int argent);
        std::string getNom();
        int getArgent();
        int getTourPrison();
        int getNbCartePrison();
        void setNom(std::string nom);
        void setArgent(int argent);
        void setTourPrison(int tour);
        void setNbCartePrison(int nb);
        void addArgent(int argent);
        void removeArgent(int argent);
    private:
        std::string nom;
        int portefeuille;
        int nbCartePrison;
        int tourPrison;
} ;

#endif