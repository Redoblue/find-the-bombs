#ifndef COMMANDER_H
#define COMMANDER_H

/* from local library */
#include "police.h"
#include "colorhistogram.h"

/* from stl */
#include <vector>

/* from OpenCV library */
#include <opencv2/core.hpp>

class Commander {
public:
    static cv::Scalar *_colors;

    Commander(const int num_dogs_per_police);

    const int NUM_DOGS_PER_POLICE;

    void initialize(const cv::Mat &image, const std::vector<cv::Rect> &pv);

    void transit(cv::Mat &frame, gsl_rng *rng);

    void normalize_weights();

    void resample();

    void show_best(cv::Mat &frame);

    void show_all(cv::Mat &frame);

    void sort_all_dogs();

private:
    std::vector<Police *> _polices;
};

#endif
