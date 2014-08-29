add_library(eye SHARED eye.cpp)
target_link_libraries(eye eye debuga ${OpenCV_LIBS} ${ZBAR_LIBRARIES}zbar)
