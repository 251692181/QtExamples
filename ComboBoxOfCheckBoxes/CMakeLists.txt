cmake_minimum_required(VERSION 2.6)

PROJECT(ComboBoxOfCheckBoxes)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

include_directories(${include_directories} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UISrcs main.ui)
QT4_WRAP_CPP(MOCSrcs main.h)

ADD_EXECUTABLE(ComboBoxOfCheckBoxes demo.cpp main.h main.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(ComboBoxOfCheckBoxes ${QT_LIBRARIES})

