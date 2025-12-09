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
        expression_parser.c
)
target_link_libraries(cli_calculator m)

