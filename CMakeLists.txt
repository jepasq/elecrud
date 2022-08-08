cmake_minimum_required(VERSION 3.0)

project(elecrud VERSION 0.0.0)
set(REVISION 2)

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

find_package(Boost COMPONENTS serialization REQUIRED)

# Shared both main rule and unit tests editor sources
# Do not contain main.cpp to avoid multiple definitions of main()
set(EDITOR_SRC
  src/editor/Elecrud.cpp
  src/editor/MainWindow.cpp
)

# File library
add_library(elecrud-file SHARED
  src/libfile/ProjectFile.cpp)
target_link_libraries(elecrud-file PUBLIC ${Boost_LIBRARIES})


add_executable(elecrud src/editor/main.cpp ${EDITOR_SRC}) 
target_link_libraries(elecrud ${Boost_LIBRARIES} ${LIBS_LIBRARIES} elecrud-file)

target_include_directories(elecrud PUBLIC ${SDL2_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR} src)

# Unit tests
find_package(Boost COMPONENTS unit_test_framework serialization REQUIRED) # filesystem system 
add_executable(tests src/tests.cpp
  ${EDITOR_SRC}
  src/libfile/ProjectFile_Test.cpp
  
  src/editor/MainWindow_Test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES} ${LIBS_LIBRARIES} elecrud-file)
target_include_directories(tests PUBLIC ${SDL2_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR} src)
add_custom_target(check COMMAND tests) # Add the `make check` command

# Reswrap command to handle FX icons
set(ICONS
  ../media/icons/new_gif.gif
  ../media/icons/open_gif.gif
  )
add_custom_command(OUTPUT icons.hpp
  MAIN_DEPENDENCY ${ICONS}
  COMMAND reswrap -o icons.hpp ${ICONS}
  COMMENT "Handling icons with `reswrap` FX tool"
  )
add_custom_target(run ALL DEPENDS icons.hpp)
