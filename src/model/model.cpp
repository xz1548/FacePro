#include "..\..\head\model\model.h"

#include <iostream>
#include <Python.h>
#include "opencv.hpp"
#include <fstream>

#define MAX_LEN 128

//将调用python脚本，得到的特征向量存到数组face_encodings中
void call_model(float face_encodings[]) {
    //python调用face_recognition,输出结果保存在face_encoding.txt中
    std::cout << "call_py------------------" << std::endl;
    std::cout << "Model Initializing-------" << std::endl;
    Py_SetPythonHome(L"C:/Anaconda3");

    Py_Initialize();

    PyObject* pModule = NULL;
    PyObject* pFunc = NULL;
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("import face_recognition");
    PyRun_SimpleString("import numpy as np");
    PyRun_SimpleString("sys.path.append('./')");

    pModule = PyImport_ImportModule("myface_recog");//导入自己的python模块
    pFunc = PyObject_GetAttrString(pModule, "face_rec");//导入自己的python函数
    PyObject* pArg;
    pArg = PyObject_CallObject(pFunc, NULL);

    Py_Finalize();

    std::cout << "final------------------" << std::endl;
    //将face_encoding.txt中的数据读入到c++中
    std::ifstream fcin("C:/Users/70/workSpace/visualStidio/FacePro/face_encoding.txt");

    int i;
    float ele;

    for (i = 0; i != MAX_LEN; i++) {
        fcin >> ele;
        face_encodings[i] = ele;
    }

    return;

}

//一个测试函数，计算两特征向量a，b间的欧几里得距离
double Euclidean_Distance(float a[], float b[]) {
    int i;
    float delta = 0;
    double d = 0;
    for (i = 0; i < 128; i++) {
        delta = a[i] - b[i];
        d = d + ((double)delta) * ((double)delta);
    }

    d = sqrt(d);

    return d;

}
