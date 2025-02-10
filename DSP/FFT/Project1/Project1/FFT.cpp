#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <complex>

#define u_short unsigned short
using namespace std;
int N = 0;
double PI = 3.14159265358979323846;
using cd = complex<double>;

void FFT(vector <cd>& v, bool invert) {

	vector<cd> even;
	vector<cd> odd;

	for (int i = 0; 2 * i < v.size(); i++) {
		even[i] = v[i * 2];
		odd[i] = v[i * 2 + 1];
	}

	// ��������� FFT ����
	FFT(even, invert);
	FFT(odd, invert);

	// ���ļ� �����ο��� �����ϴ� ���� (Butterfly ����)
	for (int i = 0; i < N / 2; i++) {
		cd w = polar(1.0, (invert ? -2 : 2) * PI * i / N) * odd[i];
		v[i] = even[i] + w;
		v[i + N / 2] = even[i] - w;
	}

	// ����ȯ ��, ũ�� ���� (IFFT)
	if (invert) {
		for (int i = 0; i < N; i++) {
			v[i] /= 2;
		}
	}
}

int main() {
	vector<cd> data = { 1, 2, 3, 4, 5, 6, 7, 8 };

	cout << "Original Data:\n";
	for (cd x : data) cout << x << " ";
	cout << "\n\n";

	FFT(data, false);  // FFT ����

	cout << "After FFT:\n";
	for (cd x : data) cout << x << " ";
	cout << "\n\n";

	FFT(data, true);  // IFFT ����

	cout << "After IFFT (Recovered):\n";
	for (cd x : data) cout << x << " ";
	cout << endl;

	return 0;
}