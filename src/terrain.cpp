/**
 * @file terrain.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe Terrain
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "terrain.hpp"
#include "joueur.hpp"

/**
 * @brief Constructeur par defaut de la classe terrain
 * 
 */
Terrain::Terrain() : Propriete(), maison(0), prixMaison(100), idCouleur(0) {}

/**
 * @brief Constructeur avec des parametres de la classe terrain
 * 
 * @param nom Nom de la parcelle
 * @param prix Prix de la parcelle
 * @param loyer Loyer de la parcelle (evolue avec la construction de maisons/hotel)
 * @param maison Nombre de maisons sur la parcelle
 * @param idCouleur Nombre correspondant a la couleur du terrain et donc au prix d'achat
 */
Terrain::Terrain(std::string nom, int prix, int loyer, int idCouleur) : Propriete(nom, prix), maison(0), idCouleur(idCouleur) {
    switch(idCouleur) { // Calcul du prix d'une maison en fonction du type de terrain
        case 1 : case 2 : this->prixMaison = 50; break; // violet / ciel
        case 3 : case 4 : this->prixMaison = 100; break; // rose / orange
        case 5 : case 6 : this->prixMaison = 150; break; // rouge / jaune
        case 7 : case 8 : this->prixMaison = 200; break; // vert / bleu
        default : std::cout << "Le prix d'achat d'une maison ne peut pas etre defini"; break;
    }
}

/**
 * @brief Action a realiser lorsqu'un joueur tombe sur une case terrain
 * 
 * @param j Joueur qui est tombe sur la case
 */
void Terrain::action(Joueur * j) {
    if(this->proprietaire == nullptr) {
        this->acheter(j);
    } else if(this->proprietaire != j) {
        this->payerLoyer(j);
    }
}

/**
 * @brief Consctruction d'une maison sur un terrain
 * 
 */
void Terrain::construireMaison(int * nbM, int * nbH) {
    int maisonConstruit = 0;
    int HotelConstruit = 0;
    if(this->getHypotheque()) {
        std::cout << "Le terrain est hypotheque, il n'est pas possible de construire une maison" << std::endl;
    } else if(this->getProprietaire()->getArgent() < this->getPrixMaison()) {
        std::cout << "Le proprietaire n'a pas assez d'argent pour acheter une maison" << std::endl;
    } else if(this->getMaison() < 4 ) {
        std::cout << "il n'y a plus de maisons a construire" << std::endl;
        if (nbM==0){
            std::cout << "Il n'y a plus de maisons disponible" << std::endl;
        }
    } else if(this->getMaison() == 4 ) {
        std::cout << "il n'y a plus d'hotels a construire" << std::endl;
        if (nbH==0){
            std::cout << "Il n'y a plus d'hotels disponible" << std::endl;
            return;
        }
    } else {
        this->setMaison(this->getMaison() + 1); // update le nombre global
        if (this->getMaison()==5){
            nbH--;
        } else {
            nbM --;
        }
    }
}

/**
 * @brief Destruction d'une maison sur un terrain
 * 
 */
void Terrain::detruireMaison() {
    if(this->getMaison() < 1) {
        std::cout << "Il n'y a pas de maisons construites sur ce terrain" << std::endl;
    } else {
        this->setMaison(this->getMaison() - 1);
    }
}

/**
 * @brief Obtenir le nombre de maisons construites sur le terrain
 * 
 * @return int Nombre de maisons construites
 */
int Terrain::getMaison() {
    return this->maison;
}

/**
 * @brief Obtenir le prix d'achat d'une maison
 * 
 * @return int Prix d'achat d'une maison
 */
int Terrain::getPrixMaison() {
    return this->prixMaison;
}
/**
 * @brief Obtenir la couleur du terrain
 * 
 * @return int Couleur du terrain
 */
int Terrain::getIdCouleur() {
    return this->idCouleur;
}

/**
 * @brief Obtenir le loyer du terrain 
 * 
 * @return int le loyer 
 */
int Terrain::getLoyer() {
    return this->loyer;
}

void Terrain::setMaison(int nbMaisons) {
    this->maison = nbMaisons;
}

/**
 * @brief Calcule le loyer du terrain qui sera paye par les joueurs adverses lorsqu'ils visiteront la case
 * 
 * @return int  Le loyer calcule
 */
int Terrain::calculLoyer() {
    // Calcul du loyer en fonction du nombre de maisons/hotel construits
    switch(this->getMaison()) {
        case 0 : return this->loyer;
        case 1 : return this->loyer * 5;
        case 2 : return this->loyer * 15;
        case 3 : return this->loyer * 45;
        case 4 : return this->loyer * 80;
        case 5 : return this->loyer * 125;
        default : std::cout << "Le nombre de maisons/hotels est incorrect" << std::endl;
    }    
}


void Terrain::vente(Joueur * joueur) {
    if(this->getHypotheque()) {
        std::cout << "La maison est hypothequee et ne peut pas etre vendue" << std::endl;
    } else if (joueur->getArgent() < this->prixAcquisition) {
        std::cout << "L'acheteur ne possede pas les fonds suffisants pour realiser l'acquisition" << std::endl;
    } else if(this->getMaison() > 0) {
        std::cout << "Il y a des maisons ou un hotel sur le terrain, il ne peut pas etre vendu" << std::endl;
    } else {
        this->proprietaire = joueur;
    }
}