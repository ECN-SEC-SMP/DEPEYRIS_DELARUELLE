/**
 * @file parcGratuit.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe ParcGratuit
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "parcGratuit.hpp"

/**
 * @brief Constructeur de la classe ParcGratuit
 * 
 */
ParcGratuit::ParcGratuit() : Case("Parc Gratuit") {}

/**
 * @brief action realisee sur la case parc gratuit (rien)
 * 
 * @param j joueur
 */
void ParcGratuit::action(Joueur * j) {
    std::cout << j->getNom() << " est sur la case " << this->getNom() << std::endl;
}