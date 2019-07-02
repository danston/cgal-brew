# Created by the script cgal_create_cmake_script.
# This is the CMake script for compiling a CGAL application.

project(Shape_detection_Examples)

cmake_minimum_required(VERSION 2.8.10)
set(CMAKE_CXX_STANDARD 11)

find_package(CGAL QUIET COMPONENTS Core)
if(CGAL_FOUND)

  include(${CGAL_USE_FILE})
  include(CGAL_CreateSingleSourceCGALProgram)

  # Use Eigen.
  find_package(Eigen3 3.1.0 QUIET) # (3.1.0 or greater)
  if(EIGEN3_FOUND)
    include(${EIGEN3_USE_FILE})

    create_single_source_cgal_program(
      "region_growing_on_point_set_2.cpp")
  endif()

  set(directory /usr/local/Cellar/cgal-examples/Shape_detection)
  install(DIRECTORY DESTINATION ${directory})
  install(DIRECTORY DESTINATION ${directory}/data)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/point_set_2.xyz DESTINATION ${directory}/data)
  install(TARGETS region_growing_on_point_set_2 DESTINATION ${directory})

else()
  message(WARNING 
  "This program requires the CGAL library, and will not be compiled.")
endif()
