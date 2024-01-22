cmake_minimum_required(VERSION 3.27)
project(BDP)

# Add the include directory of ENet
include_directories(${CMAKE_SOURCE_DIR}/lib/enet/include)

# Link against the static ENet library
add_library(enet STATIC IMPORTED)
set_target_properties(enet PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/enet/.libs/libenet.a)

# Find and link against ncurses
find_package(Curses REQUIRED)

set(SOURCE_FILES
        main.cpp
        game/source/gameClock.cpp
        game/source/game.cpp
        game/source/gameScreen.cpp
        game/source/mainMenu.cpp
        game/source/overScreen.cpp
        game/source/player.cpp
        game/source/teamScreen.cpp
        game/source/terminalSize.cpp
        game/source/button.cpp
        game/source/physics.cpp
        game/source/bCircle.cpp
        game/source/objectManager.cpp
        game/source/gameField.cpp
)

set(HEADERS
        game/content/gameClock.h
        game/content/game.h
        game/content/gameScreen.h
        game/content/mainMenu.h
        game/content/overScreen.h
        game/content/player.h
        game/content/teamScreen.h
        game/content/terminalSize.h
        game/content/button.h
        game/content/physics.h
        game/content/bCircle.h
        game/content/objectManager.h
        game/content/gameField.h
)

# Add executable and link against ENet and ncurses
add_executable(BDP ${SOURCE_FILES} ${HEADERS})
target_link_libraries(BDP PRIVATE enet ncurses)