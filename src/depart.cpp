#include "depart.hpp"

/**
 * @brief Constructeur par défaut de la classe Depart
 * 
 */
Depart::Depart() : Case("Depart") {}

/**
 * @brief Action réalisée si un joueur est sur la case départ
 * 
 * @param j joueur sur la case départ
 */
void Depart::action(Joueur * j) {
    j->addArgent(200) ; // Le joueur reçoit 200€
    
}

