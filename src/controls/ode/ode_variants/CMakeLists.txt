# GENERIC HARMONIC OSCILLATION
add_library(ode_oscillation_harmonic ode_oscillation_harmonic.cpp)

target_include_directories(ode_oscillation_harmonic PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_oscillation_harmonic PUBLIC
    ode
)

# MECHANICAL HARMONIC OSCILLATION
add_library(ode_oscillation_harmonic_mechanical ode_oscillation_harmonic_mechanical.cpp)

target_include_directories(ode_oscillation_harmonic_mechanical PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_oscillation_harmonic_mechanical PUBLIC
    ode_oscillation_harmonic
)

# ELECTROMAGNETIC HARMONIC OSCILLATION
add_library(ode_oscillation_harmonic_electromagnetic ode_oscillation_harmonic_electromagnetic.cpp)

target_include_directories(ode_oscillation_harmonic_electromagnetic PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_oscillation_harmonic_electromagnetic PUBLIC
    ode_oscillation_harmonic
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
    ode_oscillation_harmonic_mechanical
    ode_oscillation_harmonic_electromagnetic
    ode_oscillation_gravitational
    PARENT_SCOPE
)
