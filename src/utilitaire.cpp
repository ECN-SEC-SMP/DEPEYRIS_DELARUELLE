#include "utilitaire.hpp"

/**
 * @brief Renvoie un nombre aléatoire entre 1 et 6
 * 
 * @return int 
 */
int lancerDe(uint16_t borneInf, uint16_t borneSup) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distHasard(borneInf,borneSup); // distribution in range [1, 6]
    return distHasard(rng);
}