cmake_minimum_required(VERSION 3.25)
project(MultiHorror)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR "libs/SDL2_base/lib/cmake/SDL2")
set(SDL2_image_DIR "libs/SDL2_image/lib/cmake/SDL2_image")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_image_INCLUDE_DIRS})
add_executable(MultiHorror main.cpp includes/ScreenManager.cpp includes/ScreenManager.h includes/Vector2f.cpp includes/Vector2f.h includes/Window.cpp includes/Window.h includes/Window.cpp includes/Player.h includes/Player.cpp includes/RectBlock.h includes/Rect.h includes/Rect.cpp includes/RectBlock.cpp includes/Wall.h includes/Wall.cpp)


set_target_properties(MultiHorror PROPERTIES
        WIN32_EXECUTABLE FALSE
        )
target_link_libraries(MultiHorror ${SDL2_LIBRARIES})
target_link_libraries(MultiHorror SDL2_image::SDL2_image)