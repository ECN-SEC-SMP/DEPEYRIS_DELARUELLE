/**
 * @file prison.prison_hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Prison
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef prison_hpp
#define prison_hpp

#include "case.hpp"
#include "joueur.hpp"
#include <vector>

class Prison : public Case {
    public:
        Prison();
        void action(Joueur* j);
        void addPrisonnier(Joueur * j);
        void removePrisonnier(Joueur * j);
        std::vector<Joueur>* getPrisonnier();
        void setPrisonnier(std::vector<Joueur>* prisionniers);
    private:
        std::vector<Joueur>* prisonniers;
        enum states {
            TEST_TOUR,
            TEST_CARTE_LIBERATION,
            LANCER_DE,
            PAYER_POUR_SORTIR,
            SORTIR
        }
} ;

#endif