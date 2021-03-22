#include "..\..\head\binaryzation\binaryzation.h"

#include<cmath>
#include <iostream>

//������������in_feature_vec��128���������ж�ֵ�����õ�����Ϊ128 * 640��01��result
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
