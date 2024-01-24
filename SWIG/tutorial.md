# SWIG Installation and Usage Tutorial

SWIG (Simplified Wrapper and Interface Generator) is a software development tool that connects programs written in C and C++ with a variety of high-level programming languages. Here's a simple tutorial on how to install and use SWIG.

## Installation

```bash
sudo apt-get install swig
```

## Usage

1. Write your C/C++ code. For example, create a file named `example.c`:

    ```c++
    int getInt() {
        return 42;
    }
    ```

2. Create an interface file for SWIG. Name it `example.i`:

    ```c
    %module example
    %{
        extern int getInt();
    %}

    extern int getInt();
    ```

3. Use SWIG to create a wrapper. The `-python` flag is used to specify Python as the target language:

    ```bash
    swig -c++ -python example.i
    ```

4. This will generate two files: `example_wrap.c` (or `example_wrap.cxx` for C++) and `example.py`. Compile the C/C++ source code along with the SWIG wrapper, creating the file `_example.so`:

    ```bash
    g++ -fPIC -shared example.cpp example_wrap.cxx -o _example.so -I/usr/include/python3.6
    ```

5. Now you can use the C/C++ function in Python:

    ```python
    import example

    print(example.getInt())
    ```

## Executive Summary

SWIG works, but it generates a lot of files and (relatively) has a lot of steps. Also, [the author of SWIG isn't a fan.](https://code.activestate.com/lists/python-dev/109281). A good thing is that one of the files is the python package itself, which can be used in trace backs and documentation.
