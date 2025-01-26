/**
 * @file taxeDeLuxe.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe taxeDeLuxe
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef taxeDeLuxe_hpp
#define taxeDeLuxe_hpp

#include "case.hpp"
#include "joueur.hpp"

class TaxeDeLuxe : public Case {
    public:
        TaxeDeLuxe();
        void action(Joueur* j);
    private:
} ;

#endif