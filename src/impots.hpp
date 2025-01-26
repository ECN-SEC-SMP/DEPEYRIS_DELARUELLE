/**
 * @file impots.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Impots
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef impots_hpp
#define impots_hpp

#include "case.hpp"
#include "joueur.hpp"
class Impots : public Case {
    public:
        Impots();
        void action(Joueur* j);
    private:
} ;

#endif