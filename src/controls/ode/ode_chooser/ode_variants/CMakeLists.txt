add_library(ode_variants
    ode_oscillation_harmonic.cpp
)

target_include_directories(ode_variants PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_chooser/ode_variants
)

target_link_libraries(ode_variants PUBLIC
    ${wxWidgets_LIBRARIES}
    ode_entry
)
