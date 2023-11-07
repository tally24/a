#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of Fibonacci numbers to calculate: ";
    cin >> n;

    vector<long long> fibonacciSeries(n);

    long long stepCount = 0;

    if (n >= 1) {
        fibonacciSeries[0] = 0;
        stepCount++;
    }

    if (n >= 2) {
        fibonacciSeries[1] = 1;
        stepCount++;
    }

    for (int i = 2; i < n; i++) {
        fibonacciSeries[i] = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
        stepCount += 3; // Each iteration includes 3 steps: addition, access previous two values, and assignment.
    }

    cout << "Fibonacci Series:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacciSeries[i] << " ";
    }

    cout << "\nTotal steps taken to calculate the Fibonacci series: " << stepCount << endl;

    return 0;
}
