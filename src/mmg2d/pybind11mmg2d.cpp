#include <pybind11/pybind11.h>
#include <iostream>

#include "libmmg2d.h"
#include "mmg2d.h"

namespace py = pybind11;

void toto( int tata ... ) {
  printf ("%d\n",tata);
}

void generic(py::args args) {
  /// .. do something with args
  if (args) {
    int first_arg = py::cast<int>(args[0]);

    printf ( "%d\n",first_arg );
    // std::cout << "first_arg" << first_arg << std::endl;
    // va_start(argptr, first_arg);

   // int ier = MMG3D_Init_mesh(std::for_each(args.begin(), args.end()){args});

    // va_end(args.end());

    //MMG2D_Init_mesh(args.get<0>(); *args);
  }
}


PYBIND11_MODULE(mmg, m) {
  m.doc() = "Mmg provides simplicial mesh adaptation (2D, 3D and surfacic)";

  //m.def("MMG2D_Init_mesh", &MMG2D_Init_mesh, "Allocations of 2d data structure");
  m.def("generic", &generic,"blabla");
  //m.def("toto",&toto,"blibli");

  m.def("MMG2D_loadMesh", &MMG2D_loadMesh, "load mesh");
  m.def("MMG2D_saveMesh", &MMG2D_saveMesh, "save mesh");
}


/// Binding code
