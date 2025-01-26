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
 * @brief Défini le nombre de joueurs et leur nom
 * 
 */
void Jeu::parametrer() {
    int nbJoueurs = 0;
    std::string nom;
    std::cout << "Combien de joueurs ?" << std::endl;
    std::cin >> nbJoueurs;
    for (int i = 0; i < nbJoueurs; i++) {
        std::cout << "Nom du joueur " << i+1 << " : ";
        std::cin >> nom;
        joueurs.push_back(Joueur(nom, 1500));
    }
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

