import cppyy

cppyy.include("example.cpp")

print(cppyy.gbl.getInt())
