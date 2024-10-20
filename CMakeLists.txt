set(EXECUTABLE_OUTPUT_PATH bin)

# My files
file(GLOB SOURCE cpp/src/*.cpp cpp/main/main.cpp)
include_directories(cpp/include)

add_executable(main ${SOURCE})

set(OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plots/)
target_compile_definitions(main PRIVATE OUTPUT_DIRECTORY="${OUTPUT_DIRECTORY}")


# Matplot++
add_subdirectory(matplotplusplus)
target_link_libraries(main PUBLIC matplot)


# Clang-tidy
set(CMAKE_CXX_CLANG_TIDY "")
set_target_properties(main PROPERTIES CXX_CLANG_TIDY "clang-tidy;-checks=\
  bugprone-*,\
  cppcoreguidelines-*,\
  clang-analyzer-*,\
  readability-*,\
  misc-*")