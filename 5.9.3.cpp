#include <iostream>
using namespace std;

class AdHocSquare
{
public:
    AdHocSquare(double side)
    {
        set_side(side);
    }

    void set_side(double new_side)
    {
        if (new_side >= 0)
        {
            side = new_side;
        }
    }

    double get_area()
    {
        return side * side;
    }

private:
    double side;
};

class LazySquare
{
public:
    LazySquare(double side)
    {
        set_side(side);
    }

    void set_side(double new_side)
    {
        if (new_side >= 0)
        {
            side = new_side;
            side_changed = true;
        }
    }

    double get_area()
    {
        if (side_changed)
        {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

private:
    double side;
    double area;
    bool side_changed;
};

int main()
{
    AdHocSquare adhoc_square(5.0);
    cout << "AdHocSquare area: " << adhoc_square.get_area() << endl;

    LazySquare lazy_square(5.0);
    cout << "LazySquare area: " << lazy_square.get_area() << endl;

    lazy_square.set_side(7.0);
    cout << "LazySquare area (after side change): " << lazy_square.get_area() << endl;

    return 0;
}
