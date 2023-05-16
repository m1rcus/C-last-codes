#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder
{
public:
    ShopItemOrder(const string& item_name, double unit_price, int quantity)
        : item_name(item_name), unit_price(unit_price), quantity(quantity)
    {
    }

    string get_item_name() const
    {
        return item_name;
    }

    double get_unit_price() const
    {
        return unit_price;
    }

    int get_quantity() const
    {
        return quantity;
    }

    void set_item_name(const string& new_name)
    {
        item_name = new_name;
    }

    void set_unit_price(double new_price)
    {
        unit_price = new_price;
    }

    void set_quantity(int new_quantity)
    {
        quantity = new_quantity;
    }

    double get_total_price() const
    {
        return unit_price * quantity;
    }

    void print_order() const
    {
        cout << "Order Details:" << endl;
        cout << "Item: " << item_name << endl;
        cout << "Unit Price: $" << unit_price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: $" << get_total_price() << endl;
    }

private:
    string item_name;
    double unit_price;
    int quantity;
};

int main()
{
    ShopItemOrder order("T-Shirt", 19.99, 2);
    order.print_order();

    order.set_quantity(4);
    order.set_unit_price(24.99);
    order.print_order();

    return 0;
}

