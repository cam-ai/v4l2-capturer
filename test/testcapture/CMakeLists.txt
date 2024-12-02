file(GLOB SRCS *.cpp)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/test)
ADD_EXECUTABLE(testcapture ${SRCS})

TARGET_LINK_LIBRARIES(testcapture
    capture
    libgtest
    libgmock
)

add_test(NAME testcapture
         COMMAND testcapture)
