/**
 * @file taxeDeLuxe.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe TaxeDeLuxe
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "taxeDeLuxe.hpp"

/**
 * @brief Constructeur par defaut de la classe TaxeDeLuxe
 * 
 */
TaxeDeLuxe::TaxeDeLuxe() : Case("Taxe de luxe") {}

/**
 * @brief Action realisee si un joueur est sur la case taxe de luxe
 * 
 * @param j joueur sur la case taxe de luxe
 */
void TaxeDeLuxe::action(Joueur * j) {
    std::cout << j->getNom() << " paie 100 M de taxe de luxe." << std::endl ;
    j->removeArgent(100) ;
}