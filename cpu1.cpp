#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

int n = 10000000;
double temp = 2 * 3.141592 / n;
double arr_sum = 0;

void fill_sin(double* a) {
	    for (int i = 0; i < n; i++) {
			a[i] = sin(i * temp);
		}
		for (int i = 0; i < n; i++) {
			arr_sum += a[i];
		}
	    cout << arr_sum << endl;
}
int main() {
	auto begin = std::chrono::steady_clock::now();
	double* a = new double[n];
	fill_sin(a);
	delete[] a;
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	return 0;
}
