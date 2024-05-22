add_library(controls_view controls_view.cpp)

target_include_directories(controls_view PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/view
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

target_link_libraries(controls_view PUBLIC
    ${wxWidgets_LIBRARIES}
    controls
)

target_link_libraries(controls_view PRIVATE
    custom_events
)
