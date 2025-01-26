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

#ifndef chance_hpp
#define chance_hpp


#include <stdio.h>
#include "joueur.hpp"
#include "constantes.hpp"
#include "case.hpp"
#include "utilitaire.hpp"

class Chance : public Case {
    public:
        Chance();
        void action(Joueur* j) override;
    private:
} ;

#endif