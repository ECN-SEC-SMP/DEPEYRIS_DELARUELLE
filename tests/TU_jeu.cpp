/**
 * @file TU_JEU.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Tests unitaires de la classe Jeu
 * @version 0.1
 * @date 2025-01-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../src/jeu.hpp"
#include "gtest/gtest.h"
#include <iostream>

//test de la méthode lancerDe
TEST(Jeu, lancerDe) {
    Jeu jeu;
    for(int i = 0; i < 1000; i++) {
        int de = jeu.lancerDe();
        EXPECT_GE(de, 1);
        EXPECT_LE(de, 6);
    }
}
