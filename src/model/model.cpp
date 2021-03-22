#include "..\..\head\model\model.h"

#include <iostream>
#include <Python.h>
#include "opencv.hpp"
#include <fstream>

#define MAX_LEN 128

//������python�ű����õ������������浽����face_encodings��
void call_model(float face_encodings[]) {
    //python����face_recognition,������������face_encoding.txt��
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

    pModule = PyImport_ImportModule("myface_recog");//�����Լ���pythonģ��
    pFunc = PyObject_GetAttrString(pModule, "face_rec");//�����Լ���python����
    PyObject* pArg;
    pArg = PyObject_CallObject(pFunc, NULL);

    Py_Finalize();

    std::cout << "final------------------" << std::endl;
    //��face_encoding.txt�е����ݶ��뵽c++��
    std::ifstream fcin("C:/Users/70/workSpace/visualStidio/FacePro/face_encoding.txt");

    int i;
    float ele;

    for (i = 0; i != MAX_LEN; i++) {
        fcin >> ele;
        face_encodings[i] = ele;
    }

    return;

}

//һ�����Ժ�������������������a��b���ŷ����þ���
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
