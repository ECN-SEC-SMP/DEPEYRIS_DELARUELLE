/**
 * @file parcGratuit.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe ParcGratuit
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef parcGratuit_hpp
#define parcGratuit_hpp

#include "case.hpp"
#include "joueur.hpp"
#include <iostream>

class ParcGratuit : public Case {
    public:
        ParcGratuit();
        void action(Joueur* j);
    private:
} ;

#endif