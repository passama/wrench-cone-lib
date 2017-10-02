/*      File: PyCWC.h
*       This file is part of the program WrenchConeLib
*       Program description : This library implements the Contact Wrench Cone as given [here](https://scaron.info/papers/journal/caron-tro-2016.pdf). It uses cdd for the polyhedron computation and Eigen for the matrix part. Python bindings are also available.
*       Copyright (C) 2017 -  vsamy (LIRMM). All Right reserved.
*
*       This software is free software: you can redistribute it and/or modify
*       it under the terms of the CeCILL-C license as published by
*       the CEA CNRS INRIA, either version 1
*       of the License, or (at your option) any later version.
*       This software is distributed in the hope that it will be useful,
*       but WITHOUT ANY WARRANTY without even the implied warranty of
*       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*       CeCILL-C License for more details.
*
*       You should have received a copy of the CeCILL-C License
*       along with this software. If not, it can be found on the official website
*       of the CeCILL licenses family (http://www.cecill.info/index.en.html).
*/
#include "PyContactSurface.h"
#include <WrenchConeLib/CWC.h>
#include <boost/python/numpy.hpp>

namespace py = boost::python;
namespace np = boost::python::numpy;

namespace wcl {

struct PyCWC : public CWC {

    PyCWC(const np::ndarray& com, const PyContactSurface& py_pCS);
    PyCWC(const np::ndarray& com, const py::list& py_pCSs);

    np::ndarray getPyRays();
    np::ndarray getPyHalfSpaces();

private:
    np::ndarray buildNumpyArray(const Eigen::MatrixXd& mat);
};

void bindCWC();

} // namespace wcl