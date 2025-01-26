/**
 * @file arrestation.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe Arrestation
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #ifndef arrestation_hpp
 #define arrestation_hpp

#include <iostream>
#include "case.hpp"
#include "joueur.hpp"
 class Arrestation : public Case {
    public:
        Arrestation();
        void action(Joueur* j);
    private:
} ;

#endif