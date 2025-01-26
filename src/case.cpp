/**
 * @file case.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition des fonctions de la classe Case
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "case.hpp"

/**
 * @brief Constructeur par défaut de la classe case
 * 
 */
Case::Case() : nom("Case par défaut") {}

/**
 * @brief Constructeur avec un paramètre 
 * 
 * @param nom nom de la case
 */
Case::Case(std::string nom) : nom(nom) {}

/**
 * @brief Obtenir le nom de la case
 * 
 * @return std::string le nom de la case
 */
std::string Case::getNom() {
    return this->nom;
}

/**
 * @brief Fixer le nom de la case
 * 
 * @param nom nom que la case va prendre
 */
void Case::setNom(std::string nom) {
    this->nom = nom;
}