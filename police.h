#ifndef POLICE_H
#define POLICE_H

/* from local library */
#include "dog.h"

/* from stl */
#include <vector>

class Police {
public:
    Police(const cv::Mat &frame, const cv::Rect &rect, const int num_dogs);

    void find(cv::Mat &frame, gsl_rng *rng);

    void normalize();

    void reassign();

    void report_best(cv::Mat &frame, const cv::Scalar color);

    void report_all(cv::Mat &frame, const cv::Scalar color);

    void sort_dogs();

private:
    std::vector<Dog *> _dogs;
    int _num_dogs;
};

#endif
