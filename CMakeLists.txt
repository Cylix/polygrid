
###
# config
###
cmake_minimum_required(VERSION 2.8.1)
cmake_policy(SET CMP0042 NEW)

###
# verbose make
###
# set(CMAKE_VERBOSE_MAKEFILE TRUE)


###
# project
###
set(PROJECT polygrid)
project(${PROJECT} CXX)


###
# compilation options
###
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra")


###
# variables
###
set(DEPS_FOLDER ${PROJECT_SOURCE_DIR}/deps/build)

set(GTEST_INCLUDES ${DEPS_FOLDER}/gtest/include)
set(GTEST_LIBS ${DEPS_FOLDER}/gtest/lib)

set(OPENCV_INCLUDES ${DEPS_FOLDER}/opencv/include)
set(OPENCV_LIBS ${DEPS_FOLDER}/opencv/lib)

set(POLYGRID_INCLUDES ${PROJECT_SOURCE_DIR}/include)


###
# includes
###
include_directories(${POLYGRID_INCLUDES}
                    ${OPENCV_INCLUDES})


###
# link
###
link_directories(${OPENCV_LIBS})


###
# sources
###
set(DIRS "source" "source/**")
foreach(dir ${DIRS})
  # get directory sources
  file(GLOB s_${dir} "${dir}/*.cpp")
  # set sources
  set(SOURCES ${SOURCES} ${s_${dir}})
endforeach()


###
# executable
###
add_library(${PROJECT} SHARED ${SOURCES})
target_link_libraries(${PROJECT} opencv_core)
set_target_properties(${PROJECT}
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/target")


###
# install
###
install (TARGETS ${PROJECT} DESTINATION lib)
install (DIRECTORY ${POLYGRID_INCLUDES}/ DESTINATION include)


###
# tests
###
IF (BUILD_TESTS)
    add_subdirectory(tests)
ENDIF(BUILD_TESTS)
