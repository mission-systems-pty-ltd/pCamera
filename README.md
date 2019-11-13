# pCamera

A simple opencv application to display simulated camera data from MORSE using python moos.

pCamera is a simple application that subscribes to binary rgba frames and displays them using OpenCV. Currently, we use straight binary encoding for the images, but in the future will be switching to Cap'n-Proto serialisation and giving the option for grey-scale formats etc as well as using a proper header structure with each message (probably emulating the existing ROS message format).

## Dependencies

* OpenCV 3 (`sudo apt install libopencv-dev`)
* MOOS-Ivp (see iPX4 readme for installation instructions)
* Mission Systems' MORSE (https://github.com/mission-systems-pty-ltd/morse)

## Future Development

* Generalise camera frame dimensions
* Generalise frame format to be sent over network (e.g. greyscale)
