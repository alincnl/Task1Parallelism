#include <iostream>
#include <cmath>
using namespace std;

int n = 10000000;
float temp = 2 * 3.141592 / n;
float arr_sum = 0;

void fill_sin(float* a) {
    #pragma acc data create(a[:n]) copy(arr_sum) copyin(temp)
    {
    #pragma acc kernels
    for (int i = 0; i < n; i++) {
        a[i] = sin(i * temp);
    }
    #pragma acc kernels
    for (int i = 0; i < n; i++) {
        arr_sum += a[i];
    }
    }
    cout << fixed;
	cout.precision(20);
    cout << arr_sum << endl;
}
int main() {
    float* a = new float[n];
    fill_sin(a);
    delete[] a;
    return 0;
}
