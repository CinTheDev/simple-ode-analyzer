# ENTRIES

add_library(ode_entry ode_entry.cpp)

target_include_directories(ode_entry PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

target_link_libraries(ode_entry PUBLIC
    ${wxWidgets_LIBRARIES}
    controls
)

target_link_libraries(ode_entry PRIVATE
    custom_events
)

add_subdirectory(ode_variants)

# ENTRY ADD DIALOG

add_library(entry_dialog entry_dialog.cpp)

target_include_directories(entry_dialog PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
)

target_link_libraries(entry_dialog PUBLIC
    ${wxWidgets_LIBRARIES}
)

# CHOOSER FOR ENTRIES

add_library(controls_choose controls_choose.cpp)

target_include_directories(controls_choose PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls/ode
)

target_link_libraries(controls_choose PUBLIC
    ${wxWidgets_LIBRARIES}
    controls
    ode_entry
    custom_events
)

target_link_libraries(controls_choose PRIVATE
    entry_dialog
    ode_variants # Temporary, shoudln't be required later on
)
