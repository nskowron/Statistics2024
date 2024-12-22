set(EXECUTABLE_OUTPUT_PATH bin)

# My files
set(CMAKE_CXX_FLAGS_DEBUG "-g")

file(GLOB SOURCE cpp/src/*.cpp cpp/main/main.cpp)
include_directories(cpp/include)

add_executable(main ${SOURCE})

set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plots/)
target_compile_definitions(main PRIVATE OUTPUT_DIRECTORY="${OUTPUT_DIRECTORY}")

target_compile_options(main PRIVATE "-w")
set_property(TARGET main PROPERTY CXX_STANDARD 23)

# Matplot++
add_subdirectory(/home/nel/Uni/Statistics2024/matplotplusplus ${CMAKE_BINARY_DIR}/matplotplusplus)

target_compile_options(matplot PRIVATE "-w")

target_link_libraries(main PUBLIC matplot)