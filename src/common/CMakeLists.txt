add_library(custom_events events.cpp)

target_include_directories(custom_events PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

target_link_libraries(custom_events PUBLIC
    ${wxWidgets_LIBRARIES}
)
