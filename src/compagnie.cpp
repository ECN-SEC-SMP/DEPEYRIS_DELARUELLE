#include "compagnie.hpp"

/**
 * @brief Constructeur par défaut de la classe Compagnie
 * 
 */
Compagnie::Compagnie() : Propriete("Compagnie", 150) {}

/**
 * @brief Constructeur de la classe Compagnie
 * 
 * @param nom nom de la compagnie
 * @param prix prix d'acquisition de la compagnie
 */
Compagnie::Compagnie(std::string nom, int prix) : Propriete(nom, prix) {}

/**
 * @brief Action réalisée si un joueur est sur la case compagnie
 * 
 * @param j joueur sur la case compagnie
 */
void Compagnie::action(Joueur * j) {
    this->des = lancerDe(1,6) + lancerDe(1,6) ;
    std::cout << j->getNom() << " lance les dés et fait un total de " << this->des << "." << std::endl ;
    j->removeArgent(calculLoyer()) ;
    this->getProprietaire()->addArgent(calculLoyer()) ;
}

/**
 * @brief Calcul du loyer d'une compagnie
 * 
 * @param des somme des dés
 * @return int loyer
 */
int Compagnie::calculLoyer() {
    int cpt = 0 ;
    for (auto it = this->getProprietaire()->getProprietes().begin(); it != this->getProprietaire()->getProprietes().end(); ++it) {
        if (dynamic_cast<Compagnie*>(*it)) {
            cpt ++;
        }
    }
    if (cpt == 1) {
        return this->des * 4 ;
    } else if (cpt == 2) {
        return this->des * 10 ;
    } else {
        throw "Erreur dans le calcul du loyer de la compagnie" ;
    }
}