#ifndef _GLODWASSER_MICALI_H_
#define _GLODWASSER_MICALI_H_

#include <gmpxx.h>
#include <bitset>

#define SIZE_BIT_ARRAY 128 * 640

//Goldwasser_Micali加密，公钥N、delta，私钥p、q，加密的明文是01串binary_array，得到的密文是字符串homomorphism_ciphertext
void Goldwasser_Micali_encrypt(const mpz_class& N, const mpz_class& p, const mpz_class& q, const mpz_class& delta, const std::bitset<SIZE_BIT_ARRAY>& binary_array, std::string& homomorphism_ciphertext);

//使用私钥p，q解密一bit对应的密文a_bit_ciphertext，得到一个bool值
bool Goldwasser_Micali_decrypt(const mpz_class& p, const mpz_class& q, mpz_class a_bit_ciphertext);

//根据两个01串result_0和result_1，计算其汉明距离并逆向得到原始两向量欧几里得距离的估计值distance
//需要注意的是，这里的distance不是真正的欧几里得距离
//但是可以推导得到1/640倍根号distance约等于原始的欧几里得距离，误差在小数点后两到三位
void get_Hamming_Distance(std::bitset<128 * 640>& result_0, std::bitset<128 * 640>& result_1, int& distance);
//当distance小于65535 = 128 * 128 * 2 * 2时，我们认为验证通过

#endif 