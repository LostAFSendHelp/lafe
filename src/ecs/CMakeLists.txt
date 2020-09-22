add_library(
    laf-ecs

    src/entity.hpp
    src/entity.cpp
    src/component.hpp
    src/component.cpp
    src/system.hpp
    src/system.cpp

    src/derived/movement.hpp
    src/derived/movement.cpp
)

target_link_libraries(laf-ecs PUBLIC laf-renderer laf-input)
target_include_directories(laf-ecs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)