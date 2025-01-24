#include "chance.hpp"


void Chance::action(Joueur* joueur){

    int randomNumber = 0;
    cartesChance carteRandom;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distChance(0,14); // distribution in range [0, 14]
    randomNumber = distChance(rng) ;
    carteRandom = static_cast<cartesChance>(randomNumber);

    switch (carteRandom)
    {
    case cartesChance::AVANCER_CASE_DEPART:
        std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à la case Départ." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;
    case cartesChance::RDV_RUE_LA_PAIX:
        std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à la rue de la Paix." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;
    case cartesChance::RDV_HENRI_MARTIN:
        std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à l'avenue Henri Martin." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;
    case cartesChance::REPARATION_MAISON_4000_HOTEL_11500:
        std::cout << "Moalic est devenu fou au volant de sa BMW ! Le joueur " << joueur->getNom() <<
         "doit réparer ses maisons (40 M chacunes) et ses hôtels (115 M chacuns)." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;
    case cartesChance::AVANCER_GARE_DE_LYON:
        std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'à la gare de Lyon." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;
    case cartesChance::PRIX_MOTS_CROISES:
        std::cout << "Le joueur " << joueur->getNom() << "a gagné le tournoi des mots croisés. T'es vieux mais tu as 100 M en plus." << std::endl;
        joueur->addArgent(100);
        break;    
    case cartesChance::DIVIDENDE_BANCAIRE:
        std::cout << "Le joueur " << joueur->getNom() << ", la banque vous verse un dividende de 50 M." << std::endl;
        joueur->addArgent(50);
        break;    
    case cartesChance::LIBERE_PRISON:
        std::cout << "Le joueur " << joueur->getNom() << "devient un chat. Cette carte vous permez de sortir de prison." << std::endl;
        joueur->setNbCartePrison(joueur-> getNbCartePrison()+1);
        break;    
    case cartesChance::RECULER_3_CASES:
        std::cout << "Le joueur " << joueur->getNom() << " fais la connaissance de la SSAT, Vous prenez peur et reculez de 3 cases." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;    
    case cartesChance::ALLER_PRISON:
        std::cout << "Hop !Le joueur " << joueur->getNom() << "va en prison. Il fallait pas me ma bouffe." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;    
    case cartesChance::REPARATION_MAISON_2500_HOTEL_10000:
        std::cout << "Oh non, un Tommy sauvage est apparu ! Le joueur " << joueur->getNom() << "doit réparer ses maisons (25 M chacunes) et ses hôtels (100 M chacuns)." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;    
    case cartesChance::AMENDE_EXCES_VITESSE:
        std::cout << "Moalic s'est fait flashé au volant de sa BMW. Malheureusement pour vous, il a trouvé le moyen de faire payer l'amende à sa place.Le joueur " << joueur->getNom() << " doit payer 15 M." << std::endl;
        joueur->removeArgent(15);
        break;    
    case cartesChance::PAYEZ_FRAIS_SCOLARITE:
        std::cout << "Le joueur " << joueur->getNom() << "s'écrit à Centrale. Il paie 150 M de frais de scolarité." << std::endl;
        joueur->removeArgent(150);
        break;    
    case cartesChance::AMENDE_IVRESSE:
        std::cout << "Le joueur " << joueur->getNom() << " est aussi torché que Zak. Il paie 20 M pour ivresse sur voie publique" << std::endl;
        joueur->removeArgent(20);
        break;    
    case cartesChance::IMMEUBLE_PRET_RAPPORTENT:
        std::cout << "Le joueur " << joueur->getNom() << " a bien investi et obtient 150 M." << std::endl;
        joueur->addArgent(150);
        break; 
    case cartesChance::RDV_BLVD_VILLETTE:
        std::cout << "Le joueur " << joueur->getNom() << "s'avance jusqu'au boulevard de la Villette." << std::endl;
        /* Fonction à implémeter je sais pas ou*/
        break;

    default:
        std::cout << "Le joueur " << joueur->getNom() << " est étourdi." << std::endl;
        throw("Carte chance inconnue");
        break;
    }
    
}