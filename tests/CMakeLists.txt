# Add an executable to the tests.

set(TESTS_PROJECT_NAME "${CMAKE_PROJECT_NAME}-tests")

set(INCLUDE_DIR
     ../src/imagine/core
     ../src/imagine/primitives
     ../src/imagine/utils
     ../src/imagine/mesh
   )

add_executable(
  ${TESTS_PROJECT_NAME}
  main.cpp
  test-interpolator.cpp
  test-coeffTable.cpp
  test-derivatives.cpp
  test-mesh.cpp
)

target_include_directories(${TESTS_PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
find_library(libimagine NAMES libimagine_lib.a PATHS ../build/debug/src/imagine)
target_link_libraries(${TESTS_PROJECT_NAME} PRIVATE ${libimagine} armadillo)
