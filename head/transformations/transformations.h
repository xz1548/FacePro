#ifndef _TRANSFORMATION_H_
#define _TRANSFORMATION_H_

extern double Matrix[128][128];
extern double pos_x[11];
extern double pos_y[11];
extern int q[11];

//��Կ���ɣ������������ͶӰ�õļ��ܾ���
void generate_Matrix(double Matrix[][128]);

//��Կ���ɣ����ɱ�������任�õĵ�ɷֲ�
void generate_charge(int n, double pos_x[], double pos_y[], int q[]);

//�������ͶӰ
void transformation1(double Matrix[][128], float data[], float trans_data[]);

//��������任
void transformation2(double pos_x[], double pos_y[], int q[], float data[]);

//���������������α任֮�����������Χ����-320��320

#endif 
