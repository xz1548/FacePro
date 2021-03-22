#include "..\..\head\binaryzation\binaryzation.h"

#include<cmath>
#include <iostream>

//将对特征向量in_feature_vec的128个分量进行二值化，得到长度为128 * 640的01串result
void binaryzation(float in_feature_vec[128], std::bitset<128 * 640>& result) {

	result.reset();
	int i = 0; 
	int j = 0;
	unsigned long long offset = 320;
	unsigned long long origin = 0;
	int j_max = 64;

	for (i = 0; i != 128; i++) {
		origin = offset + unsigned long long(floor(in_feature_vec[i] + 0.5));

		for (j = 0; j != j_max; j++) {
			result.set(origin + j);
			result.set(origin - j);
		}

		offset += 640;

	}
	return;
}
