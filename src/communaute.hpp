/**
 * @file communaute.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Communaute
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef communaute_hpp
#define communaute_hpp

#include <stdio.h>
#include "joueur.hpp"
#include "constantes.hpp"
#include "case.hpp"
#include "utilitaire.hpp"

class Communaute : public Case {
    public:
        Communaute();
        void action(Joueur* j);
    private:
} ;

#endif