#include "prison.hpp"

/**
 * @brief Constructeur par défaut de la classe prison
 * 
 */
Prison::Prison() : prisonniers(nullptr) {}

/**
 * @brief Action réalisée si un joueur est sur la case prison
 * 
 * @param j joueur en prison
 */
void Prison::action(Joueur * j) {
    auto it = find(this->getPrisonnier()->begin(), this->getPrisonnier()->end(), j);
    if(it == this->getPrisonnier()->end()) {
        std::cout << j->getNom() << " effectue une visite simple en Prison." << std::endl;
        return;
    } else if(j->getTourPrison() >= 2) {
        
    }
}

