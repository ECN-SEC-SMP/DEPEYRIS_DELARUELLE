/**
 * @file compagnie.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Compagnie
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef servicePublic_hpp
#define servicePublic_hpp

#include <iostream>
#include "propriete.hpp"
#include "utilitaire.hpp"

class Compagnie : public Propriete {
    public:
        Compagnie();
        Compagnie(std::string nom, int prix);
        void action(Joueur * j) override;
        int calculLoyer() override;
    private:
        int des;
} ;

#endif