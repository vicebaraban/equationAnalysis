cmake_minimum_required(VERSION 3.23)
project(equationAnalysis C)

set(CMAKE_C_STANDARD 99)

add_executable(equationAnalysis main.c quadEquAnalysis.c quadEquAnalysis.h)
