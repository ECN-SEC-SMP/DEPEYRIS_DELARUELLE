# Ajouter Google Test
add_subdirectory(../googletest googletest-build)

# Activer les tests
enable_testing()

# Définir les fichiers sources et d'en-tête nécessaires
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

# Créer une bibliothèque statique avec les fichiers sources
add_library(my_library STATIC ${SOURCES} ${HEADERS})

# Définir les fichiers de test
set(TEST_SOURCES
    TU_jeu.cpp
    TU_joueur.cpp
)

# Créer un exécutable pour chaque fichier de test unitaire
add_executable(TU_jeu TU_jeu.cpp)
add_executable(TU_joueur TU_joueur.cpp)

# Lier Google Test et les fichiers sources aux exécutables de test unitaire
target_link_libraries(TU_jeu my_library gtest gtest_main)
target_link_libraries(TU_joueur my_library gtest gtest_main)

# Créer un exécutable global pour tous les tests unitaires
add_executable(all_tests ${TEST_SOURCES})

# Lier Google Test et les fichiers sources à l'exécutable global
target_link_libraries(all_tests my_library gtest gtest_main)

# Ajouter les tests
add_test(NAME TU_jeu COMMAND TU_jeu)
add_test(NAME TU_joueur COMMAND TU_joueur)