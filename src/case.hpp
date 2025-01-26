/**
 * @file Case.hpp
 * @author DELARUELLE DEPEYRIS
 * @brief Description de la classe case
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef case_hpp
#define case_hpp

#include <string>

class Joueur;

class Case {
    public:
        Case();
        Case(std::string nom);
        virtual void action(Joueur * joueur) = 0;
        std::string getNom();
        void setNom(std::string nom);
    protected:
        std::string nom;
};

#endif