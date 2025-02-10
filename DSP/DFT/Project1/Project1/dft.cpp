#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <complex>  // 복소수 계산을 위한 헤더
#define M_PI 3.14159265358979323846
// DFT 계산 함수
std::vector<std::complex<double>> dft(const std::vector<double>& x) {
    int N = x.size();  // 입력 신호의 크기
    std::vector<std::complex<double>> X(N);  // 주파수 영역의 결과를 저장할 벡터

    // DFT 공식 적용
    for (int k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);  // 주파수 성분의 합을 저장할 복소수
        for (int n = 0; n < N; ++n) {
            double real_part = cos(2 * M_PI * k * n / N);  // 실수부
            double imag_part = -sin(2 * M_PI * k * n / N);  // 허수부
            std::complex<double> exp_term(real_part, imag_part);
            sum += x[n] * exp_term;  // DFT 공식에 따른 계산
        }
        X[k] = sum;  // 계산된 주파수 성분 저장
    }

    return X;
}

// 결과 출력 함수
void print_complex_vector(const std::vector<std::complex<double>>& vec) {
    for (const auto& value : vec) {
        std::cout << value << std::endl;
    }
}

int main() {
    // 입력 신호 (예: 샘플링된 데이터)
    std::vector<double> x = { 1.0, 2.0, 3.0, 4.0 };  // 예시로 간단한 신호를 사용

    // DFT 계산
    std::vector<std::complex<double>> X = dft(x);

    // DFT 결과 출력
    std::cout << "DFT 결과:" << std::endl;
    print_complex_vector(X);

    return 0;
}
