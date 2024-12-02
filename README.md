Camera capture
====================================

Build
--------------

You need the V4L2 development package. On Debian/Ubuntu:
```
$ sudo apt install libv4l2-dev
```

Then:
```
$ bash build.sh
```

Calling `./camera_capture` acquires one image from `/dev/video0` and saves it as
`frame.ppm`.


