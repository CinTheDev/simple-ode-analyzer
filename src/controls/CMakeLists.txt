add_library(controls controls.cpp)

target_include_directories(controls PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls
)

target_link_libraries(controls PUBLIC
    ${wxWidgets_LIBRARIES}
)

add_subdirectory(view)
add_subdirectory(ode)

add_library(controls_panel STATIC controls_panel.cpp)

target_include_directories(controls_panel PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

target_link_libraries(controls_panel PUBLIC
    ${wxWidgets_LIBRARIES}
    controls_view
    controls_choose
    custom_events
)
