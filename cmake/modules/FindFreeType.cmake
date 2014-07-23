INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(PC_FREETYPE QUIET freetype2)

IF (NOT FREETYPE_INCLUDE_DIR)
    FIND_PATH(FREETYPE_INCLUDE_DIR ft2build.h
        HINTS $ENV{FREETYPE_DIR} ${PC_FREETYPE_INCLUDEDIR} ${PC_FREETYPE_INCLUDE_DIRS}
        PATH_SUFFIXES freetype2
    )
ENDIF()
IF (NOT FREETYPE_LIBRARIES)
    FIND_LIBRARY(FREETYPE_LIBRARIES freetype HINTS $ENV{FREETYPE_DIR})
ENDIF()

MARK_AS_ADVANCED(FREETYPE_INCLUDE_DIR)
MARK_AS_ADVANCED(FREETYPE_LIBRARIES)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
    FreeType
    DEFAULT_MSG
    FREETYPE_LIBRARIES
    FREETYPE_INCLUDE_DIR
)
