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

class Joueur {
    public:
        Joueur();
        Joueur(int id, std::string nom, int argent);
        int getArgent();
        int getTourPrison();
        int getNbCartePrison();
        void setArgent(int argent);
        void setTourPrison(int tour);
        void setNbCartePrison(int nb);
        void addArgent(int argent);
    private:
        int id;
        std::string nom;
        int portefeuille;
        int nbCartePrison;
        int tourPrison;
};

#endif