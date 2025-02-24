/**
 * @file chance.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Definition des fonctions de la classe Chance
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "chance.hpp"

/**
 * @brief Constructeur par defaut de la classe Chance
 * 
 */
Chance::Chance() : Case("Chance") {}

/**
 * @brief Tirer une carte chance et appliquer l'action associee
 * 
 * @param joueur joueur qui tire la carte
 */
void Chance::action(Joueur* joueur){
    cartesChance carteRandom;
    carteRandom = static_cast<cartesChance>(lancerDe(0, 15));

    switch (carteRandom)
    {
        case cartesChance::AVANCER_CASE_DEPART:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'a la case Depart." << std::endl;
            joueur->deplacer(0); 
        } break;

        case cartesChance::RDV_RUE_LA_PAIX:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'a la rue de la Paix." << std::endl;
            joueur->deplacer(39);
        } break;

        case cartesChance::RDV_HENRI_MARTIN:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'a l'avenue Henri Martin." << std::endl;
            joueur->deplacer(24);
        } break;

        case cartesChance::REPARATION_MAISON_4000_HOTEL_11500:
        {
            std::cout << "Moalic est devenu fou au volant de sa BMW ! Le joueur " << joueur->getNom() << "doit reparer ses maisons (40 M chacunes) et ses hotels (115 M chacuns)." << std::endl;
            int nbMaison = joueur->nbMaisonHotel()[0];
            int nbHotel = joueur->nbMaisonHotel()[1];
            joueur->removeArgent(nbMaison*40+nbHotel*115);
        } break;

        case cartesChance::AVANCER_GARE_DE_LYON:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'a la gare de Lyon." << std::endl;
            joueur->deplacer(15);
        } break;

        case cartesChance::PRIX_MOTS_CROISES:
        {
            std::cout << "Le joueur " << joueur->getNom() << "a gagne le tournoi des mots croises. T'es vieux mais tu as 100 M en plus." << std::endl;
            joueur->addArgent(100);
        } break;  

        case cartesChance::DIVIDENDE_BANCAIRE:
        {
            std::cout << "Le joueur " << joueur->getNom() << ", la banque vous verse un dividende de 50 M." << std::endl;
            joueur->addArgent(50);
        } break;  

        case cartesChance::LIBERE_PRISON:
        {
            std::cout << "Le joueur " << joueur->getNom() << "devient un chat. Cette carte vous permez de sortir de prison." << std::endl;
            joueur->setNbCartePrison(joueur-> getNbCartePrison()+1);
        } break;  

        case cartesChance::RECULER_3_CASES:
        {
            std::cout << "Le joueur " << joueur->getNom() << " fais la connaissance de la SSAT, Vous prenez peur et reculez de 3 cases." << std::endl;
            joueur->deplacer(joueur->getPosition()-3);
        } break;   

        case cartesChance::ALLER_PRISON:
        {
            std::cout << "Hop !Le joueur " << joueur->getNom() << "va en prison. Il fallait pas me piquer ma bouffe." << std::endl;
            joueur->deplacer(30);
        } break;  

        case cartesChance::REPARATION_MAISON_2500_HOTEL_10000:
        {
            std::cout << "Oh non, un Tommy sauvage est apparu ! Le joueur " << joueur->getNom() << "doit reparer ses maisons (25 M chacunes) et ses hotels (100 M chacuns)." << std::endl;
            int nbMaison = joueur->nbMaisonHotel()[0];
            int nbHotel = joueur->nbMaisonHotel()[1];
            joueur->removeArgent(nbMaison*25+nbHotel*100);
        } break;  

        case cartesChance::AMENDE_EXCES_VITESSE:
        {
            std::cout << "Moalic s'est fait flashe au volant de sa BMW. Malheureusement pour vous, il a trouve le moyen de faire payer l'amende a sa place. Le joueur " << joueur->getNom() << " doit payer 15 M." << std::endl;
            joueur->removeArgent(15);
        } break; 

        case cartesChance::PAYEZ_FRAIS_SCOLARITE:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'ecrit a Centrale. Il paie 150 M de frais de scolarite." << std::endl;
            joueur->removeArgent(150);
        } break; 

        case cartesChance::AMENDE_IVRESSE:
        {
            std::cout << "Le joueur " << joueur->getNom() << " est aussi torche que Zak. Il paie 20 M pour ivresse sur voie publique" << std::endl;
            joueur->removeArgent(20);
        } break;  

        case cartesChance::IMMEUBLE_PRET_RAPPORTENT:
        {
            std::cout << "Le joueur " << joueur->getNom() << " a bien investi et obtient 150 M." << std::endl;
            joueur->addArgent(150);
        } break; 

        case cartesChance::RDV_BLVD_VILLETTE:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'au boulevard de la Villette." << std::endl;
            joueur->deplacer(11);
        } break;
        
        default:
        {
            std::cout << "Le joueur " << joueur->getNom() << " est etourdi." << std::endl;
            std::cout <<("Carte chance inconnue");
        } break;
    }
    
}