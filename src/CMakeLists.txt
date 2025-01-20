# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
    ../src/Jeu.cpp
)

set(HEADERS
    ../src/constantes.hpp
)

# Créer l'exécutable
add_executable(main ${SOURCES} ${HEADERS})