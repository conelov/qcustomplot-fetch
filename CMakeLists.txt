cmake_minimum_required(VERSION 3.11)


# tuning variables
option(QCUSTOMPLOT_DEMO "qcustomplot build demo" OFF)
set(QCUSTOMPLOT_VERSION 2.1.1 CACHE STRING "")
set(QCUSTOMPLOT_URL "https://www.qcustomplot.com/release/${QCUSTOMPLOT_VERSION}/QCustomPlot-source.tar.gz" CACHE STRING "")
set(QT_VERSION 5 CACHE STRING "")
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")


project(qcustomplot LANGUAGES CXX VERSION ${QCUSTOMPLOT_VERSION})

# https://github.com/ethereum/solidity/compare/e4f49e09823c484bd11d22a4b37181a43f202abd..4159d13a996d8b376ae33f2be58b9651269daee4
# Avoid warnings in CMake 3.24.0:
if(CMAKE_VERSION VERSION_GREATER "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(qcustomplot
  URL "${QCUSTOMPLOT_URL}"
  )
FetchContent_MakeAvailable(qcustomplot)

add_library(qcustomplot
  "${qcustomplot_SOURCE_DIR}/qcustomplot.h"
  "${qcustomplot_SOURCE_DIR}/qcustomplot.cpp"
  )

target_include_directories(qcustomplot PUBLIC
  "${qcustomplot_SOURCE_DIR}"
  )

set(Qt5Libs Core Widgets PrintSupport)
# set(Qt6Libs ...)
find_package(Qt${QT_VERSION} COMPONENTS ${Qt${QT_VERSION}Libs} REQUIRED)
foreach(i IN LISTS Qt${QT_VERSION}Libs)
  target_link_libraries(qcustomplot PRIVATE
    Qt${QT_VERSION}::${i}
    )
endforeach()

set_target_properties(qcustomplot PROPERTIES
  AUTOMOC ON
  )


if(QCUSTOMPLOT_DEMO)
  add_subdirectory(demo)
endif()
