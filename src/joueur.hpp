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
#include <vector>

class Terrain ;
class Propriete ;

class Joueur {
    public:
        Joueur() ;
        Joueur(std::string nom, int argent) ;
        void addArgent(int argent) ;
        void removeArgent(int argent) ;
        void addPropriete(Propriete * propriete) ;
        void removePropriete(Propriete * propriete) ;
        void deplacer(int numCase) ;
        std::vector<int> nbMaisonHotel() ;
        std::string getNom() ;
        int getArgent() ;
        int getTourPrison() ;
        int getNbCartePrison() ;
        std::vector<Propriete*> getProprietes() ;
        int getPosition() ;
        int getCompteurDouble();
        void setNom(std::string nom) ;
        void setArgent(int argent) ;
        void setTourPrison(int tour) ;
        void setNbCartePrison(int nb) ;
        void setProprietes(std::vector<Propriete*> proprietes) ;
        void setPosition(int position) ;
        void setCompteurDouble(int compteur);
        
    private:
        std::string nom ;
        int portefeuille ;
        int nbCartePrison ;
        int tourPrison ;
        int compteurDouble ;
        int position ;
        std::vector<Propriete*> proprietes ;
} ;

#endif