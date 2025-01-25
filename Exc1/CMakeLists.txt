file(GLOB SOURCE cpp/src/*.cpp cpp/main/main.cpp)
include_directories(cpp/include)

add_executable(exc1 ${SOURCE})

set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plots/)
target_compile_definitions(exc1 PRIVATE OUTPUT_DIRECTORY="${OUTPUT_DIRECTORY}")

target_link_libraries(exc1 PRIVATE matplot)