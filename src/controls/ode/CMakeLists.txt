add_subdirectory(ode_chooser)

add_library(controls_ode controls_ode.cpp)

target_include_directories(controls_ode PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
)

target_link_libraries(controls_ode PUBLIC
    ${wxWidgets_LIBRARIES}
    custom_events
    controls
)
