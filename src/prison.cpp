/**
 * @file prison.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe prison
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "prison.hpp"

/**
 * @brief Constructeur par defaut de la classe prison
 * 
 */
Prison::Prison() : Case("Prison"), prisonniers(0) {}

/**
 * @brief Action realisee si un joueur est sur la case prison
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
        std::cout << j->getNom() << "Vous avez " << j->getNbCartePrison() << "cartes \"Vous etes libere de prison\" et " << j->getArgent() << "sur votre portefeuille. Que voulez-vous faire ?" << std::endl ; // On affiche le nombre de cartes "Vous etes libere de prison" et la somme d'argent du joueur
        std::cout << "1. Payer l'amende de " << AMANDE_PRISON << "€" << std::endl ; // On propose de payer l'amende
        if(j->getTourPrison() < MAX_TOUR_PRISON) { // Si le joueur n'a pas encore fait 3 tours en prison
            std::cout << "2. Tenter de lancer les des pour sortir de prison" << std::endl ; // On propose de lancer les des
        }
        if(j->getNbCartePrison() > 0) { // Si le joueur a des cartes "Vous etes libere de prison"
            std::cout << "3. Utiliser une carte \"Vous etes libere de prison\"" << std::endl ; // On propose d'utiliser une carte
        }
        std::cin >> choixJoueur ; // On recupere le choix du joueur
        if(choixJoueur == "1") { // Si le joueur veut payer l'amende
            if(j->getArgent() >= AMANDE_PRISON) { // try catch
                j->removeArgent(AMANDE_PRISON) ; 
                j->setTourPrison(-1) ;
                this->removePrisonnier(j) ;
            } else {
                std::cout << "Vous n'avez pas assez d'argent pour payer l'amende." << std::endl ;
            }
        } else if(choixJoueur == "2" && (j->getTourPrison() < MAX_TOUR_PRISON)) { // Si le joueur veut lancer les des
            int de1 = lancerDe(1,6) ; 
            int de2 = lancerDe(1,6) ;
            if(de1 == de2) {
                std::cout << "Vous avez fait un double. Vous etes libere de prison." << std::endl ;
                j->setTourPrison(-1) ;
                this->removePrisonnier(j) ;
            } else {
                std::cout << "Vous n'avez pas fait de double. Vous restez en prison." << std::endl ;
                j->setTourPrison(j->getTourPrison() + 1) ;
            }
        } else if((choixJoueur == "3") && (j->getNbCartePrison() > 0)) { // Si le joueur veut utiliser une carte "libere de prison"
            j->setTourPrison(-1) ;   // On remet le nombre de tours en prison a 0
            j->setNbCartePrison(j->getNbCartePrison() - 1) ; // On enleve une carte "libere de prison"
            this->removePrisonnier(j) ; // On enleve le joueur de la liste des prisonniers
        }   else {
            std::cout << "Choix invalide." << std::endl ; // Si le choix est invalide
        }
    }
}

/**
 * @brief Ajoute un joueur dans la prison
 * 
 * @param j joueur qui est ajoute en prison
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
 * @brief Definir la liste des prisonniers
 * 
 * @param prisonniers la liste des prisonniers
 */
void Prison::setPrisonnier(std::vector<Joueur*> prisonniers) {
    this->prisonniers = prisonniers ;
}
