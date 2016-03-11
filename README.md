# Polygrid

Polygrid is a solution to a problematic I've encountered: how to provide fast handling of polygons (matching, merging, splitting, ...) by keeping as much accuracy as possible.

The main issue concerning polygons is that most mathematical algorithms to handle them are time consuming and are not appropriate for real-time software applications.

My solution is simple: building a simple grid over the polygon and use this grid to apply operations such as matching, merging or splitting instead of using the polygon directly.
This solution provides very fast operations and make it easy to trade-off between accuracy and performance by increasing or decreasing grid cells' size.

Still under development.

## Requirements
* C++11

## Compiling
The library uses `cmake`. In order to build the library, follow these steps:

```bash
git clone https://github.com/Cylix/polygrid.git
cd polygrid
./install_deps.sh # necessary only for building tests
mkdir build
cd build
cmake .. # only library
cmake .. -DBUILD_TESTS=true # library and tests
make -j
```

If you want to install the library in a specific folder:

```bash
cmake -DCMAKE_INSTALL_PREFIX=/destination/path ..
make install -j
```

Then, you just have to include `<polygrid/polygrid>` in your source files and link the `polygrid` library with your project.

To build the tests, it is necessary to install `google_tests`. Just run the `install_deps.sh` script which does the work for you.

## Author
[Simon Ninon](http://simon-ninon.fr)
