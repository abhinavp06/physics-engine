cmake_minimum_required(VERSION 3.23)
project(appe)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SDL3_DIR external/SDL3/cmake)

find_package(SDL3 REQUIRED CONFIG)

add_executable(appe src/main.cpp)

target_include_directories(appe PUBLIC include)
target_link_libraries(appe PRIVATE SDL3::SDL3)

add_custom_command(TARGET appe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_RUNTIME_DLLS:appe>
    $<TARGET_FILE_DIR:appe>
    COMMAND_EXPAND_LISTS
)