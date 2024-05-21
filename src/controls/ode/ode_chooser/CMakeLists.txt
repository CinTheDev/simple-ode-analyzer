# ENTRIES

add_library(ode_entry ode_entry.cpp)

target_include_directories(ode_entry PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_chooser
)

target_link_libraries(ode_entry PUBLIC
    ${wxWidgets_LIBRARIES}
)

# CHOOSER FOR ENTRIES

add_library(controls_choose controls_choose.cpp)

target_include_directories(controls_choose PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode/ode_chooser
)

target_link_libraries(controls_choose PUBLIC
    ${wxWidgets_LIBRARIES}
    controls
    ode_entry
)
