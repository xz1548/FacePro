#include "..\..\head\goldwasser_micali\goldwasser_micali.h"

#include <ctime>
#include <string>
#include <bitset>
#include <gmpxx.h>

#define SIZE_N 1024

//大整数的快速模幂
mpz_class FME(mpz_class x, mpz_class n, const mpz_class& m) {
    mpz_class d = 1;
    mpz_class n_0 = 1;

    while (n != 0) {
        n_0 = n >> 1;
        if (n != (n_0 << 1)) {
            d = (d * x) % m;
        }
        n = n_0;
        x = (x * x) % m;
    }
    return d;
}

//Goldwasser_Micali加密，公钥N、delta，私钥p、q，加密的明文是01串binary_array，得到的密文是字符串homomorphism_ciphertext
void Goldwasser_Micali_encrypt(const mpz_class& N, const mpz_class& p, const mpz_class& q, const mpz_class& delta, const std::bitset<SIZE_BIT_ARRAY>& binary_array, std::string& homomorphism_ciphertext) {
    homomorphism_ciphertext = "";
    std::string a_bit;
    mpz_class ran = 2;
    gmp_randclass rr(gmp_randinit_default);
    rr.seed(time(NULL));//随机数种子。

    int i;
    for (i = 0; i != SIZE_BIT_ARRAY; i++) {
        ran = rr.get_z_range(N);
        if ((gcd(ran, p) != 1) || (gcd(ran, q) != 1)) {
            ran = ran + p + q;
        }

        ran = ((ran * ran) * (1 - binary_array[i] + binary_array[i] * delta)) % N;

        a_bit = ran.get_str(16);

        homomorphism_ciphertext += std::string(SIZE_N - a_bit.length(), '0') + a_bit;

    }

    return;
}

//使用私钥p，q解密一bit对应的密文a_bit_ciphertext，得到一个bool值
bool Goldwasser_Micali_decrypt(const mpz_class& p, const mpz_class& q, mpz_class a_bit_ciphertext) {
    mpz_class exp;
    exp = ((p - 1) >> 1);
    a_bit_ciphertext = a_bit_ciphertext % p;
    if (FME(a_bit_ciphertext, exp, p) != 1) {
        return false;
    }

    exp = ((q - 1) >> 1);
    if (FME(a_bit_ciphertext, exp, p) != 1) {
        return false;
    }

    return true;
}

//根据两个01串result_0和result_1，计算其汉明距离并逆向得到原始两向量欧几里得距离的估计值distance
//需要注意的是，这里的distance不是真正的欧几里得距离
//但是可以推导得到1/640倍根号distance约等于原始的欧几里得距离，误差在小数点后两到三位
void get_Hamming_Distance(std::bitset<128 * 640>& result_0, std::bitset<128 * 640>& result_1, int& distance) {

    int i, j;
    unsigned long long origin = 0;
    int k = 0;

    distance = 0;

    for (i = 0; i != 128; i++) {

        for (j = 0; j != 640; j++) {

            k = k + (result_0[origin + j] ^ result_1[origin + j]);
            
            /*
            if (result_0[origin + j] != result_1[origin + j]) {
                k++;
            }
            */
            
        }
        distance = distance + k * k;

        origin = origin + 640;
        k = 0;
    }

    return;
}
//当distance小于65535 = 128 * 128 * 2 * 2时，我们认为验证通过
