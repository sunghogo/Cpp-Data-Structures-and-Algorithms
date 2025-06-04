cmake_minimum_required(VERSION 3.14)

project(dsa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all lessons subdirectories
file(GLOB CHILD_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/lessons lessons/*)

foreach(child ${CHILD_DIRS})
  if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lessons/${child}")
    add_subdirectory("lessons/${child}")
  endif()
endforeach()
