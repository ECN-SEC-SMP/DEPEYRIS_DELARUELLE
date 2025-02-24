/**
 * @file arrestation.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe Arrestation
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "arrestation.hpp"

/**
 * @brief Constructeur par defaut de la classe Arrestation
 * 
 */
Arrestation::Arrestation() : Case("Arrestation") {}

/**
 * @brief Action realisee si un joueur est sur la case arrestation
 * 
 * @param j joueur sur la case arrestation
 */
void Arrestation::action(Joueur * j) {
    std::cout << j->getNom() << " va en prison." << std::endl ;
    j->setTourPrison(0) ;
}