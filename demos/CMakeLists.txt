find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui Widgets REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(DigitalWalletDemos)
# add_subdirectory(demo2)
# add_subdirectory(demo3)
# add_subdirectory(demo4)
