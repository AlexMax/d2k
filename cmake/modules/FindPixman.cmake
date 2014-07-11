INCLUDE(FindPackageHandleStandardArgs)

IF (NOT PIXMAN_INCLUDE_DIR)
    FIND_PATH(PIXMAN_INCLUDE_DIR pixman-1/pixman.h HINTS $ENV{PIXMAN_DIR})
ENDIF()
IF (NOT PIXMAN_LIBRARIES)
    FIND_LIBRARY(PIXMAN_LIBRARIES pixman-1 HINTS $ENV{PIXMAN_DIR})
ENDIF()

MARK_AS_ADVANCED(PIXMAN_INCLUDE_DIR)
MARK_AS_ADVANCED(PIXMAN_LIBRARIES)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
    Pixman
    DEFAULT_MSG
    PIXMAN_LIBRARIES
    PIXMAN_INCLUDE_DIR
)
