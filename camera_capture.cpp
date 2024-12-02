#include <iostream>
#include <fstream>

#include "v4l2_capture.h"
#include "capture.h"

#define XRES 640
#define YRES 480

using namespace std;

int main(int argc, char** argv)
{
    V4l2Capture V4l2Capture("/dev/video0", XRES, YRES);
    unsigned char * img_buf = (unsigned char *)malloc(XRES*YRES*3);
    V4l2Capture.get_frame(img_buf, XRES*YRES*3);

    ofstream image;
    image.open("frame.ppm");
    image << "P6\n" << XRES << " " << YRES << " 255\n";
    image.write((char *) img_buf, XRES*YRES*3);
    image.close();
    if (img_buf) {
        free(img_buf);
        img_buf = NULL;
    }

    return 0;

}
