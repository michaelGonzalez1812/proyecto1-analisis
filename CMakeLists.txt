cmake_minimum_required(VERSION 3.9)
project(proyecto_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
set(SOURCE_FILES main.cpp)

find_package(Boost 1.66.0)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
else ()
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(proyecto1 main.cpp algorithms/rootMuller.h algorithms/LaguerreMethod.hpp algorithms/deflate.h algorithms/deflate.hpp algorithms/prueba.h algorithms/rootMuller.hpp)
    target_link_libraries(proyecto1 ${Boost_LIBRARIES})
endif ()