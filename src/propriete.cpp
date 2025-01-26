/**
 * @file propriete.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe Propriete
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "propriete.hpp"
#include "joueur.hpp"

/**
 * @brief Cosntructeur par defaut de la classe Propriete
 * 
 */
Propriete::Propriete() : Case(), proprietaire(nullptr), prixAcquisition(1000), loyer(0), hypotheque(false) {}

/**
 * @brief Constructeur de la classe Propriete avec les parametres
 * 
 * @param nom nom de la case
 * @param prixAcquisition prix de vente de la case
 * @param loyer loyer de la case 
 */
Propriete::Propriete(std::string nom, int prixAcquisition) : Case(nom), proprietaire(nullptr), prixAcquisition(prixAcquisition), loyer(0), hypotheque(false) {}

/**
 * @brief Permet d'acheter une propriete
 * 
 * @param joueur 
 */
void Propriete::acheter(Joueur * joueur) {
    std::string reponse = "";
    if(joueur->getArgent() < this->prixAcquisition) {
        std::cout << "Le joueur n'a pas assez d'argent pour acheter la propriete" << std::endl;
    } else {
        std::cout << "Voulez-vous acheter " << this->getNom() << " pour " << this->prixAcquisition << " M ? (oui/non)" << std::endl;
        std::cin >> reponse;
        if(reponse == "oui") {
            joueur->removeArgent(this->prixAcquisition);
            this->proprietaire = joueur;
            joueur->addPropriete(this);
        } else {
            std::cout << "Le joueur n'a pas achete la propriete" << std::endl;
        }
    }
}

/**
 * @brief Permet de payer le loyer lorsqu'un joueur tomber sur une propriete
 * 
 * @param joueur 
 */
void Propriete::payerLoyer(Joueur * joueur) {
    if(joueur->getArgent() < this->loyer) {
        std::cout << "Le joueur n'a pas assez d'argent pour payer" << std::endl;
    } else {
        std::cout << joueur->getNom() << " doit payer " << this->loyer << " a " << this->proprietaire->getNom() << "." << std::endl;
        this->proprietaire->addArgent(loyer);
        joueur->removeArgent(loyer);
    }
}

/**
 * @brief Permet une transacation immobiliere entre 2 joueurs (gare ou compagnie)
 * 
 * @param joueur joueur qui realise l'acquisition
 */
void Propriete::vente(Joueur * joueur) {
    if(this->getHypotheque()) {
        std::cout << "La propriete est hypothequee et ne peut pas etre vendue" << std::endl;
    } else if (joueur->getArgent() < this->prixAcquisition) {
        std::cout << "L'acheteur ne possede pas les fonds suffisants pour realiser l'acquisition" << std::endl;
    } else {
        this->proprietaire = joueur;
    }
}

/**
 * @brief Obtenir le nom du proprietaire
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
 * @brief Connaître si la propriete est hypothequee ou non
 * 
 * @return true 
 * @return false 
 */
bool Propriete::getHypotheque() {
    return this->hypotheque;
}

/**
 * @brief Definir le proprietaire
 * 
 * @param proprietaire 
 */
void Propriete::setProprietaire(Joueur * proprietaire) {
    this->proprietaire = proprietaire;
}

/**
 * @brief Definir la valeur de la propriete
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
 * @brief Definir si la propriete est hypothequee
 * 
 * @param hypotheque 
 */
void Propriete::setHypotheque(bool hypotheque) {
    this->hypotheque = hypotheque;
}





