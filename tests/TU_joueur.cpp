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
#include "../src/terrain.hpp"
#include "gtest/gtest.h"
#include <iostream>

// test du constructeur par défaut de la classe Joueur
TEST(Joueur, constructeur_defaut) {
    Joueur joueur;
    EXPECT_EQ(joueur.getNom(), "Joueur");
    EXPECT_EQ(joueur.getArgent(), 1500);
    EXPECT_EQ(joueur.getTourPrison(), 0);
    EXPECT_EQ(joueur.getNbCartePrison(), 0);
    EXPECT_EQ(joueur.getProprietes().size(), 0);
    EXPECT_EQ(joueur.getPosition(), 0);
}

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

// test de l'ajout d'une propriété
TEST(Joueur, ajout_propriete) {
    Joueur joueur;
    Terrain propriete("Rue de la Paix", 400, 50, 8);
    joueur.addPropriete(&propriete);
    EXPECT_EQ(joueur.getProprietes().size(), 1);
}

// test de la suppression d'une propriété
TEST(Joueur, suppression_propriete) {
    Joueur joueur;
    Terrain propriete("Rue de la Paix", 400, 50, 8);
    joueur.addPropriete(&propriete);
    joueur.removePropriete(&propriete);
    EXPECT_EQ(joueur.getProprietes().size(), 0);
}

// test du déplacement du joueur
TEST(Joueur, deplacement) {
    Joueur joueur;
    joueur.deplacer(5);
    EXPECT_EQ(joueur.getPosition(), 5);
}

// test de la récupération du nombre de maisons et d'hôtels
TEST(Joueur, nb_maison_hotel) {
    Joueur joueur;
    Terrain propriete1("Rue de la Paix", 400, 50, 8);
    Terrain propriete2("Avenue Foch", 350, 45, 7);
    joueur.addPropriete(&propriete1);
    joueur.addPropriete(&propriete2);
    std::vector<int> nbMaisonHotel = joueur.nbMaisonHotel();
    EXPECT_EQ(nbMaisonHotel[0], 0);
    EXPECT_EQ(nbMaisonHotel[1], 0);
}


