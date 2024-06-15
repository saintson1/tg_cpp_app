
cmake_minimum_required(VERSION 3.0...3.2)

set(PROJECT_NAME tg_cpp_app)
set(SOURCE_DIR src)
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_GENERATOR_PLATFORM x64)

# include_directories(${PROJECT_SOURCE_DIR}/external/include)
# set(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/external/library)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)