# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( timestwo )

cmake_minimum_required(VERSION 2.8.10)

# find_package(CGAL QUIET COMPONENTS Core )

# include( ${CGAL_USE_FILE} )
SET(MATLAB_ROOT "~/opt/MATLAB/R2016b")
set(CMAKE_CXX_STANDARD 11)
SET(MEX_SAVE_PATH "${CMAKE_SOURCE_DIR}")
set(FLAGS "-fPIC -DMX_COMPAT_32 -DMATLAB_MEX_FILE")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 ${FLAGS}")
set(WRAP "mex_stub")
set(WRAP_FILE "${WRAP}.cpp")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")

include_directories("${MATLAB_ROOT}/extern/include")
add_library(${PROJECT_NAME} timestwo.cpp)

add_library(${WRAP} OBJECT ${WRAP_FILE})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND mex  -L./  -l${PROJECT_NAME}  -output ${PROJECT_NAME} ${CMAKE_BINARY_DIR}/CMakeFiles/${WRAP}.dir/${WRAP_FILE}.o
)
# message("library_output_path: ${LIBRARY_OUTPUT_PATH}") 
# message("project_binary_dir: ${PROJECT_BINARY_DIR}") 
# message("project_source_dir: ${PROJECT_SOURCE_DIR}") 
# message("c++ flags: ${CMAKE_CXX_FLAGS}") 
# message("link flags: ${CMAKE_LINK_FLAGS}") 
# message("link libs: ${CMAKE_LINK_LIBRARIES}") 
# message("flags: ${CMAKE_FLAGS}") 

