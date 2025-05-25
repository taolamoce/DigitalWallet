cmake_minimum_required(VERSION 3.21)
project(DigitalWalletDemos)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(login main.cpp
  quenmk1.cpp
  hello1.cpp hello1.h hello1.ui
  dangnhap1.cpp dangnhap1.h dangnhap1.ui
  dangki1.cpp dangki1.h dangki1.ui
  quenmk1.cpp quenmk1.h quenmk1.ui
  otp.cpp otp.h otp.ui
  nhapmkcap2.cpp nhapmkcap2.h nhapmkcap2.ui
  taomkcap2.cpp taomkcap2.h taomkcap2.ui


  thietke.qrc
  nenchu.qrc
  123.qrc
  menu.h menu.cpp menu.ui
  picture/Dark_Purple.webp
  picture/troitoi.jpg
  doimk.h doimk.cpp doimk.ui
  giaodich.h giaodich.cpp giaodich.ui
  doimkbangotp.h doimkbangotp.cpp doimkbangotp.ui
  help1.h help1.cpp help1.ui
  tradeotp.h tradeotp.cpp tradeotp.ui
  historydialog.h historydialog.cpp historydialog.ui
  mkhauho.h mkhauho.cpp mkhauho.ui
  trogiupnguoidung.h trogiupnguoidung.cpp trogiupnguoidung.ui
  quanli.h quanli.cpp quanli.ui )
target_link_libraries(login PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  ${LIBRARY_TARGET_NAME}
  Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(login PROPERTIES
  MACOSX_BUNDLE TRUE
)
