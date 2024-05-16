# ODE STUFF

add_library(ode ode.cpp)

target_include_directories(ode PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

# TODO: Remove this
target_link_libraries(ode PRIVATE
    m
)

add_subdirectory(ode_variants)

# ODE CONTROLS

add_library(controls_ode controls_ode.cpp)

target_include_directories(controls_ode PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
)

target_link_libraries(controls_ode PUBLIC
    ${wxWidgets_LIBRARIES}
    ode
)

target_link_libraries(controls_ode PRIVATE
    custom_events
    ode_harmonic
)
