#include "test_v4l2_capture.h"


TEST_F(V4l2CaptureTest, noInputBuf) {
    EXPECT_EQ(-1, m_pV4l2Capture->get_frame(NULL, 0));
}

TEST_F(V4l2CaptureTest, checkInputBufferSize) {
    char tempBuf[2] = {0};
    EXPECT_EQ(-2, m_pV4l2Capture->get_frame(tempBuf, 0));
}
