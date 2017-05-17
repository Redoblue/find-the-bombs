#include "police.h"

/* from stl */
#include <iostream>

Police::Police(const cv::Mat &frame, const cv::Rect &rect, const int num_dogs) {
    ColorHistogram ch;
    cv::Mat imgROI = frame(rect);
    cv::Mat *hist = ch.getHueHistogram(imgROI, 65);

    for (int i = 0; i < num_dogs; i++) {
        Dog *pd = new Dog(frame.cols, frame.rows, rect, hist);

        _dogs.push_back(pd);
        _num_dogs = num_dogs;
    }
}

void Police::find(cv::Mat &frame, gsl_rng *rng) {
    std::vector<Dog *>::iterator it;
    for (it = _dogs.begin(); it != _dogs.end(); it++) {
        (*it)->run(frame, rng);
    }
}

void Police::normalize() {
    float sum = 0.0f;

    std::vector<Dog *>::iterator it;
    for (it = _dogs.begin(); it != _dogs.end(); it++) {
        sum += (*it)->weight;
    }
    for (it = _dogs.begin(); it != _dogs.end(); it++) {
        (*it)->weight /= sum;
    }
}

void Police::reassign() {
    std::vector<Dog *> tmp_dogs(_dogs);
    int k = 0;

    /* clear _polices */
    std::vector<Dog *>().swap(_dogs);

    std::vector<Dog *>::iterator it;
    for (it = tmp_dogs.begin(); it != tmp_dogs.end(); it++) {
        int np = cvRound((*it)->weight * _num_dogs);
        for (int i = 0; i < np; i++) {
            Dog *pd = new Dog(**it);
            pd->weight = 0.0f;
            _dogs.push_back(pd);
            k++;

            if (k == _num_dogs) {
                return;
            }
        }
    }

    while (k < _num_dogs) {
        Dog *pd = new Dog(*tmp_dogs.front());
        pd->weight = 0.0f;
        _dogs.push_back(pd);
        k++;
    }
}

void Police::sort_dogs() {
    std::sort(_dogs.begin(), _dogs.end(),
              [](Dog *const d1, Dog *const d2) -> bool {
                  return d1->weight > d2->weight;
              });
}

void Police::report_best(cv::Mat &frame, const cv::Scalar color) {
    Dog *bd = _dogs.front();

    int x1 = cvRound(bd->x - 0.5 * bd->s * bd->width);
    int y1 = cvRound(bd->y - 0.5 * bd->s * bd->height);
    int x2 = cvRound(bd->s * bd->width) + x1;
    int y2 = cvRound(bd->s * bd->height) + y1;

    cv::rectangle(frame, cv::Point(x1, y1), cv::Point(x2, y2),
                  color, 1, 8, 0);
}

void Police::report_all(cv::Mat &frame, const cv::Scalar color) {
    cv::Point center;

    std::vector<Dog *>::iterator it;
    for (it = _dogs.begin(); it != _dogs.end(); it++) {
        center.x = cvRound((*it)->x);
        center.y = cvRound((*it)->y);

        cv::circle(frame, center, 2, color, -1);
    }
}