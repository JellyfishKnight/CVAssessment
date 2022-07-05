//
// Created by wjy on 22-7-3.
//

#ifndef ASSESSMENT_PREPROCESS_H
#define ASSESSMENT_PREPROCESS_H

#include "opencv2/core.hpp"

using namespace cv;

typedef enum color {BLUE, RED} Color;

/*������,����ʵ����*/

class PreProcess {
private:
    ~PreProcess() = default;
    PreProcess() = default;
public:
    /**
     * @brief Ԥ����̬����
     * @param color �з�����ɫ
     * @param input ����ͼƬ
     */
    static Mat start(Color color, Mat &input);
};

#endif //ASSESSMENT_PREPROCESS_H
