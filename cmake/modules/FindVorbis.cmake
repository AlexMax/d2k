INCLUDE(FindPackageHandleStandardArgs)

IF (NOT VORBIS_INCLUDE_DIR)
    FIND_PATH(VORBIS_INCLUDE_DIR vorbis/vorbisfile.h HINTS $ENV{VORBIS_DIR})
ENDIF()

IF (NOT VORBIS_LIBRARIES)
    IF (NOT VORBIS_LIBRARY)
        FIND_LIBRARY(VORBIS_LIBRARY vorbis HINTS $ENV{VORBIS_DIR})
    ENDIF()

    IF (NOT VORBISFILE_LIBRARY)
        FIND_LIBRARY(VORBISFILE_LIBRARY vorbisfile HINTS $ENV{VORBIS_DIR})
    ENDIF()

    IF (VORBIS_LIBRARY AND VORBISFILE_LIBRARY)
        SET(VORBIS_LIBRARIES ${VORBISFILE_LIBRARY} ${VORBIS_LIBRARY})
    ENDIF()
ENDIF()

MARK_AS_ADVANCED(VORBIS_INCLUDE_DIR)
MARK_AS_ADVANCED(VORBIS_LIBRARIES)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
    Vorbis
    DEFAULT_MSG
    VORBIS_LIBRARIES
    VORBIS_INCLUDE_DIR
)

