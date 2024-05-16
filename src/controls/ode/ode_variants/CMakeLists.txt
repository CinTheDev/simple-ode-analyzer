# HARMONIC OSCILLATION
add_library(ode_harmonic ode_harmonic.cpp)

target_include_directories(ode_harmonic PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_harmonic PUBLIC
    ode
)

# V THINGY OSCILLATION
add_library(ode_v_oscillation ode_v_oscillation.cpp)

target_include_directories(ode_v_oscillation PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_v_oscillation PUBLIC
    ode
)
