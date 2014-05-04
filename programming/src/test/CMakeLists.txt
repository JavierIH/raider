OPTION(TEST1 "Communication test" 1)
IF (TEST1)
add_executable(test_communication test_communication.cpp)
target_link_libraries(test_communication serialib raider bones ${OpenCV_LIBS})
ENDIF ()



OPTION(TEST2 "Opencv test" 1)
IF (TEST2)
add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv serialib raider bones ${OpenCV_LIBS})
ENDIF ()
