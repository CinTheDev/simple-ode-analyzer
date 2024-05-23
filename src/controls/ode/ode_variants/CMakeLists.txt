# HARMONIC OSCILLATION
add_library(ode_oscillation_harmonic ode_oscillation_harmonic.cpp)

target_include_directories(ode_oscillation_harmonic PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_oscillation_harmonic PUBLIC
    ode
)

# V THINGY OSCILLATION
add_library(ode_oscillation_gravitational ode_oscillation_gravitational.cpp)

target_include_directories(ode_oscillation_gravitational PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_oscillation_gravitational PUBLIC
    ode
)

set(DIFFEQ_ALL_ODE_VARIANTS
    ode_oscillation_harmonic
    ode_oscillation_gravitational
    PARENT_SCOPE
)
