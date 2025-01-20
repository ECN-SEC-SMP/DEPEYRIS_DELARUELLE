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

class Terrain : public Propriete {
    public:
        Terrain();
        Terrain(int id, std::string nom, int prix, int maison, bool hotel, int prixMaison, int idCouleur, int loyer[6]);
        void construireMaison();
        void detruireMaison();
        void construireHotel();
        void detruireHotel();
        int getMaison();
        bool getHotel();
        int getPrixMaison();
        int getIdCouleur();
        int getLoyer(int index);
    private:
        int maison;
        bool hotel;
        int prixMaison;
        int idCouleur;
        int loyer[6];
} ;

#endif