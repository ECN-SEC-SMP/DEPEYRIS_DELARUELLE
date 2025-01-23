#include "parcGratuit.hpp"

/**
 * @brief Constructeur de la classe ParcGratuit
 * 
 */
ParcGratuit::ParcGratuit() : Case("Parc Gratuit") {}

/**
 * @brief action réalisée sur la case parc gratuit (rien)
 * 
 * @param j joueur
 */
void ParcGratuit::action(Joueur * j) {
    std::cout << j->getNom() << " est sur la case " << this->getNom() << std::endl;
}