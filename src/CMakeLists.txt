# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
)

set(HEADERS
)

# Créer l'exécutable
add_executable(main ${SOURCES} ${HEADERS})