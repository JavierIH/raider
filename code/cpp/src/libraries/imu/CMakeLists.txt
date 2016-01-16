add_library(imu SHARED imu.cpp)
target_link_libraries(imu imu i2c)
