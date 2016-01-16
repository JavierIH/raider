add_library(compass SHARED compass.cpp)
target_link_libraries(compass compass i2c)
