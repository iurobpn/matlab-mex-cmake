# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( timestwo )

cmake_minimum_required(VERSION 2.8.10)

# find_package(CGAL QUIET COMPONENTS Core )

# include( ${CGAL_USE_FILE} )
SET(MATLAB_ROOT "~/opt/MATLAB/R2016b")
set(CMAKE_CXX_STANDARD 11)
SET(MEX_SAVE_PATH "${CMAKE_SOURCE_DIR}")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -std=c99 -DMX_COMPAT_32 -DMATLAB_MEX_FILE")
SET(MEX_FLAGS "-g -cxx CC='gcc' CXX='gcc' LD='gcc'")
SET(MEX_LIBS "-lpthread -lgthread-2.0 -lrt -lglib-2.0")

# add_custom_target(timestwo mex SOURCES timestwo.c)
include_directories("${MATLAB_ROOT}/extern/include")

add_library(${PROJECT_NAME} timestwo.c)

add_library(mex_stub OBJECT mex_stub.c)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND mex  -L./  -l${PROJECT_NAME}  -output ${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/CMakeFiles/mex_stub.dir/mex_stub.c.o
)
