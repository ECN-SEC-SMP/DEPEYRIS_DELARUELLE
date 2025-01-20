/**
 * @file jeu.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Desciption de la classe Jeu
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef jeu_hpp
#define jeu_hpp

// Include des classes de cases
#include "terrain.hpp"
#include "gare.hpp"
#include "compagnie.hpp"

// Autres includes
#include "joueur.hpp"
#include "constantes.hpp"
#include <vector>
#include <random>

class Jeu {
    public:
        Jeu();
        void jouer();
        void choixNbJoueurs();
        void enchere(Propriete * propriete);
        Case* getPlateau();
        int getNbJoueurs();
        int getNbHotelsRestants();
        int getNbMaisonsRestantes();
        void setNbHotelsRestants(int nb);
        void setNbMaisonsRestantes(int nb);
        int lancerDe();
    private:
        void initialiserPlateau();
        Case* plateau [NB_CASES];
        std::vector<Joueur> joueurs;
        int hotelsRestants;
        int maisonsRestantes;
};

#endif