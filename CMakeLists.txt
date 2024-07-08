
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

include_directories(${PROJECT_SOURCE_DIR}/external/includes)

set(DTd_DIR "X:/TGRKIT/LIB/tdlib/lib/cmake/Td")
find_package(Td 1.8.30 REQUIRED)

set(BOOST_ROOT "X:/TGRKIT/builds/boost")
set(BOOST_INCLUDEDIR "X:/TGRKIT/builds/boost/include/boost-1_85")
find_package(Boost COMPONENTS filesystem)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)

add_library(client STATIC ${SOURCE_DIR}/client/client.cpp)

add_library(file STATIC ${SOURCE_DIR}/tools/file/file.cpp)
add_library(json STATIC ${SOURCE_DIR}/tools/file/json/json.cpp)

add_library(auth STATIC ${SOURCE_DIR}/auth/auth.cpp)

target_link_libraries(client PRIVATE Td::TdJson)

target_link_libraries(json PRIVATE file)

target_link_libraries(${PROJECT_NAME} PRIVATE client)
target_link_libraries(${PROJECT_NAME} PRIVATE json)
target_link_libraries(${PROJECT_NAME} PRIVATE auth)
# target_link_libraries(${PROJECT_NAME} PRIVATE json)

if(Boost_FOUND)
  target_link_libraries(file PRIVATE ${Boost_LIBRARIES})
else()

endif()