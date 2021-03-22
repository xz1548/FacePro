#include "..\..\head\goldwasser_micali\goldwasser_micali.h"

#include <ctime>
#include <string>
#include <bitset>
#include <gmpxx.h>

#define SIZE_N 1024

//�������Ŀ���ģ��
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

//Goldwasser_Micali���ܣ���ԿN��delta��˽Կp��q�����ܵ�������01��binary_array���õ����������ַ���homomorphism_ciphertext
void Goldwasser_Micali_encrypt(const mpz_class& N, const mpz_class& p, const mpz_class& q, const mpz_class& delta, const std::bitset<SIZE_BIT_ARRAY>& binary_array, std::string& homomorphism_ciphertext) {
    homomorphism_ciphertext = "";
    std::string a_bit;
    mpz_class ran = 2;
    gmp_randclass rr(gmp_randinit_default);
    rr.seed(time(NULL));//��������ӡ�

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

//ʹ��˽Կp��q����һbit��Ӧ������a_bit_ciphertext���õ�һ��boolֵ
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

//��������01��result_0��result_1�������人�����벢����õ�ԭʼ������ŷ����þ���Ĺ���ֵdistance
//��Ҫע����ǣ������distance����������ŷ����þ���
//���ǿ����Ƶ��õ�1/640������distanceԼ����ԭʼ��ŷ����þ��룬�����С�����������λ
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
//��distanceС��65535 = 128 * 128 * 2 * 2ʱ��������Ϊ��֤ͨ��
