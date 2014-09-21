#ifndef DEBUG_H
#define DEBUG_H


#include <iostream>
#include <sstream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define DEBUG_LEVEL 0

#define ERROR 1
#define WARNING 2
#define OK 3
#define INFO 4
#define STATE 5
#define MOVE 6
#define RAIDER 13



using namespace std;

void report(int, string);
void report(string);
void standardShow(cv::Mat,string);

template <class T> std::string to_string( const T &t )
{
    std::ostringstream oss;
    oss << t;
    return std::string (oss.str());
}

template <class T> std::string to_string( const std::vector<T> &t )
{
    std::ostringstream oss;
    for(int i=0; i<t.size(); i++)
    {
        oss << t.at(i) << "\t";
    }
    return std::string (oss.str());
}

#endif // DEBUG_H
