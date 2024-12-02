INCLUDE_DIRECTORIES(inc)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/output/lib)

aux_source_directory(./src DIR_LIB_SRCS)

#add_library(capture STATIC ${DIR_LIB_SRCS})
add_library(capture SHARED ${DIR_LIB_SRCS})

set(HEADERS
  inc/capture.h
  inc/v4l2_capture.h
)

file(COPY ${HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/output/inc)

#install(FILES ${HEADERS}
#  DESTINATION ${PROJECT_SOURCE_DIR}/output/inc
#)


