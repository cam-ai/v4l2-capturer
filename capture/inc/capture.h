#ifndef _CAPTURE_H
#define _CAPTURE_H

class Capture {

public:
    Capture() {}
    virtual ~Capture() {};

    /** Interface of Capture on frame.
     *
     * img_buf: the buffer will hold the image, this should be allocate first
     * buf_len: buffer length
     */
    virtual int get_frame(void *img_buf, unsigned int buf_len) = 0;
};

#endif
