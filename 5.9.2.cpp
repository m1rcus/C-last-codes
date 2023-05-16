#include <iostream>
using namespace std;

class Square
{
private:
    double side;
    double area;

public:
    void set_side(double new_side)
    {
        if (new_side >= 0)
        {
            side = new_side;
            area = side * side;
        }
    }

    void print()
    {
        cout << "Square side: " << side << endl;
        cout << "Square area: " << area << endl;
    }
};

int main()
{
    Square square;
    square.set_side(5.0);
    square.print();

    square.set_side(-3.0); // Ignored due to negative value
    square.print();

    return 0;
}
