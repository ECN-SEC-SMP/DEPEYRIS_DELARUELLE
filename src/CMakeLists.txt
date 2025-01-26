# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/arrestation.cpp
    ../src/case.cpp
    ../src/chance.cpp
    ../src/communaute.cpp
    ../src/compagnie.cpp
    ../src/depart.cpp
    ../src/gare.cpp
    ../src/impots.cpp
    ../src/jeu.cpp
    ../src/joueur.cpp
    ../src/main.cpp
    ../src/parcGratuit.cpp
    ../src/prison.cpp
    ../src/propriete.cpp
    ../src/taxeDeLuxe.cpp
    ../src/terrain.cpp
    ../src/utilitaire.cpp
)

set(HEADERS
    ../src/arrestation.hpp
    ../src/case.hpp
    ../src/chance.hpp
    ../src/communaute.hpp
    ../src/compagnie.hpp
    ../src/constantes.hpp
    ../src/depart.hpp
    ../src/gare.hpp
    ../src/impots.hpp
    ../src/jeu.hpp
    ../src/joueur.hpp
    ../src/parcGratuit.hpp
    ../src/prison.hpp
    ../src/propriete.hpp
    ../src/taxeDeLuxe.hpp
    ../src/terrain.hpp
    ../src/utilitaire.hpp
)

# Créer l'exécutable
add_executable(main ${SOURCES} ${HEADERS})