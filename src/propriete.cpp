/**
 * @file propriete.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition de la classe propriete
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "propriete.hpp"

/**
 * @brief Cosntructeur par défaut de la classe Propriete
 * 
 */
Propriete::Propriete() : Case(), proprietaire(nullptr), prixAcquisition(1000), loyer(100), hypotheque(false) {}

/**
 * @brief Constructeur de la classe Propriete avec les paramètres
 * 
 * @param nom 
 * @param prixAcquisition 
 * @param loyer 
 */
Propriete::Propriete(std::string nom, int prixAcquisition, int loyer) : Case(nom), proprietaire(nullptr), prixAcquisition(prixAcquisition), loyer(loyer), hypotheque(false) {}

/**
 * @brief Permet de payer le loyer lorsqu'un joueur tomber sur une propriété
 * 
 * @param joueur 
 */
void Propriete::payerLoyer(Joueur * joueur) {
    if(joueur->getArgent() < this->loyer) {
        throw "Le joueur n'a pas assez d'argent pour payer" ;
    } else {
        this->proprietaire->addArgent(loyer);
        joueur->removeArgent(loyer);
    }
}

/**
 * @brief Permet une transacation immobilière entre 2 joueurs (gare ou compagnie)
 * 
 * @param joueur 
 */
void Propriete::vente(Joueur * joueur) {
    if(this->getHypotheque()) {
        throw "La maison est hypothéquée et ne peut pas être vendue";
    } else if (joueur->getArgent() < this->prixAcquisition) {
        throw "L'acheteur ne possède pas les fonds suffisants pour réaliser l'acquisition";
    } else {
        this->proprietaire = joueur;
    }
}

/**
 * @brief Obtenir le nom du propriétaire
 * 
 * @return Joueur* 
 */
Joueur * Propriete::getProprietaire() {
    return this->proprietaire;
}

/**
 * @brief Obtenir le prix de vente
 * 
 * @return int 
 */
int Propriete::getPrixAcquisition() {
    return this->prixAcquisition;
}

/**
 * @brief Obtenir le prix du loyer
 * 
 * @return int 
 */
int Propriete::getLoyer() {
    return this->loyer;
}

/**
 * @brief Connaître si la propriété est hypothéquée ou non
 * 
 * @return true 
 * @return false 
 */
bool Propriete::getHypotheque() {
    return this->hypotheque;
}

/**
 * @brief Définir le propriétaire
 * 
 * @param proprietaire 
 */
void Propriete::setProprietaire(Joueur * proprietaire) {
    this->proprietaire = proprietaire;
}

/**
 * @brief Définir la valeur de la propriété
 * 
 * @param prixAcquisition 
 */
void Propriete::setPrixAcquisition(int prixAcquisition) {
    this->prixAcquisition = prixAcquisition;
}

/**
 * @brief 
 * 
 * @param loyer 
 */
void Propriete::setLoyer(int loyer) {
    this->loyer = loyer;
}

/**
 * @brief Définir si la propriété est hypothéquée
 * 
 * @param hypotheque 
 */
void Propriete::setHypotheque(bool hypotheque) {
    this->hypotheque = hypotheque;
}





