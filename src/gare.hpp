/**
 * @file gare.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Gare
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef gare_hpp
#define gare_hpp

#include "propriete.hpp"

class Gare : public Propriete {
    public:
        Gare();
        int calculLoyer() override;
} ;

#endif