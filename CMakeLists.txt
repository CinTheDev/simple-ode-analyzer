cmake_minimum_required(VERSION 3.10)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

if (wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

project(diffeq)

add_library(plotter src/plotter.c)
target_include_directories(plotter PUBLIC ${CMAKE_SOURCE_DIR}/include/diffeq)

add_library(ode src/ode.c)
target_include_directories(ode PUBLIC ${CMAKE_SOURCE_DIR}/include/diffeq)
