/**
 * @file joueur.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe Joueur
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// -------------------------------------------------------------------------- //
// ------------------------------- Includes --------------------------------- //
// -------------------------------------------------------------------------- //

#include "joueur.hpp"
#include "propriete.hpp"
#include "terrain.hpp"

// -------------------------------------------------------------------------- //
// ------------------------------- Methodes --------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Construct a new Joueur:: Joueur object
 * 
 */
Joueur::Joueur() : nom("Joueur"), portefeuille(1500), nbCartePrison(0), tourPrison(0), proprietes(0), position(0) {}

/**
 * @brief Construct a new Joueur:: Joueur object
 * 
 * @param nom 
 * @param argent 
 */
Joueur::Joueur(std::string nom, int argent) : nom(nom), portefeuille(argent), nbCartePrison(0), tourPrison(0), proprietes(0), position(0) {}


/**
 * @brief Ajouter une propriete a la liste des proprietes du joueur
 * 
 * @param propriete 
 */
void Joueur::addPropriete(Propriete * propriete) {
    this->proprietes.push_back(propriete);
}

/**
 * @brief Retirer une propriete de la liste des proprietes du joueur
 * 
 * @param propriete 
 */
void Joueur::removePropriete(Propriete * propriete) {
    for (int i = 0; i < this->proprietes.size(); i++) {
        if (this->proprietes[i] == propriete) {
            this->proprietes.erase(this->proprietes.begin() + i);
        }
    }
}

/**
 * @brief Deplacer le joueur sur une nouvelle case
 * 
 * @param numCase 
 */
void Joueur::deplacer(int numCase) {
    if ((numCase <= this->getPosition()) && this->getTourPrison() == -1) {
        this->addArgent(200);
        std::cout << this->getNom() << " passe par la case depart. Il reçoit 200 M." << std::endl ;
    }
    this->position = numCase;
}

/** 
 * @brief Compte le nombre de maisons et d'hotels possedes par le joueur
 * 
 * @param 
 */
std::vector<int> Joueur::nbMaisonHotel(){
    int nbMaison = 0 ;
    int nbHotel = 0 ;
    for (auto it = proprietes.begin(); it != proprietes.end(); ++it) {
        if (dynamic_cast<Terrain*>(*it)) {
            int batimentsConstruits = dynamic_cast<Terrain*>(*it)->getMaison() ;
            if (batimentsConstruits > 0 && batimentsConstruits < 6){
                if(batimentsConstruits==5) {
                    nbHotel++ ;
                } else {
                    nbMaison+=batimentsConstruits ;
                }
            } else {
                std::cout << "Il n' y a pas de maison / hotel construit" << std::endl ;
            }
        }
    }
    std::vector<int> nbBatiments;
    nbBatiments.push_back(nbMaison);
    nbBatiments.push_back(nbHotel);
    return nbBatiments;
}

/**
 * @brief Ajouter de l'argent au portefeuille du joueur
 * 
 * @param argent 
 */
void Joueur::addArgent(int argent) {
    this->portefeuille += argent;
}

/**
 * @brief Retirer de l'argent du portefeuille du joueur
 * 
 * @param argent 
 */
void Joueur::removeArgent(int argent) {
   
    if (argent > this->portefeuille) {
        std::cout << "Pas assez d'argent";
    } else {
        this->portefeuille -= argent;
    }  
}

/**
 * @brief Obtenir le nom du joueur
 * 
 * @return std::string 
 */
std::string Joueur::getNom() {
    return nom;
}

/**
 * @brief Obtenir la valeur du portefeuille du joueur
 * 
 * @return int 
 */
int Joueur::getArgent() {
    return portefeuille;
}

/**
 * @brief Obtenir le nombre de tours passes en prison par le joueur
 * 
 * @return int 
 */
int Joueur::getTourPrison() {
    return tourPrison;
}

/**
 * @brief Obtenir le nombre de cartes de sortie de prison du joueur
 * 
 * @return int 
 */
int Joueur::getNbCartePrison() {
    return nbCartePrison;
}

/**
 * @brief Obtenir la liste des proprietes du joueur
 * 
 * @return std::vector<Propriete*> 
 */
std::vector<Propriete*> Joueur::getProprietes() {
    return proprietes;
}

/**
 * @brief Obtenir la position du joueur
 * 
 * @return int 
 */
int Joueur::getPosition() {
    return position;
}

/**
 * @brief Obtenir le nombre de doubles effectués par le joueur
 *
 * @return int
 */
int Joueur::getCompteurDouble() {
    return compteurDouble;
}

/**
 * @brief Donner un nom au joueur
 * 
 * @param nom 
 */
void Joueur::setNom(std::string nom) {
    this->nom = nom;
}

/**
 * @brief Initialiser le portefeuille du joueur
 * 
 * @param argent 
 */
void Joueur::setArgent(int argent) {
    this->portefeuille = argent;
}

/**
 * @brief Initialiser le nombre de tours passes en prison par le joueur
 * 
 * @param tour 
 */
void Joueur::setTourPrison(int tour) {
    this->tourPrison = tour;
}

/**
 * @brief Initialiser le nombre de cartes de sortie de prison du joueur
 * 
 * @param nb 
 */
void Joueur::setNbCartePrison(int nb) {
    this->nbCartePrison = nb;
}

/**
 * @brief Initialiser la liste des proprietes du joueur
 * 
 * @param proprietes 
 */
void Joueur::setProprietes(std::vector<Propriete*> proprietes) {
    this->proprietes = proprietes;
}

/**
 * @brief Initialiser la position du joueur
 * 
 * @param position 
 */
void Joueur::setPosition(int position) {
    this->position = position;
}


/**
 * @brief Initialiser la nombre de double faits par le joueur
 *
 * @param compteur
 */
void Joueur::setCompteurDouble(int compteur) {
    this->compteurDouble = compteur;
}


