#include "communaute.hpp"


void Communaute::action(Joueur* joueur){

    int randomNumber = 0;
    lancerDe(0,15);
    cartesCommunaute carteRandom = static_cast<cartesCommunaute>(randomNumber);

    switch (carteRandom)
    {
    case cartesCommunaute::PLACEZ_VOUS_CASE_DEPART:
        std::cout << "Le joueur " << joueur->getNom() << " s'avance jusqu'à la case Départ." << std::endl;
        joueur->deplacer(0);
        break;
    case cartesCommunaute::ERREUR_BANQUE:
        std::cout << "La banque a fait une erreur. Le joueur " << joueur->getNom() << "  reçoit 200 M en compensation." << std::endl;
        joueur->addArgent(200);
        break;
    case cartesCommunaute::NOTE_DOCTEUR:
        std::cout << "Le joueur " << joueur->getNom() << " est tombé malade. Le docteur vous demande 50 M." << std::endl;
        joueur->removeArgent(50);
        break;
    case cartesCommunaute::VENTE_STOCK:
        std::cout << joueur->getNom() <<" a fait du ménage dans son grenier. Cela rapporte 50 M." << std::endl;
        joueur->addArgent(50);
        break;
    case cartesCommunaute::LIBERE_PRISON:
        std::cout << "Le joueur " << joueur->getNom() << " devient un chat. Cette carte vous permez de sortir de prison." << std::endl;
        joueur->setNbCartePrison(joueur-> getNbCartePrison()+1);
        break;   
    case cartesCommunaute::ALLER_PRISON:
        std::cout << "Hop! Le joueur " << joueur->getNom() << " va en prison. Il fallait pas voler ma bouffe." << std::endl;
        joueur->deplacer(30);
        break; 
    case cartesCommunaute::RETOURNEZ_BELLEVILLE:
        std::cout << "Le joueur " << joueur->getNom() << " s'avance jusqu'au Boulevard de Belleville." << std::endl;
        joueur->deplacer(1);
        break;
    case cartesCommunaute::REVENU_ANNUEL:
        std::cout << "Le joueur " << joueur->getNom() << " a bien investi. Il touche 100 M." << std::endl;
        joueur->addArgent(100);
        break;    
    case cartesCommunaute::ANNIVERSAIRE:
        std::cout << "On fête l'anniversaire de " << joueur->getNom() << ", la banque vous verse 50 M." << std::endl;
        joueur->addArgent(50);
        break;    
    case cartesCommunaute::CONTRIBUTIONS_REMBOURSENT:
        std::cout << "Le joueur " << joueur->getNom() << " touchent 20 M des contributions." << std::endl;
        joueur->addArgent(20);
        break;    
    case cartesCommunaute::INTERETS_PRET:
        std::cout << joueur->getNom() << " reçoit 25 M de l'intérêt de son emprunt." << std::endl;
        joueur->addArgent(25);
        break;    
    case cartesCommunaute::POLICE_ASSURANCE:
        std::cout << joueur->getNom() << " paie son assurance 50 M." << std::endl;
        joueur->removeArgent(50);
        break;    
    case cartesCommunaute::AMENDE_OU_CARTE_CHANCE:
        std::cout << "Le joueur " << joueur->getNom() << " doit payer une amende de 10 M." << std::endl;
        joueur->removeArgent(10);
        break;    
    case cartesCommunaute::RDV_GARE_LA_PLUS_PROCHE:
        std::cout << "Le joueur " << joueur->getNom() << " est aussi torché que Zak. Il cherche à rejoindre la gare la plus proche." << std::endl;
        int pos = joueur->getPosition();
        int arrondi = ((pso + 5 / 2) / 5) * 5;
        
        break;    
    case cartesCommunaute::PRIX_DE_BEAUTE:
        std::cout << "Le joueur " << joueur->getNom() << " a bien investi et obtient 150 M." << std::endl;
        joueur->addArgent(150);
        break; 
    case cartesCommunaute::HERITAGE:
        std::cout << "Le joueur " << joueur->getNom() << " s'avance jusqu'au boulevard de la Villette." << std::endl;
        joueur->deplacer(11);
        break;

    default:
        std::cout << "Le joueur " << joueur->getNom() << " est étourdi." << std::endl;
        throw("Carte Communaute inconnue");
        break;
    }
    
}