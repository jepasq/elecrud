cmake_minimum_required(VERSION 3.0)

project(elecrud VERSION 0.0.2)
set(REVISION 14)

configure_file(
  "${PROJECT_SOURCE_DIR}/Doxyfile.in"
  "${PROJECT_BINARY_DIR}/Doxyfile"
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(FindPkgConfig)
pkg_check_modules(LIBS REQUIRED fox>=1.6)

# Shared both main rule and unit tests editor sources
# Do not contain main.cpp to avoid multiple definitions of main()
set(EDITOR_SRC
  src/editor/Elecrud.cpp
  src/editor/Generator.cpp
  src/editor/GeneratorV1.cpp
  src/editor/MainWindow.cpp
)

# File library
add_library(elecrud-file SHARED
  src/libfile/ProjectFile.cpp)
target_link_libraries(elecrud-file PUBLIC ${Boost_LIBRARIES})
target_include_directories(elecrud-file PUBLIC ${LIBS_INCLUDE_DIRS})

# Executable
add_executable(elecrud src/editor/main.cpp ${EDITOR_SRC}) 
target_link_libraries(elecrud ${Boost_LIBRARIES} ${LIBS_LIBRARIES}
  elecrud-file stdc++fs)
target_include_directories(elecrud PUBLIC ${SDL2_INCLUDE_DIRS}
  ${LIBS_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}
  src
  src/libfile)
add_dependencies(elecrud icons)

# Unit tests
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(tests src/tests.cpp
  ${EDITOR_SRC}
  src/libfile/ProjectFile_Test.cpp
  
  src/editor/Generator_Test.cpp
  src/editor/GeneratorV1_Test.cpp
  src/editor/MainWindow_Test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES} ${LIBS_LIBRARIES}
  elecrud-file stdc++fs)
target_include_directories(tests PUBLIC ${SDL2_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR} src src/libfile)
add_custom_target(check COMMAND tests DEPENDS icons)

# Reswrap command to handle FX icons
set(ICONS
  ../media/icons/new_gif.gif
  ../media/icons/open_gif.gif
  ../media/icons/project_big.gif
  ../media/icons/coll_big.gif
  ../media/icons/gen_big.gif
  ../media/icons/log_big.gif
  )
add_custom_command(OUTPUT icons.hpp
  MAIN_DEPENDENCY ${ICONS}
  COMMAND reswrap -o icons.hpp ${ICONS}
  COMMENT "Handling icons with `reswrap` FX tool"
  )
add_custom_target(icons ALL DEPENDS icons.hpp)

