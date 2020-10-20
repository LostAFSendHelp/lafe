add_library(
    laf-ecs

    src/entity.hpp
    src/entity.cpp
    src/component.hpp
    src/component.cpp
    src/system.hpp
    src/system.cpp

    src/derived/translation.hpp
    src/derived/translation.cpp
    src/derived/rotation.hpp
    src/derived/rotation.cpp
    src/derived/spinning.hpp
    src/derived/spinning.cpp
    src/derived/cast_light.hpp
    src/derived/cast_light.cpp
)

target_link_libraries(laf-ecs PRIVATE laf-renderer laf-input laf-geometry laf-window glm)
target_include_directories(laf-ecs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
config_macros(laf-ecs)