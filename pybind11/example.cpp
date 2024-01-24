#include <pybind11/pybind11.h>

namespace py = pybind11;

int getInt() {
    return 42;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("getInt", &getInt, "A function which returns an int");
}