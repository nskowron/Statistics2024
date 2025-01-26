file(GLOB SOURCE cpp/src/*.cpp cpp/main/main.cpp)
include_directories(cpp/include)

add_executable(exc3-2 ${SOURCE})

set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plots/)
target_compile_definitions(exc3-2 PRIVATE OUTPUT_DIRECTORY="${OUTPUT_DIRECTORY}")

target_link_libraries(exc3-2 PRIVATE matplot)