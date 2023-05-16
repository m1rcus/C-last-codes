#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
    int gcd(int a, int b);
};

Fraction::Fraction(int numerator, int denominator) {
    int gcdValue = gcd(abs(numerator), abs(denominator));

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    this->numerator = numerator / gcdValue;
    this->denominator = denominator / gcdValue;
}

string Fraction::toString() {
    if (denominator == 1) {
        return to_string(numerator);
    } else if (abs(numerator) > denominator) {
        int wholePart = numerator / denominator;
        int remainder = abs(numerator) % denominator;

        return to_string(wholePart) + " " + to_string(remainder) + "/" + to_string(denominator);
    } else {
        return to_string(numerator) + "/" + to_string(denominator);
    }
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int Fraction::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int num, den;
    string input;
    cout << "Enter the fraction in the form '[numerator] / [denominator]': ";
    getline(cin, input);

    size_t slashIndex = input.find("/");
    num = stoi(input.substr(0, slashIndex));
    den = stoi(input.substr(slashIndex + 1));

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
