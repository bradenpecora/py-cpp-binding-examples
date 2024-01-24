# cppyy tutorial

## Installation

Install via pip

```bash
pip install cppyy
```

Install via conda-forge

```bash
conda install -c conda-forge cppyy
```

## Write C++ code

```cpp
int getInt() {
    return 42;
}
```

## Write python code to call C++ function

```python
import cppyy

cppyy.include("example.cpp")

print(cppyy.gbl.getInt())

```

## Notes

- Had to adjust the library CMakeLists.txt such that a dynamic library was created
- Can't see documentation on hover or have Pylance check for errors, etc. since it is a dynamic import
