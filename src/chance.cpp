/**
 * @file chance.cpp
 * @author DELARUELLE DEPEYRIS
 * @brief Définition des fonctions de la classe Chance
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "chance.hpp"

/**
 * @brief Constructeur par défaut de la classe Chance
 * 
 */
Chance::Chance() : Case("Chance") {}

/**
 * @brief Tirer une carte chance et appliquer l'action associée
 * 
 * @param joueur joueur qui tire la carte
 */
void Chance::action(Joueur* joueur){
    cartesChance carteRandom;
    int randomNumber = 0;
    lancerDe(0,15);
    carteRandom = static_cast<cartesChance>(randomNumber);

    switch (carteRandom)
    {
        case cartesChance::AVANCER_CASE_DEPART:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à la case Départ." << std::endl;
            joueur->deplacer(0); 
        } break;

        case cartesChance::RDV_RUE_LA_PAIX:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à la rue de la Paix." << std::endl;
            joueur->deplacer(39);
        } break;

        case cartesChance::RDV_HENRI_MARTIN:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à l'avenue Henri Martin." << std::endl;
            joueur->deplacer(24);
        } break;

        case cartesChance::REPARATION_MAISON_4000_HOTEL_11500:
        {
            std::cout << "Moalic est devenu fou au volant de sa BMW ! Le joueur " << joueur->getNom() << "doit réparer ses maisons (40 M chacunes) et ses hôtels (115 M chacuns)." << std::endl;
            int nbMaison = joueur->nbMaisonHotel()[0];
            int nbHotel = joueur->nbMaisonHotel()[1];
            joueur->removeArgent(nbMaison*40+nbHotel*115);
        } break;

        case cartesChance::AVANCER_GARE_DE_LYON:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à la gare de Lyon." << std::endl;
            joueur->deplacer(15);
        } break;

        case cartesChance::PRIX_MOTS_CROISES:
        {
            std::cout << "Le joueur " << joueur->getNom() << "a gagné le tournoi des mots croisés. T'es vieux mais tu as 100 M en plus." << std::endl;
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
            std::cout << "Oh non, un Tommy sauvage est apparu ! Le joueur " << joueur->getNom() << "doit réparer ses maisons (25 M chacunes) et ses hôtels (100 M chacuns)." << std::endl;
            int nbMaison = joueur->nbMaisonHotel()[0];
            int nbHotel = joueur->nbMaisonHotel()[1];
            joueur->removeArgent(nbMaison*25+nbHotel*100);
        } break;  

        case cartesChance::AMENDE_EXCES_VITESSE:
        {
            std::cout << "Moalic s'est fait flashé au volant de sa BMW. Malheureusement pour vous, il a trouvé le moyen de faire payer l'amende à sa place. Le joueur " << joueur->getNom() << " doit payer 15 M." << std::endl;
            joueur->removeArgent(15);
        } break; 

        case cartesChance::PAYEZ_FRAIS_SCOLARITE:
        {
            std::cout << "Le joueur " << joueur->getNom() << "s'écrit à Centrale. Il paie 150 M de frais de scolarité." << std::endl;
            joueur->removeArgent(150);
        } break; 

        case cartesChance::AMENDE_IVRESSE:
        {
            std::cout << "Le joueur " << joueur->getNom() << " est aussi torché que Zak. Il paie 20 M pour ivresse sur voie publique" << std::endl;
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
            std::cout << "Le joueur " << joueur->getNom() << " est étourdi." << std::endl;
            throw("Carte chance inconnue");
        } break;
    }
    
}