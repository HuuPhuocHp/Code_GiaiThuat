#include <iostream>
#include <stack>
using namespace std;
int fibonacci(int n) {
    stack<int> s;
    s.push(n);
    int result = 0;
    while (!s.empty()) {
        int num = s.top();
        s.pop();
        if (num <= 1) {
            result = num;
        } else {
            s.push(num - 1);
            s.push(num - 2);
        }
    }
    return result;
}
int main() {
    int n;
    cout << "Enter a number for Fibonacci: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;
    return 0;
}

