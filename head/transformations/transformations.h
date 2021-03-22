#ifndef _TRANSFORMATION_H_
#define _TRANSFORMATION_H_

extern double Matrix[128][128];
extern double pos_x[11];
extern double pos_y[11];
extern int q[11];

//密钥生成，生成随机线性投影用的加密矩阵
void generate_Matrix(double Matrix[][128]);

//密钥生成，生成表面褶皱变换用的电荷分布
void generate_charge(int n, double pos_x[], double pos_y[], int q[]);

//随机线性投影
void transformation1(double Matrix[][128], float data[], float trans_data[]);

//表面褶皱变换
void transformation2(double pos_x[], double pos_y[], int q[], float data[]);

//特征向量经过两次变换之后，其各分量范围都在-320到320

#endif 
