#include <iostream>
using namespace std;

const int InvalidArgument = 222;

float internaldiv(float arg1, float arg2) {
    if (arg1 < 0 || arg2 == 0)
        throw InvalidArgument;
    return arg1 / arg2;
}

bool div(float& res, float arg1, float arg2) {
    try {
        res = internaldiv(arg1, arg2);
        return true;
    } catch (int error) {
        if (error == InvalidArgument)
            cout << "Your input is not valid." << endl;
        return false;
    }
}

int main(void) {
    float r, a, b;
    while (cin >> a) {
        cin >> b;
        if (div(r, a, b))
            cout << r << endl;
        else
            cout << "Are you kidding me?" << endl;
    }
    return 0;
}
