#include "prison.hpp"


/**
 * @brief Constructeur par défaut de la classe prison
 * 
 */
Prison::Prison() : Case("Prison"), prisonniers(0) {}

/**
 * @brief Action réalisée si un joueur est sur la case prison
 * 
 * @param j joueur en prison
 */
void Prison::action(Joueur * j) {
    std::string choixJoueur = "";
    auto it = std::find(this->prisonniers.begin(),this->prisonniers.end() , j); // On cherche si le joueur est parmi la liste des prisonniers
    if(it == this->prisonniers.end() && *it != j) { // Si non
        std::cout << j->getNom() << " effectue une visite simple en Prison." << std::endl ; // C'est une visite simple
        return ;
    } else {    // Si oui
        std::cout << j->getNom() << " est en prison. Cela fait " << (j->getTourPrison() + 1) << " tours qu'il est en prison." << std::endl ; // On affiche le nombre de tours en prison du joueur
        std::cout << j->getNom() << "Vous avez " << j->getNbCartePrison() << "cartes \"Vous etes libéré de prison\" et " << j->getArgent() << "sur votre portefeuille. Que voulez-vous faire ?" << std::endl ; // On affiche le nombre de cartes "Vous etes libéré de prison" et la somme d'argent du joueur
        std::cout << "1. Payer l'amende de " << AMANDE_PRISON << "€" << std::endl ; // On propose de payer l'amende
        if(j->getTourPrison() < MAX_TOUR_PRISON) { // Si le joueur n'a pas encore fait 3 tours en prison
            std::cout << "2. Tenter de lancer les dés pour sortir de prison" << std::endl ; // On propose de lancer les dés
        }
        if(j->getNbCartePrison() > 0) { // Si le joueur a des cartes "Vous etes libéré de prison"
            std::cout << "3. Utiliser une carte \"Vous etes libéré de prison\"" << std::endl ; // On propose d'utiliser une carte
        }
        std::cin >> choixJoueur ; // On récupère le choix du joueur
        if(choixJoueur == "1") { // Si le joueur veut payer l'amende
            if(j->getArgent() >= AMANDE_PRISON) { // try catch
                j->removeArgent(AMANDE_PRISON) ; 
                j->setTourPrison(-1) ;
                this->removePrisonnier(j) ;
            } else {
                std::cout << "Vous n'avez pas assez d'argent pour payer l'amende." << std::endl ;
            }
        } else if(choixJoueur == "2" && (j->getTourPrison() < MAX_TOUR_PRISON)) { // Si le joueur veut lancer les dés
            int de1 = lancerDe(1,6) ; 
            int de2 = lancerDe(1,6) ;
            if(de1 == de2) {
                std::cout << "Vous avez fait un double. Vous êtes libéré de prison." << std::endl ;
                j->setTourPrison(-1) ;
                this->removePrisonnier(j) ;
            } else {
                std::cout << "Vous n'avez pas fait de double. Vous restez en prison." << std::endl ;
                j->setTourPrison(j->getTourPrison() + 1) ;
            }
        } else if((choixJoueur == "3") && (j->getNbCartePrison() > 0)) { // Si le joueur veut utiliser une carte "libéré de prison"
            j->setTourPrison(-1) ;   // On remet le nombre de tours en prison à 0
            j->setNbCartePrison(j->getNbCartePrison() - 1) ; // On enlève une carte "libéré de prison"
            this->removePrisonnier(j) ; // On enlève le joueur de la liste des prisonniers
        }   else {
            std::cout << "Choix invalide." << std::endl ; // Si le choix est invalide
        }
    }
}

/**
 * @brief Ajoute un joueur dans la prison
 * 
 * @param j joueur qui est ajouté en prison
 */
void Prison::addPrisonnier(Joueur * j) {
    this->prisonniers.push_back(j) ;
}

/**
 * @brief Sors un joueur de la prison
 * 
 * @param j joueur qui sort de la prison
 */
void Prison::removePrisonnier(Joueur * j) {
    for(std::vector<Joueur*>::iterator it = this->prisonniers.begin(); it < prisonniers.end(); it++) {
        if(*it == j) {
            this->prisonniers.erase(it) ;
            return ; 
        }
    }
}

/**
 * @brief Obtenir la liste des joueurs en prison
 * 
 * @return std::vector<Joueur*> la liste des prisonniers
 */
std::vector<Joueur*> Prison::getPrisonnier() {
    return this->prisonniers ;
}

/**
 * @brief Définir la liste des prisonniers
 * 
 * @param prisonniers la liste des prisonniers
 */
void Prison::setPrisonnier(std::vector<Joueur*> prisonniers) {
    this->prisonniers = prisonniers ;
}
