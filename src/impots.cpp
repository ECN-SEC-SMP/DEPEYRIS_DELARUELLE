#include "impots.hpp"

/**
 * @brief Constructeur par défaut de la classe Impots
 * 
 */
Impots::Impots() : Case("Impots") {}

/**
 * @brief Action réalisée si un joueur est sur la case impots
 * 
 * @param j joueur sur la case impots
 */
void Impots::action(Joueur * j) {
    std::cout << j->getNom() << " paie 200 M d'impots." << std::endl ;
    j->removeArgent(200) ;
}