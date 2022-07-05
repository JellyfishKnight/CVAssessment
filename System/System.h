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
    //��Ƶ·��
    string root;
    //�з���ɫ
    Color color;
    //ԭͼ
    Mat demo;
    //�����ҵ�������
    vector<vector<Point>> allContours;
    //�����㼶
    vector<Vec4i> hierarchy;
    //ɸѡ���������
    vector<vector<Point>> selectedContours;
    //���б�ɸѡ�����������ϵľ���
    vector<RotatedRect> allRects;
    //ƥ���ϵ���������
    RotatedRect matchA, matchB;
    //װ�װ�����
    Point center;
    /**
     * @brief �ҵ��������ҽ���ɸѡ
     * @param frame ����ͼ��,Ӧ��Ϊ��ֵ��ͼ��
     */
    void ContoursFind(const Mat& frame);

    /**
     * @brief ��Ͼ��β��ҽ���ƥ��
     */
    void RectFit();

public:

    explicit System(string  r, Color c) : root(std::move(r)), color(c) {}

    /**
     * @brief ����ʶ��ϵͳ
     */
    void start();

    ~System() = default;

};

#endif //ASSESSMENT_SYSTEM_H
