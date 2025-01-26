/**
 * @file propriete.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition des fonctions de la classe Propriete
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "propriete.hpp"
#include "joueur.hpp"

/**
 * @brief Cosntructeur par défaut de la classe Propriete
 * 
 */
Propriete::Propriete() : Case(), proprietaire(nullptr), prixAcquisition(1000), loyer(0), hypotheque(false) {}

/**
 * @brief Constructeur de la classe Propriete avec les paramètres
 * 
 * @param nom nom de la case
 * @param prixAcquisition prix de vente de la case
 * @param loyer loyer de la case 
 */
Propriete::Propriete(std::string nom, int prixAcquisition) : Case(nom), proprietaire(nullptr), prixAcquisition(prixAcquisition), loyer(0), hypotheque(false) {}

/**
 * @brief Permet d'acheter une propriété
 * 
 * @param joueur 
 */
void Propriete::acheter(Joueur * joueur) {
    std::string reponse = "";
    if(joueur->getArgent() < this->prixAcquisition) {
        throw "Le joueur n'a pas assez d'argent pour acheter la propriété";
    } else {
        std::cout << "Voulez-vous acheter " << this->getNom() << " pour " << this->prixAcquisition << " ? (oui/non)" << std::endl;
        std::cin >> reponse;
        if(reponse == "oui") {
            joueur->removeArgent(this->prixAcquisition);
            this->proprietaire = joueur;
            joueur->addPropriete(this);
        } else {
            throw "Le joueur n'a pas acheté la propriété";
        }
    }
}

/**
 * @brief Permet de payer le loyer lorsqu'un joueur tomber sur une propriété
 * 
 * @param joueur 
 */
void Propriete::payerLoyer(Joueur * joueur) {
    if(joueur->getArgent() < this->loyer) {
        throw "Le joueur n'a pas assez d'argent pour payer" ;
    } else {
        std::cout << joueur->getNom() << " doit payer " << this->loyer << " à " << this->proprietaire->getNom() << "." << std::endl;
        this->proprietaire->addArgent(loyer);
        joueur->removeArgent(loyer);
    }
}

/**
 * @brief Permet une transacation immobilière entre 2 joueurs (gare ou compagnie)
 * 
 * @param joueur joueur qui réalise l'acquisition
 */
void Propriete::vente(Joueur * joueur) {
    if(this->getHypotheque()) {
        throw "La propriété est hypothéquée et ne peut pas être vendue";
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





