/**
 * @file utilitaire.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions utilitaires du jeu
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "utilitaire.hpp"

/**
 * @brief Renvoie un nombre aleatoire entre 1 et 6
 * 
 * @return int 
 */
int lancerDe(uint16_t borneInf, uint16_t borneSup) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distHasard(borneInf,borneSup); // distribution in range [1, 6]
    return distHasard(rng);
}