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
        game/source/player.cpp
)

# Add executable and link against ENet and ncurses
add_executable(BDP ${SOURCE_FILES})
target_link_libraries(BDP PRIVATE enet ncurses)