#include "arrestation.hpp"

/**
 * @brief Constructeur par défaut de la classe Arrestation
 * 
 */
Arrestation::Arrestation() : Case("Arrestation") {}

/**
 * @brief Action réalisée si un joueur est sur la case arrestation
 * 
 * @param j joueur sur la case arrestation
 */
void Arrestation::action(Joueur * j) {
    std::cout << j->getNom() << " va en prison." << std::endl ;
    j->setTourPrison(0) ;
}