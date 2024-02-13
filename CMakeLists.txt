cmake_minimum_required(VERSION 3.17)
project(sfml_proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/Cellar/sfml/2.6.1/include)

link_directories(/usr/local/Cellar/sfml/2.6.1/lib)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(sfml_proj main.cpp
        Logic/Board.cpp
        Logic/Piece.cpp
        Logic/Square.cpp
        Game.cpp
)

target_link_libraries(sfml_proj sfml-graphics sfml-window sfml-system)
