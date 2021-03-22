#ifndef _GLODWASSER_MICALI_H_
#define _GLODWASSER_MICALI_H_

#include <gmpxx.h>
#include <bitset>

#define SIZE_BIT_ARRAY 128 * 640

//Goldwasser_Micali���ܣ���ԿN��delta��˽Կp��q�����ܵ�������01��binary_array���õ����������ַ���homomorphism_ciphertext
void Goldwasser_Micali_encrypt(const mpz_class& N, const mpz_class& p, const mpz_class& q, const mpz_class& delta, const std::bitset<SIZE_BIT_ARRAY>& binary_array, std::string& homomorphism_ciphertext);

//ʹ��˽Կp��q����һbit��Ӧ������a_bit_ciphertext���õ�һ��boolֵ
bool Goldwasser_Micali_decrypt(const mpz_class& p, const mpz_class& q, mpz_class a_bit_ciphertext);

//��������01��result_0��result_1�������人�����벢����õ�ԭʼ������ŷ����þ���Ĺ���ֵdistance
//��Ҫע����ǣ������distance����������ŷ����þ���
//���ǿ����Ƶ��õ�1/640������distanceԼ����ԭʼ��ŷ����þ��룬�����С�����������λ
void get_Hamming_Distance(std::bitset<128 * 640>& result_0, std::bitset<128 * 640>& result_1, int& distance);
//��distanceС��65535 = 128 * 128 * 2 * 2ʱ��������Ϊ��֤ͨ��

#endif 