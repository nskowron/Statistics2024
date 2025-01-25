cmake_minimum_required(VERSION 3.14)
project(Statistics2024)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Matplot++
include(FetchContent)
FetchContent_Declare(
    matplot
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus.git
    GIT_TAG v1.2.1
)
FetchContent_MakeAvailable(matplot)

# Exercises
add_subdirectory(Exc1)
add_subdirectory(Exc2)
add_subdirectory(Exc3)