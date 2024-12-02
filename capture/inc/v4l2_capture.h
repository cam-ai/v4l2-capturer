#ifndef _V4L2_CAPTURE_H
#define _V4L2_CAPTURE_H


#include <string>
#include <memory>

#include "capture.h"

struct buffer {
      void   *data;
      size_t  size;
};

struct RGBImage {
      unsigned char   *data; // RGB888
      size_t          width;
      size_t          height;
      size_t          size; // width * height * 3
};


class V4l2Capture:public Capture
{

public:
    V4l2Capture(const std::string& device = "/dev/video0", 
           int width = 640, 
           int height = 480);

    ~V4l2Capture();

    int get_frame(void *img_buf, unsigned int buf_len);

private:
    void init_mmap();

    void open_device();
    void close_device();

    void init_device();
    void uninit_device();

    void start_capturing();
    void stop_capturing();

    bool read_frame();

    std::string device;
    int fd;

    RGBImage rgb_frame;
    struct buffer          *buffers;
    unsigned int     n_buffers;

    size_t xres, yres;
    size_t stride;

    bool force_format = true;

    /** Captures and returns a frame from the V4l2Capture.
     *
     * The returned object contains a field 'data' with the image data in RGB888
     * format (ie, RGB24), as well as 'width', 'height' and 'size' (equal to
     * width * height * 3)
     *
     * This call blocks until a frame is available or until the provided
     * timeout (in seconds). 
     *
     * Throws a runtime_error if the timeout is reached.
     */
    const RGBImage& frame(int timeout = 1);
};

#endif
