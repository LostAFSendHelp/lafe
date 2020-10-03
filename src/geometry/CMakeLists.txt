add_library(
    laf-geometry

    src/geometry.hpp
    src/geometry.cpp
    src/vertex.hpp
    src/vertex.cpp
)

target_link_libraries(laf-geometry PUBLIC glm)
target_include_directories(laf-geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
config_macros(laf-geometry)