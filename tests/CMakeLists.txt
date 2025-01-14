# Ajouter Google Test
add_subdirectory(../googletest googletest-build)

# Activer les tests
enable_testing()

# Définir les fichiers sources et d'en-tête nécessaires
set(SOURCES
    ../src/main.cpp
)

set(HEADERS
)

# Créer une bibliothèque statique avec les fichiers sources
add_library(my_library STATIC ${SOURCES} ${HEADERS})

# Définir les fichiers de test
set(TEST_SOURCES
    TU.cpp
)

# Créer un exécutable pour chaque fichier de test unitaire
add_executable(TU TU.cpp)

# Lier Google Test et les fichiers sources aux exécutables de test unitaire
target_link_libraries(TU my_library gtest gtest_main)

# Créer un exécutable global pour tous les tests unitaires
add_executable(all_tests ${TEST_SOURCES})

# Lier Google Test et les fichiers sources à l'exécutable global
target_link_libraries(all_tests my_library gtest gtest_main)

# Ajouter les tests
add_test(NAME TU COMMAND TU)