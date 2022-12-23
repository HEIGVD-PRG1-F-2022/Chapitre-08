cmake_minimum_required(VERSION 3.23)
project(Chapitre_08)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(libdio
        GIT_REPOSITORY https://github.com/HEIGVD-PRG1-F-2022/libdio.git
        GIT_TAG v0.2.1
        )
FetchContent_MakeAvailable(libdio)

add_subdirectory(Exo_8_9)
add_subdirectory(Exo_8_a)
add_subdirectory(Exo_8_b)
