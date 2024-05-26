add_library(ode_variants
    ode_function.cpp
    ode_oscillation_harmonic.cpp
    ode_oscillation_harmonic_mechanical.cpp
    ode_oscillation_harmonic_electromagnetic.cpp
    ode_oscillation_gravitational.cpp
    ode_oscillation_pendulum.cpp
)

target_include_directories(ode_variants PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_variants
)

target_link_libraries(ode_variants PUBLIC
    ${wxWidgets_LIBRARIES}
    ode_entry
)
