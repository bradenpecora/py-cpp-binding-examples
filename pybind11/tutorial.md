# pybind11 tutorial

## Step1: Install pybind11

Install via pip

```bash
pip install pybind11
```

Install via conda-forge

```bash
conda install -c conda-forge pybind11
```

Then install python-dev

```bash
sudo apt-get install python3-dev
```

## Write your C++ code

```cpp
#include <pybind11/pybind11.h>

namespace py = pybind11;

int getInt() {
    return 42;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("getInt", &getInt, "A function which returns an int");
}
```

and compile it, changing included python path accordingly:

```bash
c++ -O3 -Wall -shared -fPIC -std=c++11 -I/home/braden/miniconda3/envs/test/include/python3.12 -I $(python -m pybind11 --includes) example.cpp -o example.so
```

## Call using Python

```python
import example

print(example.getInt())
>>> 42
```

## Executive Summary

I didn't look at how to tie this to a larger library. It may be complicated. Adjusting C++ code is required.
Intellisense will raise an error in every file.
