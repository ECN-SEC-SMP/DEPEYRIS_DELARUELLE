/**
 * @file main.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief programme principal
 * @version 0.1
 * @date 2025-01-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "jeu.hpp"

int main () {
    Jeu jeu;
    jeu.parametrer();
    do {
        jeu.jouerUnTour();
    } while (1);
}