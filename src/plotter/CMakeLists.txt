add_subdirectory(ode)

add_library(plotter STATIC plotter.cpp)

target_include_directories(plotter PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/plotter
)

target_link_libraries(plotter PUBLIC
    ${wxWidgets_LIBRARIES}
    custom_events
)

target_link_libraries(plotter PRIVATE
    ode
)
