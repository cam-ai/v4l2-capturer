#include "gtest/gtest.h"
#include "v4l2_capture.h"

// The fixture for testing class v4l2_capture.
class V4l2CaptureTest : public ::testing::Test {

protected:

    // You can do set-up work for each test here.
    V4l2CaptureTest() {
        m_pV4l2Capture = NULL;
    }

    // You can do clean-up work that doesn't throw exceptions here.
    ~V4l2CaptureTest () override{

    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    void SetUp() override {
        m_pV4l2Capture = new V4l2Capture("/dev/video0", 640, 480);
    }

    // Code here will be called immediately after each test (right
    // before the destructor).
    void TearDown() override {
        if (m_pV4l2Capture != NULL) {
            delete m_pV4l2Capture;
        }
    }
    V4l2Capture *m_pV4l2Capture;
};
