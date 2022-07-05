//
// Created by wjy on 22-7-3.
//

#ifndef ASSESSMENT_Ranging_H
#define ASSESSMENT_Ranging_H

#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

//工具类:解算PnP,不可被实例化
class Ranging {
private:
    //相机内参矩阵
    Mat cameraMatrix;
    //畸变矩阵
    Mat disCoeffs;
    //平移矩阵
    Mat tvec;
    //旋转矩阵
    Mat rvec;
    //装甲板灯条的点以及中心点
    Point2f *points;
    //装甲板的实际宽度和高度
    float boardWidth = 135;
    float boardHeight = 125;
    /**
     * @brief 初始化成员变量
     */
    void init(const RotatedRect& a, const RotatedRect& b);
    /**
     * @brief 计算世界坐标
     * @return 世界坐标
     */
    vector<Point3f> getObjPoints();
    /**
     * @brief 误差计算
     */
    void caculateError();

public:
    /**
     * @brief 开始解算PnP
     * @param a 矩形a
     * @param b 矩形b
     */
    void start(const RotatedRect& a, const RotatedRect& b, Mat& demo);

    Ranging() = default;

    ~Ranging() = default;
};


#endif //ASSESSMENT_Ranging_H
