set(EXECUTABLE_OUTPUT_PATH bin)

file(GLOB SOURCE cpp/src/*.cpp cpp/main/main.cpp)
include_directories(cpp/include)

add_executable(main ${SOURCE})