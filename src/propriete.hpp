/**
 * @file propriete.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Propriete
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef propriete_hpp
#define propriete_hpp

#include "case.hpp"

class Joueur ;

class Propriete : public Case {
    public:
        Propriete();
        Propriete(std::string nom, int prixAcquisition);
        Propriete(std::string nom, int prixAcquisition, int loyer);
        void enchere();
        void acheter(Joueur * joueur);
        virtual int calculLoyer() = 0;
        void payerLoyer(Joueur * joueur);
        virtual void vente(Joueur * joueur);
        void hypothequer();
        Joueur * getProprietaire();
        int getPrixAcquisition();
        int getLoyer();
        bool getHypotheque();
        void setProprietaire(Joueur * proprietaire);
        void setPrixAcquisition(int prixAcquisition);
        void setLoyer(int loyer);
        void setHypotheque(bool hypotheque);
    protected:
        Joueur * proprietaire;
        int prixAcquisition;
        int loyer;
        bool hypotheque;
} ;

#endif