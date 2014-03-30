add_library(mpu9150 SHARED mpu9150.c)
add_library(quaternion SHARED quaternion.c)
add_library(vector3d SHARED vector3d.c)

target_link_libraries(mpu9150 linux_glue)



