set(CPP_FILES_LIB
     math/interpolation.cpp
     math/coefficients.cpp
   )

set(CPP_FILES_ALL
     ${CMAKE_CURRENT_SOURCE_DIR}
     gui/main.cpp
   )

SET(INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/math
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
   )

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
  ${CPP_FILES_ALL}
)

# Library used for unit tests
add_library(
  ${CMAKE_PROJECT_NAME}_lib
  ${CPP_FILES_LIB}
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE wx::net wx::core wx::base X11)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_COMP_FLAGS})
target_compile_options(${CMAKE_PROJECT_NAME}_lib PUBLIC ${EXTRA_COMP_FLAGS})

