cmake_minimum_required(VERSION 3.14)

project(Harjoitus LANGUAGES CXX)


# Määrittele C++-standardiversio

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)


# Etsi Boost-kirjasto
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

file(GLOB_RECURSE HEADER_FILES Harjoitus/*.h)
file(GLOB_RECURSE SOURCE_FILES Harjoitus/*.cpp)

# Lisää kaikki lähdetiedostot
set(ALL_FILES
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

# Lisää include-hakemistot
include_directories(Harjoitus)

# Luo suoritettava tiedosto
add_executable(Harjoitus ${ALL_FILES})

target_link_libraries(Harjoitus Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Harjoitus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
