#include <iostream>
#include <stack>
using namespace std;
int reverseNumber(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }
    int reversedNumber = 0;
    int place = 1;
    while (!s.empty()) {
        reversedNumber += s.top() * place;
        s.pop();
        place *= 10;
    }
    return reversedNumber;
}
int main() {
    int n;
    cout << "Enter a number to reverse: ";
    cin >> n;
    
    cout << "Reversed number is: " << reverseNumber(n) << endl;
    return 0;
}
C
#include <iostream>
#include <stack>
using namespace std;
void moveDisk(int from, int to) {
    cout << "Move disk from tower " << from << " to tower " << to << endl;
}
void hanoi(int n, int from, int to, int auxiliary) {
    stack<tuple<int, int, int>> s;
    s.push({n, from, to});
    while (!s.empty()) {
        auto [numDisks, fromTower, toTower] = s.top();
        s.pop();
        if (numDisks == 1) {
            moveDisk(fromTower, toTower);
        } else {
            s.push({numDisks - 1, auxiliary, toTower});
            s.push({1, fromTower, toTower});
            s.push({numDisks - 1, fromTower, auxiliary});
        }
    }
}
int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    hanoi(n, 1, 3, 2);
    return 0;
}
