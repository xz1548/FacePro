#ifndef _BINARYZATION_H_
#define _BINARYZATION_H_

#include <bitset>

//将对特征向量in_feature_vec的128个分量进行二值化，得到长度为128 * 640的01串result
void binaryzation(float in_feature_vec[128], std::bitset<128 * 640>& result);

#endif 
