project(qcustomplot_demo_as_attach)


find_package(Qt${QT_VERSION} COMPONENTS Core Widgets PrintSupport REQUIRED)


add_executable(${PROJECT_NAME}
  main.cpp
  )

qcustomplot_attach(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt${QT_VERSION}::Core
  Qt${QT_VERSION}::Widgets
  Qt${QT_VERSION}::PrintSupport
  )

set_target_properties(${PROJECT_NAME} PROPERTIES
  AUTOMOC ON
  )
