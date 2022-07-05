//
// Created by wjy on 22-7-3.
//

#include "System.h"
#include "PreProcess.h"
#include "ranging.h"
#include "iostream"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

void System::start() {
    VideoCapture capture(root);
    if (!capture.isOpened()) {
        cout << "Wrong root!" << endl;
        return ;
    }
    while (true) {
        capture >> demo;
        if (demo.empty()) {                                      //�п��Լ��ж�����
            cout << "Picture read failed" << endl;
            return ;
        }
        Mat frame = PreProcess::start(color, demo).clone(); //Ԥ����(����һ����ֵ��ͼ)
        ContoursFind(frame);                               //���������Լ�ɸѡ
        RectFit();                                                  //Ѱ��ƥ��ľ���
        if (center.x != 0 && center.y != 0) {
            Ranging check;                            //��Ŀ���
            check.start(matchA, matchB, demo);
        }
//        if (center.x != 0 && center.y != 0) {
//            cout << center << endl;                            //���װ�װ����ĵ�
//        }
        center.x = center.y = 0;                            //���ݹ���
        cout << "------------------------------------------------" << endl;
        namedWindow("demo", WINDOW_NORMAL);
        imshow("demo", demo);
        int control = waitKey(1);
        if (control == 27) {
            break;
        }
    }
    waitKey(0);
    cout << "Finished" << endl;
    destroyAllWindows();
}

void System::ContoursFind(const Mat& frame) {
    allContours.clear();
    selectedContours.clear();
    Mat edge = frame.clone();
//    Canny(frame, edge, 35, 135);                   //���Կ��Ǵ��Ľ�
    findContours(edge, allContours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    for (int i = 0; i < allContours.size(); i++) {                      //���������������븱������ɸѡ����
        if (hierarchy[i][2] == -1 && hierarchy[i][3] != -1) {
            selectedContours.push_back(allContours[i]);
        }
    }
//    drawContours(demo, selectedContours, -1, Scalar(0, 255, 255), 10);
}

void System::RectFit() {
    allRects.clear();
    for (auto &contour: selectedContours) {          //ʹ����Բ���
        if (contour.size() > 100) {
            allRects.push_back(fitEllipse(contour));
        }
    }
//    for (const auto &rect: allRects) {
//        Point2f corner[4];
//        rect.points(corner);
//        for (int i = 0; i < 4; i++) {
//            line(demo, corner[i], corner[(i + 1) % 4], Scalar(0, 255 ,255), 10);
//            cout << "drawing" << endl;
//        }
//    }
    for (int i = 0; i < allRects.size(); i++) {
        for (int j = i + 1; j < allRects.size(); j++) {
            if (allRects[i].angle > 0 && allRects[i].angle <= 90) {
                allRects[i].angle = -1;
            }
            if (allRects[j].angle > 0 && allRects[j].angle <= 90) {
                allRects[j].angle = -1;
            }
            if (allRects[i].size.height / allRects[i].size.width >= 1
            && allRects[i].size.height / allRects[i].size.width <= 9
            && allRects[j].size.height / allRects[j].size.width >= 1
            && allRects[j].size.height / allRects[j].size.width <= 9 ) {          //�Ծ��γ���Ƚ���ɸѡ
                if (allRects[i].angle * allRects[j].angle > 0
                && (allRects[i].size.area() / allRects[j].size.area() >= 0.8
                    || allRects[j].size.area() / allRects[i].size.area() >= 0.8
                && (allRects[i].size.area() / allRects[j].size.area() <= 1.25
                    || allRects[j].size.area() / allRects[i].size.area() <= 1.25))
                ) {                  //���������εĽǶ��Լ�����������
                    Point2f point_i[4], point_j[4];
                    allRects[i].points(point_i);                                //�õ��������εĽǵ�
                    allRects[j].points(point_j);
                    if (allRects[i].center.x > allRects[j].center.x) { //�淶�������ε����λ���Ա��������
                        matchA = allRects[j];                          //��ֵ����Ա������������
                        matchB = allRects[i];                          //����װ�װ�����
                    } else {
                        matchA = allRects[i];
                        matchB = allRects[j];
                    }
                    center = Point((matchA.center.x + matchB.center.x) / 2, (matchB.center.y + matchA.center.y) / 2);
                    for (int l = 0; l < 4; l++) {                                   //����ƥ���ϵľ���
                        line(demo, point_i[l], point_i[(l + 1) % 4], Scalar(0, 255, 255), 20);
                        line(demo, point_j[l], point_j[(l + 1) % 4], Scalar(0, 255, 255), 20);
                    }
                    circle(demo, center, 10, Scalar(0, 255, 255), -1);
                }
            }
        }
    }
//    namedWindow("demo", WINDOW_NORMAL);
//    imshow("demo", demo);
}
