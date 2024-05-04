add_subdirectory(ode)

add_library(plotter plotter.c)
target_include_directories(plotter PUBLIC ${CMAKE_SOURCE_DIR}/include/diffeq)
