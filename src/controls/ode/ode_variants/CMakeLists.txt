add_library(ode_harmonic ode_harmonic.cpp)

target_include_directories(ode_harmonic PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/plotter/ode/ode_variants
)

target_link_libraries(ode_harmonic PUBLIC
    ode
)
