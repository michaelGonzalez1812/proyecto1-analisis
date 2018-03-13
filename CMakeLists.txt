cmake_minimum_required(VERSION 3.9)
project(proyecto_1)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "/usr/local/boost_1_66_0")
set(BOOSTROOT "/usr/local/boost_1_66_0")
set(SOURCE_FILES main.cpp def.cpp)

find_package(Boost 1.66.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
else()
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(BoostTest main.cpp)
    target_link_libraries(BoostTest ${Boost_LIBRARIES})
endif()

add_executable(proyecto_1 main.cpp def.cpp def.h)