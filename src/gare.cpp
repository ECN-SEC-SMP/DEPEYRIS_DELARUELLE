/**
 * @file gare.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition des fonctions de la classe Gare
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "gare.hpp"
#include "joueur.hpp"

/**
 * @brief Constructeur par défaut de la classe Gare
 * 
 */
Gare::Gare() : Propriete("Gare", 200) {}

/**
 * @brief Constructeur avec des paramètres de la classe Gare
 * 
 * @param nom Nom de la gare
 * @param prix Prix d'achat de la gare
 */
Gare::Gare(std::string nom, int prix) : Propriete(nom, prix) {}

/**
 * @brief Action réalisée si un joueur est sur la case gare
 * 
 * @param j joueur sur la case gare
 */
void Gare::action(Joueur *j) {
    if (this->getProprietaire() == nullptr) { // Si la gare n'a pas de propriétaire
        this->acheter(j); // Le joueur peut l'acheter
    } else if (this->getProprietaire() != j) { // Si la gare a un propriétaire différent du joueur
        int loyer = this->calculLoyer(); // On calcule le loyer à payer
        j->removeArgent(loyer); // Le joueur paie le loyer
        this->getProprietaire()->addArgent(loyer); // Le propriétaire reçoit le loyer
        std::cout << j->getNom() << " paie " << loyer << " M à " << this->getProprietaire()->getNom() << " pour la gare " << this->getNom() << "." << std::endl;
    }
}

/**
 * @brief Calcul du loyer à payer par un joueur qui tombe sur une gare
 * 
 * @return int le loyer à payer
 */
int Gare::calculLoyer() {
    int nbGares = 0;
    for (auto propriete : this->getProprietaire()->getProprietes()) { 
        if (dynamic_cast<Gare*>(propriete)) {   // On compte le nombre de gares possédées par le propriétaire
            nbGares++;
        }
    }
    return 25 * (1 << (nbGares - 1)); // On calcule le loyer en fonction du nombre de gares possédées
}

