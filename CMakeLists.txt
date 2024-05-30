cmake_minimum_required(VERSION 3.26.2)

project(raytracer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG 35b1148efb839381b84de9290d9caf0b66ad7d03
)

FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml
  GIT_TAG 82dc2033e51b8323857c3ae1cf1f458b3a933c35
)

message(STATUS "Fetching ImGui-SFML...")

set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)

FetchContent_MakeAvailable(imgui-sfml)


find_package(SFML 2.5 COMPONENTS graphics audio system REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories(include)

add_compile_options(-O3 -g3 -ggdb)

add_executable(raytracer ${SOURCES})

target_link_libraries(raytracer sfml-graphics sfml-audio sfml-system config++ ImGui-SFML::ImGui-SFML)

add_compile_options(-O3 -ggdb -g3)
