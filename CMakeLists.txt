cmake_minimum_required(VERSION 3.5)
project(polynom_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(polynom_project main.cpp polynom.cpp polynom-list.cpp)

# Include directories for header files
include_directories(include)

# Add header files to the project
set(HEADER_FILES include/polynom.h include/polynom-list.h)
target_include_directories(polynom_project PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(polynom_project PRIVATE ${HEADER_FILES})
