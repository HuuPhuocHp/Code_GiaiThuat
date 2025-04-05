#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Term {
    double coefficient; // Hệ số
    int degree;         // Bậc
};

void sortTerms(vector<Term>& terms) {
    sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.degree < b.degree;
    });
}

int main() {
    vector<Term> terms = {{2.5, 3}, {1.0, 1}, {4.0, 2}};
    sortTerms(terms);

    cout << "Sap xep theo bac tang dan:\n";
    for (const Term& term : terms) {
        cout << term.coefficient << "x^" << term.degree << " ";
    }
    return 0;
}
