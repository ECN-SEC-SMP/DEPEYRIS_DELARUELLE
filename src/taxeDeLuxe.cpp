#include "taxeDeLuxe.hpp"

/**
 * @brief Constructeur par défaut de la classe TaxeDeLuxe
 * 
 */
TaxeDeLuxe::TaxeDeLuxe() : Case("Taxe de luxe") {}

/**
 * @brief Action réalisée si un joueur est sur la case taxe de luxe
 * 
 * @param j joueur sur la case taxe de luxe
 */
void TaxeDeLuxe::action(Joueur * j) {
    std::cout << j->getNom() << " paie 100 M de taxe de luxe." << std::endl ;
    j->removeArgent(100) ;
}