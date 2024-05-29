cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(task-auriga-1)
add_compile_options(-Wall -Wextra)
add_executable(task-auriga-1
  main.cpp
  algo1.cpp
  algo2.cpp
  algo3.cpp
  algo4.cpp
  algo6.cpp
)
target_compile_features(task-auriga-1 PRIVATE cxx_std_23)
