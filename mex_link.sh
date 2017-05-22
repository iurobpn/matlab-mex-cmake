#!/bin/sh

OUTPUT=$1
STATIC_LIB_NAME=$OUTPUT
MOVE_LOCATION=$2
LINKER_FLAGS=
INCDIR=

echo 'Running godawful mex linking hack...'
# mex_stub.o compiled with:
gcc -g -Wall -fPIC -std=c99 -pthread -DMX_COMPAT_32 -DMATLAB_MEX_FILE -I/home/gagarin/opt/MATLAB/R2016b/extern/include -c ../mex_stub.c -o mex_stub.o
mex -g -cxx CC='gcc' CXX='gcc' LD='gcc' -L./ -lpthread -lgthread-2.0 -lrt -lglib-2.0 -l$STATIC_LIB_NAME $LINKER_FLAGS -output $OUTPUT mex_stub.o
mv $OUTPUT.mexa64 $MOVE_LOCATION
