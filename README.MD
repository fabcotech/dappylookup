# Co-resolution c++

C++ implementation of co-resolution used in dappy, with only two dependencies `libcurl` and `base64`.

Unlike the javascript implementation, this repository has no abstraction layer, it has a straightforward strructure, and assumes you want to resolve (with co-resolution) A / CERT / TXT records on a dappy network, `request.cpp` is the file to edit if you wish to co-resolve other kind of resources.

Building the repository.

```
# https://docs.conan.io/en/latest/getting_started.html
mkdir build && cd build
conan install ..
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make
```

Do co-resolution (/hash route for now)
```
./bin/cores
./bin/cores --debug
```