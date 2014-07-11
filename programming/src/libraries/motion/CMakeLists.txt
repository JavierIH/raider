add_library(motion SHARED motion.cpp)
target_link_libraries(motion motion i2c)
