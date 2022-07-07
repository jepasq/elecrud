cmake_minimum_required(VERSION 3.0)

project(elecrud VERSION 0.0.0)
set(REVISION 1)

configure_file(
  "${PROJECT_SOURCE_DIR}/Doxyfile.in"
  "${PROJECT_BINARY_DIR}/Doxyfile"
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(FindPkgConfig)
pkg_check_modules(LIBS REQUIRED fox>=1.6)

# Shared both main rule and unit tests editor sources
# Do not contain main.cpp to avoid multiple definitions of main()
set(EDITOR_SRC
  src/editor/Elecrud.cpp
  src/editor/MainWindow.cpp
)
add_executable(elecrud src/editor/main.cpp ${EDITOR_SRC}) 
target_link_libraries(elecrud ${LIBS_LIBRARIES})
target_include_directories(elecrud PUBLIC ${SDL2_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR})

# Unit tests
find_package(Boost COMPONENTS unit_test_framework REQUIRED) # filesystem system 
add_executable(tests src/tests.cpp
  ${EDITOR_SRC}
  src/editor/MainWindow_Test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES} ${LIBS_LIBRARIES})
add_custom_target(check COMMAND tests) # Add the `make check` command
