#include "commander.h"

/* from stl */
#include <iostream>

cv::Scalar *Commander::_colors = new cv::Scalar[3]{
        CV_RGB(255, 0, 0),
        CV_RGB(0, 255, 0),
        CV_RGB(0, 0, 255)
};

Commander::Commander(const int num_dogs_per_police) : NUM_DOGS_PER_POLICE(num_dogs_per_police) {
}

void Commander::initialize(const cv::Mat &frame, const std::vector<cv::Rect> &pv) {
    std::vector<cv::Rect>::const_iterator it;
    for (it = pv.begin(); it != pv.end(); it++) {
        Police *pp = new Police(frame, *it, NUM_DOGS_PER_POLICE);
        _polices.push_back(pp);
    }
}

void Commander::transit(cv::Mat &frame, gsl_rng *rng) {
    std::vector<Police *>::iterator it;
    for (it = _polices.begin(); it != _polices.end(); it++) {
        (*it)->find(frame, rng);
    }
}

void Commander::normalize_weights() {
    float sum = 0.0f;

    std::vector<Police *>::iterator it;
    for (it = _polices.begin(); it != _polices.end(); it++) {
        (*it)->normalize();
    }
}

void Commander::resample() {
    std::vector<Police *>::iterator it;
    for (it = _polices.begin(); it != _polices.end(); it++) {
        (*it)->reassign();
    }
}

void Commander::show_best(cv::Mat &frame) {
    std::vector<Police *>::iterator it;
    for (it = _polices.begin(); it != _polices.end(); it++) {
        (*it)->report_best(frame, _colors[it - _polices.begin()]);
    }
}

void Commander::show_all(cv::Mat &frame) {
    std::vector<Police *>::iterator it;
    for (it = _polices.begin(); it != _polices.end(); it++) {
        (*it)->report_all(frame, _colors[it - _polices.begin()]);
    }
}

void Commander::sort_all_dogs() {
    std::vector<Police *>::iterator it;
    for (it = _polices.begin(); it != _polices.end(); it++) {
        (*it)->sort_dogs();
    }
}