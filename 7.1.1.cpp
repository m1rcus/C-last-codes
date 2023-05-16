#include <iostream>
using namespace std;

int main(void) {
    int a = 8, b = 0, c = 0;
    cin >> b;
    try {
        if (b == 0) {
            throw "Your input is not valid, you can't divide by zero.";
        }
        c = a / b;
    } catch (const char* errorMessage) {
        cout << errorMessage << endl;
        return 0;
    }

    cout << c << endl;
    return 0;
}
