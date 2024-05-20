# ODE STUFF

add_library(ode ode.cpp)

target_include_directories(ode PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

add_subdirectory(ode_variants)

# ODE CONTROLS

add_subdirectory(specialized_options)

add_library(controls_ode controls_ode.cpp)

target_include_directories(controls_ode PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
)

target_link_libraries(controls_ode PUBLIC
    ${wxWidgets_LIBRARIES}
    controls
    controls_specialized
    ode
)

target_link_libraries(controls_ode PRIVATE
    custom_events
    ode_harmonic
    ode_v_oscillation
)
