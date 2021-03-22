#ifndef _MODEL_H_
#define _MODEL_H_

//将调用python脚本，得到的特征向量存到数组face_encodings中
void call_model(float face_encodings[]);

//一个测试函数，计算两特征向量a，b间的欧几里得距离
double Euclidean_Distance(float a[], float b[]);

#endif 
