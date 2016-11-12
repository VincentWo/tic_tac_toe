project(tic_tac_toe)
add_executable(tic_tac_toe src/main.cpp)
target_include_directories(tic_tac_toe PRIVATE include)
target_compile_options(tic_tac_toe PRIVATE -std=c++1z -Wall -Wextra -g -O0)
