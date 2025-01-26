/**
 * @file TU_utilitaire.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Test unitaire des fonctions utilitaires
 * @version 0.1
 * @date 2025-01-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "gtest/gtest.h"
#include "../src/utilitaire.hpp"

// test de la méthode lancerDe
TEST(Jeu, lancerDe) {
    for(int i = 0; i < 1000; i++) {
        int de = lancerDe(1,6);
        EXPECT_GE(de, 1);
        EXPECT_LE(de, 6);
    }
}