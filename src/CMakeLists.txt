# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
    ../src/jeu.cpp
    ../src/joueur.cpp
)

set(HEADERS
    ../src/constantes.hpp
    ../src/case.hpp
)

# Créer l'exécutable
add_executable(main ${SOURCES} ${HEADERS})