#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

random_device rd;
mt19937 gen(rd());

vector<int> arr(100000000);

int busqueda_lineal(const vector<int>&  arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int busqueda_binaria(const vector<int>&  arr, int n, int x) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == x) {
            return medio;
        }
        if (arr[medio] < x) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

int busqueda_trinaria(const vector<int>&  arr, int n, int x) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int tercio1 = izquierda + (derecha - izquierda) / 3;
        int tercio2 = derecha - (derecha - izquierda) / 3;

        if (arr[tercio1] == x) {
            return tercio1;
        }
        if (arr[tercio2] == x) {
            return tercio2;
        }

        if (x < arr[tercio1]) {
            derecha = tercio1 - 1;
        } else if (x > arr[tercio2]) {
            izquierda = tercio2 + 1;
        } else {
            izquierda = tercio1 + 1;
            derecha = tercio2 - 1;
        }
    }
    return -1;
}

auto benchmark(int (*func)(const vector<int>&  arr, int n, int x) , int n , int count) {
    uniform_int_distribution<int> dist(1, n);
    duration<float, milli> delta = {};

    for (int i = 0; i < count; i++) {

        int x = dist(gen);
        auto start = chrono::high_resolution_clock::now();
        func(arr , n , x);
        auto end = chrono::high_resolution_clock::now();
        delta += end - start;
    }
    delta /= count;

    return delta.count();
}

int main() {
    const int sizes[4] = {100000 , 1000000, 10000000, 100000000};
    const int test_count = 30;
    for(int i = 0; i < 1e8; i++) {
        arr[i] = i;
    }

    for (auto& size : sizes) {
        cout << "Prueba " << size << " elementos:" << endl;
        cout << "Busqueda lineal: " << benchmark(busqueda_lineal , size , test_count) << "ms" << endl;
        cout << "Busqueda binaria: " << benchmark(busqueda_binaria , size , test_count) << "ms" << endl;
        cout << "Busqueda trinaria: " << benchmark(busqueda_trinaria , size , test_count) << "ms" << endl;
    }



    return 1;
}