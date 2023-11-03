## QCustomPlot fetch with cmake

`qcustomplot-fetch` is a tool that allows you to obtain the QCustomPlot library from the official website using CMake
during project configuration. This project simplifies the process of downloading and integrating QCustomPlot, making it
more convenient and automated.

### Installation

To start using QCustomPlot-Fetch, follow these steps:

1. Add the QCustomPlot-Fetch repository as a submodule in your project using the `add_subdirectory` command:
   ```cmake
   add_subdirectory(qcustomplot-fetch)
   ```

2. If you want to specify the desired version of QCustomPlot, set the `QCUSTOMPLOT_VERSION` variable:
   ```cmake
   set(QCUSTOMPLOT_VERSION "2.1.1")
   ```
   or
   ```bash
   cmake -DQCUSTOMPLOT_VERSION="2.1.1" .
   ```
   Alternatively, you can specify the url for downloading QCustomPlot entirely through the `QCUSTOMPLOT_URL` variable.

3. If you need demonstration examples, set the `QCUSTOMPLOT_DEMO` variable:
   ```cmake
   set(QCUSTOMPLOT_DEMO ON)
   ```
   You can find examples in the `demo` directory.

### Usage Example
A CMake example for your project:

```cmake
cmake_minimum_required(VERSION 3.21)
project(MyProject)

# Set the desired QCustomPlot version
set(QCUSTOMPLOT_VERSION "2.1.1")

# Add qcustomplot-fetch as a submodule
add_subdirectory(qcustomplot-fetch)

# Add your target and link it with QCustomPlot
add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE qcustomplot)
```
