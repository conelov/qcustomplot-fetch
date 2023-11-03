project(qcustomplot_demo)


find_package(Qt${QT_VERSION} COMPONENTS Core Widgets REQUIRED)


add_executable(${PROJECT_NAME}
  main.cpp
  )

target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt${QT_VERSION}::Core
  Qt${QT_VERSION}::Widgets
  qcustomplot
  )
