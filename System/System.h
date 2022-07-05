//
// Created by wjy on 22-7-3.
//

#ifndef ASSESSMENT_SYSTEM_H
#define ASSESSMENT_SYSTEM_H

#include <utility>
#include "PreProcess.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "vector"

using namespace std;
using namespace cv;

class System {
private:
    //视频路径
    string root;
    //敌方颜色
    Color color;
    //原图
    Mat demo;
    //所有找到的轮廓
    vector<vector<Point>> allContours;
    //轮廓层级
    vector<Vec4i> hierarchy;
    //筛选过后的轮廓
    vector<vector<Point>> selectedContours;
    //所有被筛选过后的轮廓拟合的矩形
    vector<RotatedRect> allRects;
    //匹配上的两个矩形
    RotatedRect matchA, matchB;
    //装甲板中心
    Point center;
    /**
     * @brief 找到轮廓并且进行筛选
     * @param frame 输入图像,应当为二值化图像
     */
    void ContoursFind(const Mat& frame);

    /**
     * @brief 拟合矩形并且进行匹配
     */
    void RectFit();

public:

    explicit System(string  r, Color c) : root(std::move(r)), color(c) {}

    /**
     * @brief 启动识别系统
     */
    void start();

    ~System() = default;

};

#endif //ASSESSMENT_SYSTEM_H
