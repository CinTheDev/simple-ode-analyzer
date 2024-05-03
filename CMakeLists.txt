cmake_minimum_required(VERSION 3.10)

project(diffeq)

add_library(plotter src/plotter.c)
target_include_directories(plotter PUBLIC ${CMAKE_SOURCE_DIR}/include/diffeq)

add_library(ode src/ode.c)
target_include_directories(ode PUBLIC ${CMAKE_SOURCE_DIR}/include/diffeq)

add_executable(diffeq
    src/main.c
)
target_link_libraries(diffeq
    PUBLIC
    ode
    plotter
    m
)
