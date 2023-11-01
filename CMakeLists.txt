cmake_minimum_required(VERSION 3.21)
project(qcustomplot)


# tuning variables
option(QCUSTOMPLOT_LIB_TARGET "Define and build target qcustomplot" ON)
option(QCUSTOMPLOT_DEMO "qcustomplot build demo" ${PROJECT_IS_TOP_LEVEL})
set(QCUSTOMPLOT_VERSION 2.1.1 CACHE STRING "")
set(QCUSTOMPLOT_URL "https://www.qcustomplot.com/release/${QCUSTOMPLOT_VERSION}/QCustomPlot-source.tar.gz" CACHE STRING "")
set(QT_VERSION 5 CACHE STRING "")
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")


# internal variable
set(QCUSTOMPLOT_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/qcustomplot-src")
set(QCUSTOMPLOT_SOURCE_DIR "${QCUSTOMPLOT_INCLUDE_DIR}/qcustomplot")


include(FetchContent)
FetchContent_GetProperties(qcustomplot)
if(NOT qcustomplot_POPULATED)
  # https://github.com/ethereum/solidity/compare/e4f49e09823c484bd11d22a4b37181a43f202abd..4159d13a996d8b376ae33f2be58b9651269daee4
  # Avoid warnings in CMake 3.24.0:
  if(CMAKE_VERSION VERSION_GREATER "3.24.0")
    cmake_policy(SET CMP0135 NEW)
  endif()
  FetchContent_Populate(qcustomplot
    URL "${QCUSTOMPLOT_URL}"
    SOURCE_DIR "${QCUSTOMPLOT_SOURCE_DIR}"
    )


  # attach function
  function(qcustomplot_attach target)
    target_sources(${target} PRIVATE
      "${QCUSTOMPLOT_SOURCE_DIR}/qcustomplot.h"
      "${QCUSTOMPLOT_SOURCE_DIR}/qcustomplot.cpp"
      )

    target_include_directories(${target}
      PUBLIC
      "${QCUSTOMPLOT_INCLUDE_DIR}"
      PRIVATE
      "${QCUSTOMPLOT_SOURCE_DIR}"
      )
  endfunction()


  if(QCUSTOMPLOT_LIB_TARGET)
    add_library(qcustomplot)
    qcustomplot_attach(qcustomplot)

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
  endif()
endif()


if(QCUSTOMPLOT_DEMO)
  add_subdirectory(demo/as_attach)
  add_subdirectory(demo/as_target)
endif()
