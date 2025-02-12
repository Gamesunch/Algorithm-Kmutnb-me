#include <iostream>
using namespace std;

int ct = 0;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isPrimeCycle(int X[], int n) {
    for (int i = 1; i <= n; i++) {
        int sum = X[i] + X[(i % n) + 1];
        if (!isPrime(sum)) return false;
    }
    return true;
}

void permute(int X[], int start, int end) {
    if (start == end) {
        if (isPrimeCycle(X, end)) {
            ct++;
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(X[start], X[i]);
        permute(X, start + 1, end);
        swap(X[start], X[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int X[21];

    for (int i = 1; i <= n; i++) {
        X[i] = i;
    }

    permute(X, 2, n);
    cout<<ct;
    return 0;
}

