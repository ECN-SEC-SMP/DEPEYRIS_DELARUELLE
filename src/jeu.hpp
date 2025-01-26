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
#include "depart.hpp"
#include "arrestation.hpp"
#include "case.hpp"
#include "taxeDeLuxe.hpp"
#include "chance.hpp"
#include "prison.hpp"
#include "impots.hpp"
#include "parcGratuit.hpp"
#include "communaute.hpp"

// Autres includes
#include "constantes.hpp"
#include "joueur.hpp"
#include "utilitaire.hpp"
#include <vector>
#include <iostream>


class Jeu {
    public:
        Jeu();
        void jouerUnTour();
        void parametrer();
        void faillite(Joueur * joueur);
        void acheterPropriete(Propriete * propriete);
        void enchere(Propriete * propriete);
        Case * getPlateau();
        int getNbJoueurs();
        int* getNbHotelsRestants();
        int* getNbMaisonsRestantes();
        void setNbHotelsRestants(int nb);
        void setNbMaisonsRestantes(int nb);
    private:
        void initialiserPlateau();
        Case* plateau [NB_CASES];
        std::vector<Joueur> joueurs;
        int hotelsRestants;
        int maisonsRestantes;
};

#endif