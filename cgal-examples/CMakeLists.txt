# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

project(Barycentric_coordinates_2_Examples)

cmake_minimum_required(VERSION 3.1)
find_package(CGAL QUIET)

if (CGAL_FOUND)

  # create a target per cppfile
  file(GLOB cppfiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
  foreach(cppfile ${cppfiles})
    create_single_source_cgal_program("${cppfile}")
  endforeach()

  set(directory /usr/local/Cellar/cgal-examples/Barycentric_coordinates_2)
  install(DIRECTORY DESTINATION ${directory})
  install(TARGETS Mean_value_coordinates_example DESTINATION ${directory})

else()
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
endif()
