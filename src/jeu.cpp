/**
 * @file jeu.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition des fonctions de la classe Jeu
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "jeu.hpp"

/**
 * @brief Constructeur par défaut de la classe Jeu
 * 
 */
Jeu::Jeu() {
    hotelsRestants = NB_HOTELS;
    maisonsRestantes = NB_MAISONS;
}

/**
 * @brief un tour d'une partie de Monopoly
 * 
 */
void Jeu::jouerUnTour() {
    int des = 0;
    std::string reponse = "";
    for (std::vector<Joueur>::iterator joueur = joueurs.begin(); joueur <= this->joueurs.end(); joueur++) {
        reponse = "";
        des = 0;
        std::cout << "C'est au tour de " << joueur->getNom() << std::endl;
        des = lancerDe(1,6) + lancerDe(1,6);
        std::cout << "Vous avancez de " << des << " cases." << std::endl;
        joueur->deplacer(joueur->getPosition() + des);
        std::cout << "Vous êtes sur la case " << plateau[joueur->getPosition()]->getNom() << std::endl;
        plateau[joueur->getPosition()]->action(&(*joueur));
        std::cout << "Vous avez " << joueur->getArgent() << "M" << std::endl;
        std::cout << "Voulez-vous construire une maison sur un terrain ? (oui/non)" << std::endl;
        std::cin >> reponse;
        if (reponse == "oui") {
            std::cout << "voici les terrains que vous possédez : " << std::endl;
            for (int i = 0; i < joueur->getProprietes().size(); i++) {
                if (dynamic_cast<Terrain*>(joueur->getProprietes()[i])) {
                    std::cout << joueur->getProprietes()[i]->getNom() << std::endl;
                    std::cout << "Nombre de maisons : " << dynamic_cast<Terrain*>(joueur->getProprietes()[i])->getMaison() << std::endl;
                    std::cout << "Prix d'une maison : " << dynamic_cast<Terrain*>(joueur->getProprietes()[i])->getPrixMaison() << std::endl;
                    std::cout << "Voulez-vous construire une maison sur ce terrain ? (oui/non)" << std::endl;
                    std::cin >> reponse;
                    if (reponse == "oui") {
                        dynamic_cast<Terrain*>(joueur->getProprietes()[i])->construireMaison(this->getNbMaisonsRestantes(), this->getNbHotelsRestants());
                    }   
                }
            }
            std::cin >> reponse;
        } else {
            std::cout << "Fin du tour de " << joueur->getNom() << std::endl;
        }
        faillite(&(*joueur));  
    }
}

/**
 * @brief Défini le nombre de joueurs et leur nom
 * 
 */
void Jeu::parametrer() {
    int nbJoueurs = 0;
    std::string nom;
    do{
        std::cout << "Combien de joueurs ?" << std::endl;
        std::cin >> nbJoueurs;
    } while (nbJoueurs < 2 || nbJoueurs > 8);
    for (int i = 0; i < nbJoueurs; i++) {
        std::cout << "Nom du joueur " << i+1 << " : ";
        std::cin >> nom;
        joueurs.push_back(Joueur(nom, 1500));
    }
}

/**
 * @brief Un joueur a fait faillite
 * 
 * @param joueur joueur qui a fait faillite
 */
void Jeu::faillite(Joueur * joueur) {
    if(joueur->getArgent() <= 0) {
        std::cout << joueur->getNom() << " a fait faillite." << std::endl;
        for (int i = 0; i < joueur->getProprietes().size(); i++) {
        joueur->getProprietes()[i]->setProprietaire(nullptr);
        }
        for (int i = 0; i < joueurs.size(); i++) {
            if (this->joueurs[i].getNom() == joueur->getNom()) {
                joueurs.erase(joueurs.begin() + i);
            }
        }
    } else {
        return;
    }
}

/**
 * @brief Enchère pour l'achat d'une propriété
 * 
 * @param propriete propriété à vendre
 */
void Jeu::enchere(Propriete * propriete) {
    int prix = 0;
    int enchere = 0;
    int nbJoueurs = joueurs.size();
    int i = 0;
    while (i < nbJoueurs) {
        std::cout << "Joueur " << this->joueurs[i].getNom() << ", faites une enchère pour " << propriete->getNom() << " : ";
        std::cin >> enchere;
        if (enchere > prix) {
            prix = enchere;
            i = 0;
        } else {
            i++;
        }
    }
    propriete->setProprietaire(&this->joueurs[i]);
    this->joueurs[i].removeArgent(prix);
}

/**
 * @brief Construit le plateau de jeu
 * 
 */
void Jeu::initialiserPlateau() {
    this->plateau[0] = new Depart();
    this->plateau[1] = new Terrain("Boulevard de Belleville", 60, 2, 1);
    this->plateau[2] = new Chance();
    this->plateau[3] = new Terrain("Rue Lecourbe", 60, 4, 1);
    this->plateau[4] = new Impots();
    this->plateau[5] = new Gare("Gare Montparnasse", 200);
    this->plateau[6] = new Terrain("Rue de Vaugirard", 100, 6, 2);
    this->plateau[7] = new Chance();
    this->plateau[8] = new Terrain("Rue de Courcelles", 100, 6, 2);
    this->plateau[9] = new Terrain("Avenue de la République", 120, 8, 2);
    this->plateau[10] = new Prison();
    this->plateau[11] = new Terrain("Boulevard de la Villette", 140, 10, 3);
    this->plateau[12] = new Compagnie("Compagnie d'électricité", 150);
    this->plateau[13] = new Terrain("Avenue de Neuilly", 140, 10, 3);
    this->plateau[14] = new Terrain("Rue de Paradis", 160, 12, 3);
    this->plateau[15] = new Gare("Gare de Lyon", 200);
    this->plateau[16] = new Terrain("Avenue Mozart", 180, 14, 4);
    this->plateau[17] = new Chance();
    this->plateau[18] = new Terrain("Boulevard Saint-Michel", 180, 14, 4);
    this->plateau[19] = new Terrain("Place Pigalle", 200, 16, 4);
    this->plateau[20] = new ParcGratuit();
    this->plateau[21] = new Terrain("Avenue Matignon", 220, 18, 5);
    this->plateau[22] = new Chance();
    this->plateau[23] = new Terrain("Boulevard Malesherbes", 220, 18, 5);
    this->plateau[24] = new Terrain("Avenue Henri-Martin", 240, 20, 5);
    this->plateau[25] = new Gare("Gare du Nord", 200);
    this->plateau[26] = new Terrain("Faubourg Saint-Honoré", 260, 22, 6);
    this->plateau[27] = new Terrain("Place de la Bourse", 260, 22, 6);
    this->plateau[28] = new Compagnie("Compagnie des eaux", 150);
    this->plateau[29] = new Terrain("Rue La Fayette", 280, 24, 6);
    this->plateau[30] = new Arrestation();
    this->plateau[31] = new Terrain("Avenue de Breteuil", 300, 26, 7);
    this->plateau[32] = new Terrain("Avenue Foch", 300, 26, 7);
    this->plateau[33] = new Chance();
    this->plateau[34] = new Terrain("Boulevard des Capucines", 320, 28, 7);
    this->plateau[35] = new Gare("Gare Saint-Lazare", 200);
    this->plateau[36] = new Chance();
    this->plateau[37] = new Terrain("Avenue des Champs-Elysées", 350, 35, 8);
    this->plateau[38] = new TaxeDeLuxe();
    this->plateau[39] = new Terrain("Rue de la Paix", 400, 50, 8);
}

/**
 * @brief Obtenir le plateau de jeu
 * 
 * @return Case* plateau de jeu
 */
Case * Jeu::getPlateau() {
    return *plateau;
}

/**
 * @brief Obtenir le nombre de joueurs
 * 
 * @return int nombre de joueurs
 */
int Jeu::getNbJoueurs() {
    return joueurs.size();
}

/**
 * @brief Obtenir le nombre d'hotels restants
 * 
 * @return int nombre d'hotels restants
 */
int* Jeu::getNbHotelsRestants() {
    return &hotelsRestants;
}

/**
 * @brief Obtenir le nombre de maisons restantes
 * 
 * @return int nombre de maisons restantes
 */
int* Jeu::getNbMaisonsRestantes() {
    return &maisonsRestantes;
}

/**
 * @brief Définir le nombre d'hotels restants
 * 
 * @param nb nombre d'hotels restants
 */
void Jeu::setNbHotelsRestants(int nb) {
    hotelsRestants = nb;
}

/**
 * @brief Définir le nombre de maisons restantes
 * 
 * @param nb nombre de maisons restantes
 */
void Jeu::setNbMaisonsRestantes(int nb) {
    maisonsRestantes = nb;
}




