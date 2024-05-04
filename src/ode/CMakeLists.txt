add_library(ode ode.c)
target_include_directories(ode PUBLIC ${CMAKE_SOURCE_DIR}/include/diffeq/ode)
