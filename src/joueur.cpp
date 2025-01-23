/**
 * @file joueur.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Déclaration de la classe Joueur
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

// -------------------------------------------------------------------------- //
// ------------------------------- Méthodes --------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Construct a new Joueur:: Joueur object
 * 
 */
Joueur::Joueur() : nom("Joueur"), portefeuille(1500), nbCartePrison(0), tourPrison(0) {}

/**
 * @brief Construct a new Joueur:: Joueur object
 * 
 * @param nom 
 * @param argent 
 * @param position 
 */
Joueur::Joueur(std::string nom, int argent) : nom(nom), portefeuille(argent), nbCartePrison(0), tourPrison(0) {}

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
 * @brief Obtenir le nombre de tours passés en prison par le joueur
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
 * @brief Initialiser le nombre de tours passés en prison par le joueur
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
        throw "Pas assez d'argent";
    } else {
        this->portefeuille -= argent;
    }  
}

void Joueur::