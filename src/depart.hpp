/**
 * @file depart.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Depart
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef depart_hpp
#define depart_hpp

#include <iostream>
#include "case.hpp"
#include "joueur.hpp"
class Depart : public Case {
    public:
        Depart();
        void action(Joueur* j);
    private:
} ;

#endif