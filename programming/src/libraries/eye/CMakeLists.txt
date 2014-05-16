add_library(eye SHARED eye.cpp)
target_link_libraries(eye eye ${OpenCV_LIBS})
