/*
	This file is part of matlab-mex-cmake.

	matlab-mex-cmake is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	matlab-mex-cmake is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with matlab-mex-cmake.  If not, see <http://www.gnu.org/licenses/>.
*/

/**************************************************************************
  * @file    mex_stub.cpp
  * @author  Iuro Baptista Pereira Nascimento
  * @version V1.0.0
  * @date    22-May-2017
  * @brief   wrapper implementation
  * @warning 
***************************************************************************/

#include "mex.h"
#include "mex_main.h"
#include <time.h>
#include <thread>

/* static void at_exit(); */

void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    __mexFunction__(nlhs, plhs, nrhs, prhs);

}

