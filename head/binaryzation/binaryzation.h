#ifndef _BINARYZATION_H_
#define _BINARYZATION_H_

#include <bitset>

//������������in_feature_vec��128���������ж�ֵ�����õ�����Ϊ128 * 640��01��result
void binaryzation(float in_feature_vec[128], std::bitset<128 * 640>& result);

#endif 
