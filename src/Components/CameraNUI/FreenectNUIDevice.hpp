/* 
 * File:   FreenectNUIDevice.h
 * Author: Michal Lisicki
 *
 */

#ifndef FREENECTNUIDEVICE_H
#define	FREENECTNUIDEVICE_H

#include <libfreenect.hpp>
#include <libfreenect_sync.h>
#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class FreenectNUIDevice : public Freenect::FreenectDevice {
public:
    FreenectNUIDevice(freenect_context *_ctx, int _index);
    
    void VideoCallback(void* _rgb, uint32_t timestamp);
    void DepthCallback(void* _depth, uint32_t timestamp);
    bool getVideo(Mat& output);
    bool getDepth(Mat& output);
private:
    pthread_mutex_t m_rgb_mutex;
    pthread_mutex_t m_depth_mutex;
    bool m_new_rgb_frame;
    bool m_new_depth_frame;
    Mat depthMat;
    Mat rgbMat;
};

#endif	/* FREENECTNUIDEVICE_H */

