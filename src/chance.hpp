/**
 * @file chance.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Chance
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifdef chance_hpp
#ifndef chance_hpp

#include "case.hpp"
class Chance : public Case {
    public:
        Chance();
        void action(Joueur* j);
    private:
} ;

#endif