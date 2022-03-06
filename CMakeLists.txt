cmake_minimum_required(VERSION 3.21.3)

# Project's name
project(imagine VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Variables to control the build process
option(PROJECT_BUILD_TESTS "Build the unit tests" OFF)

# Directory containing the executable
if(NOT PROJECT_BUILD_TESTS)
  add_subdirectory(src/${CMAKE_PROJECT_NAME})
  add_subdirectory(external/wxWidgets)

  target_include_directories(
    ${CMAKE_PROJECT_NAME}
    SYSTEM PUBLIC external/wxWidgets/include
  )
endif()

#Only build the tests if required
if(PROJECT_BUILD_TESTS)
  add_subdirectory(tests)
endif()

