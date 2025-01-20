/**
 * @file servicePublic.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe servicePublic
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef servicePublic_hpp
#define servicePublic_hpp

#include "propriete.hpp"

class Compagnie : public Propriete {
    public:
        Compagnie();
        int calculLoyer(int des);
    private:
} ;

#endif