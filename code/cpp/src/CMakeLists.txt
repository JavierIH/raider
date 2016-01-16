add_subdirectory(libraries)

OPTION(TEST "Test for libraries and integration")
IF(TEST)
add_subdirectory(test)
ENDIF()

OPTION(APPS "Aplications (Ceabot, footbal...)")
IF(APPS)
add_subdirectory(apps)
ENDIF()



