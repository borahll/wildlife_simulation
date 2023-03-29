cmake_minimum_required(VERSION 3.25)
project(wildlife_simulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(22101852_Bora_Haliloglu_hw3)

add_executable(wildlife_simulation
        22101852_Bora_Haliloglu_hw3/Creatures.cpp
        22101852_Bora_Haliloglu_hw3/Creatures.hpp
        22101852_Bora_Haliloglu_hw3/Food.cpp
        22101852_Bora_Haliloglu_hw3/Food.hpp
        22101852_Bora_Haliloglu_hw3/SimulationMgr.cpp)
