#  ____     _    ___ ____  _____ ____  
# |  _ \   / \  |_ _|  _ \| ____|  _ \ 
# | |_) | / _ \  | || | | |  _| | |_) |
# |  _ < / ___ \ | || |_| | |___|  _ < 
# |_| \_/_/   \_|___|____/|_____|_| \_\
#
                                      

project(raider2)

cmake_minimum_required(VERSION 2.6)
find_package( OpenCV REQUIRED )

set(TRUNK_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(RAIDER_BIN_DIR "${TRUNK_DIR}/build/bin")
set(RAIDER_TESTS_DIR "${TRUNK_DIR}/build/tests")
set(RAIDER_LIBS_DIR "${TRUNK_DIR}/build/lib")

set(LIBRARY_OUTPUT_PATH ${RAIDER_LIBS_DIR})
set(EXECUTABLE_OUTPUT_PATH ${RAIDER_BIN_DIR})
set(TEST_OUTPUT_PATH ${RAIDER_TESTS_DIR})

add_subdirectory(src)


