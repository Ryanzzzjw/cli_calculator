# CMake configuration for Command Line Calculator
# Multi-file compilation project

cmake_minimum_required(VERSION 3.10)
project(cli_calculator C)

# Set C language standard
set(CMAKE_C_STANDARD 11)

# Add executable with all source files
add_executable(cli_calculator
        main.c
        calc.c
)

# ========================================
# Module 9: Link Math Library
# ========================================
# TODO: Uncomment the following lines after implementing scientific functions

# On Linux/macOS, you need to link the math library explicitly
# On Windows with MSVC, math functions are included by default
# if(UNIX)
#     target_link_libraries(cli_calculator m)
# endif()

# Alternative: Link math library on all platforms (also works)
 target_link_libraries(cli_calculator m)

# Optional: Enable compiler warnings
# Uncomment to enable:
# if(MSVC)
#     target_compile_options(cli_calculator PRIVATE /W4)
# else()
#     target_compile_options(cli_calculator PRIVATE -Wall -Wextra -pedantic)
# endif()
