/**
 * @file compagnie.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition des fonctions de la classe Compagnie
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "compagnie.hpp"
#include "joueur.hpp"

/**
 * @brief Constructeur par défaut de la classe Compagnie
 * 
 */
Compagnie::Compagnie() : Propriete("Compagnie", 150) {}

/**
 * @brief Constructeur de la classe Compagnie
 * 
 * @param nom nom de la compagnie
 * @param prix prix d'acquisition de la compagnie
 */
Compagnie::Compagnie(std::string nom, int prix) : Propriete(nom, prix) {}

/**
 * @brief Action réalisée si un joueur est sur la case compagnie
 * 
 * @param j joueur sur la case compagnie
 */
void Compagnie::action(Joueur * j) {
    if(this->getProprietaire() == nullptr) { // si la compagnie n'a pas de propriétaire
        this->acheter(j) ; // le joueur peut l'acheter
    } else if(this->getProprietaire() != j) { // si la compagnie a un propriétaire différent du joueur
        this->des = lancerDe(1,6) + lancerDe(1,6) ; // lancer de 2 dés pour calculer le loyer
        std::cout << j->getNom() << " lance les dés et fait un total de " << this->des << "." << std::endl ; 
        this->payerLoyer(j) ; // le joueur doit payer le loyer
    }
}

/**
 * @brief Calcul du loyer d'une compagnie
 * 
 * @param des somme des dés
 * @return int loyer
 */
int Compagnie::calculLoyer() {
    int cpt = 0 ; 
    for (auto it = this->getProprietaire()->getProprietes().begin(); it != this->getProprietaire()->getProprietes().end(); ++it) { // on compte le nombre de compagnies possédées par le propriétaire
        if (dynamic_cast<Compagnie*>(*it)) {
            cpt ++;
        }
    }
    if (cpt == 1) { // calcul du loyer en fonction du nombre de compagnies possédées
        return this->des * 4 ;
    } else if (cpt == 2) {
        return this->des * 10 ;
    } else {
        throw "Erreur dans le calcul du loyer de la compagnie" ; // erreur si le nombre de compagnies possédées est différent de 1 ou 2
    }
}