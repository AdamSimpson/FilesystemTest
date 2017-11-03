cmake_minimum_required(VERSION 3.8)
project(FilesystemTest)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(FilesystemTest ${SOURCE_FILES})

find_package(Boost COMPONENTS system filesystem  REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(FilesystemTest ${Boost_LIBRARIES})