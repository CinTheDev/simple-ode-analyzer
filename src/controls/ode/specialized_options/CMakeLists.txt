add_library(controls_specialized controls_specialized.cpp)

target_include_directories(controls_specialized PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/specialized_options
)

target_link_libraries(controls_specialized PUBLIC
    ${wxWidgets_LIBRARIES}
)
