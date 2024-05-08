add_library(controls STATIC controls.cpp)

target_include_directories(controls PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/controls
    ${CMAKE_SOURCE_DIR}/include/diffeq/common
)

target_link_libraries(controls PUBLIC
    ${wxWidgets_LIBRARIES}
)
