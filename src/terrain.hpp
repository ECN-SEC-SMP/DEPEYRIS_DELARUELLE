/**
 * @file terrain.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe terrain
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef terrain_hpp
#define terrain_hpp

#include "propriete.hpp"
#include "joueur.hpp"

class Terrain : public Propriete {
    public:
        Terrain();
        Terrain(std::string nom, int prix, int loyer, int idCouleur);
        void action(Joueur * j) override;
        void construireMaison();
        void detruireMaison();
        int getMaison();
        int getPrixMaison();
        int getIdCouleur();
        int getLoyer();
        void setMaison(int nbMaisons);
        int calculLoyer() override;
        void vente(Joueur * joueur) override;
    private:
        int maison;
        int prixMaison;
        int idCouleur;
} ;

#endif