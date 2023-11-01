## QCustomPlot fetch with cmake
QCustomPlot-Fetch is a tool that allows you to obtain the QCustomPlot library from the official website using CMake during project configuration. This project simplifies the process of downloading and integrating QCustomPlot, making it more convenient and automated.

### Installation
To start using QCustomPlot-Fetch, follow these steps:

1. Add the QCustomPlot-Fetch repository as a submodule in your project using the `add_subdirectory` command:
```cmake
    add_subdirectory(qcustomplot-fetch)
```

2. By default, the `QCUSTOMPLOT_LIB_TARGET` option is enabled, which means that QCustomPlot will be built as a library and made available as a target for linking. 
   
   If you want to specify the desired version of QCustomPlot, set the `QCUSTOMPLOT_VERSION` variable:
```cmake
set(QCUSTOMPLOT_VERSION "2.1.1")
```
Alternatively, you can specify the URL for downloading QCustomPlot entirely through the QCUSTOMPLOT_URL variable.

Call the qcustomplot_attach function and provide the name of the target to which you want to attach the QCustomPlot source files:

cmake

qcustomplot_attach(<target_name>)

This function is always available and allows you to integrate the QCustomPlot source files into your project without the need to build it as a library.

If you need demonstration examples, set the QCUSTOMPLOT_DEMO variable:

cmake

    set(QCUSTOMPLOT_DEMO ON)

    You can find examples in the demo directory.

Usage Example

A CMake example for your project:

cmake

cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Add QCustomPlot-Fetch as a submodule
add_subdirectory(qcustomplot-fetch)

# The QCUSTOMPLOT_LIB_TARGET option is enabled by default, QCustomPlot will be built as a library

# Set the desired QCustomPlot version
set(QCUSTOMPLOT_VERSION "2.1.1")

# Add your executable file and link it with QCustomPlot
add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE qcustomplot)

Or integration without building the QCustomPlot library:

cmake

cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Add QCustomPlot-Fetch as a submodule
add_subdirectory(qcustomplot-fetch)

# Attach the QCustomPlot source files to your project
qcustomplot_attach(my_target)

# Add your executable file and link it with the target to which QCustomPlot is attached
add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE my_target)