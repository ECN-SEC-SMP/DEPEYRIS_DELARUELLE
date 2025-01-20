#include "jeu.hpp"

Jeu::Jeu() {
    hotelsRestants = NB_HOTELS;
    maisonsRestantes = NB_MAISONS;
}

int Jeu::lancerDe() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
    return dist6(rng);
}