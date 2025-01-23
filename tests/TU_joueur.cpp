/**
 * @file TU_joueur.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Tests unitaires de la classe Joueur
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "../src/joueur.hpp"
#include "gtest/gtest.h"
#include <iostream>

// test du constructeur par défaut de la classe Joueur
TEST(Joueur, constructeur_defaut) {
    Joueur joueur;
    EXPECT_EQ(joueur.getNom(), "Joueur");
    EXPECT_EQ(joueur.getArgent(), 1500);
    EXPECT_EQ(joueur.getTourPrison(), 0);
    EXPECT_EQ(joueur.getNbCartePrison(), 0);
}

// test du constructeur avec paramètres de la classe Joueur


// test de l'ajout d'argent
TEST(Joueur, ajout_argent) {
    Joueur joueur;
    joueur.addArgent(500);
    EXPECT_EQ(joueur.getArgent(), 1500+500);
}

// test du retrait d'argent
TEST(Joueur, retrait_argent) {
    Joueur joueur;
    joueur.removeArgent(500);
    EXPECT_EQ(joueur.getArgent(), 1500-500);
}
