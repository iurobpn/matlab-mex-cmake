# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( timestwo )

cmake_minimum_required(VERSION 2.8.10)

# find_package(CGAL QUIET COMPONENTS Core )

# include( ${CGAL_USE_FILE} )

set(CMAKE_CXX_STANDARD 11)
SET(MEX_SAVE_PATH "${CMAKE_SOURCE_DIR}")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -std=c99 -DMX_COMPAT_32 -DMATLAB_MEX_FILE")
SET_DIRECTORY_PROPERTIES(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${MEX_SAVE_PATH}/${PROJECT_NAME}.mexa64;mex_stub.o")

# add_custom_target(timestwo mex SOURCES timestwo.c)
include_directories("/home/gagarin/opt/MATLAB/R2016b/extern/include")
add_library(${PROJECT_NAME} timestwo.c)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${PROJECT_SOURCE_DIR}/mex_link.sh ${PROJECT_NAME} ${MEX_SAVE_PATH}
)

