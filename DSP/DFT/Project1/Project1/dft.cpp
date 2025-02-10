#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <complex>  // ���Ҽ� ����� ���� ���
#define M_PI 3.14159265358979323846
// DFT ��� �Լ�
std::vector<std::complex<double>> dft(const std::vector<double>& x) {
    int N = x.size();  // �Է� ��ȣ�� ũ��
    std::vector<std::complex<double>> X(N);  // ���ļ� ������ ����� ������ ����

    // DFT ���� ����
    for (int k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);  // ���ļ� ������ ���� ������ ���Ҽ�
        for (int n = 0; n < N; ++n) {
            double real_part = cos(2 * M_PI * k * n / N);  // �Ǽ���
            double imag_part = -sin(2 * M_PI * k * n / N);  // �����
            std::complex<double> exp_term(real_part, imag_part);
            sum += x[n] * exp_term;  // DFT ���Ŀ� ���� ���
        }
        X[k] = sum;  // ���� ���ļ� ���� ����
    }

    return X;
}

// ��� ��� �Լ�
void print_complex_vector(const std::vector<std::complex<double>>& vec) {
    for (const auto& value : vec) {
        std::cout << value << std::endl;
    }
}

int main() {
    // �Է� ��ȣ (��: ���ø��� ������)
    std::vector<double> x = { 1.0, 2.0, 3.0, 4.0 };  // ���÷� ������ ��ȣ�� ���

    // DFT ���
    std::vector<std::complex<double>> X = dft(x);

    // DFT ��� ���
    std::cout << "DFT ���:" << std::endl;
    print_complex_vector(X);

    return 0;
}
