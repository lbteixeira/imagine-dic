set(CPP_FILES
     math/interpolation.cpp
     main.cpp
   )

SET(INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/math)

set(EXTRA_COMP_FLAGS
     -Werror
     -Wall
     -Wextra
     -pedantic-errors
     -Wconversion
     -Wsign-conversion
   )

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${CPP_FILES}
)

# Library used for unit tests
add_library(
  ${CMAKE_PROJECT_NAME}_lib
  ${CPP_FILES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_COMP_FLAGS})
target_compile_options(${CMAKE_PROJECT_NAME}_lib PUBLIC ${EXTRA_COMP_FLAGS})

