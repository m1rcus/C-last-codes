#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity), reserved(reserved)
{
    if (reserved < 0) {
        this->reserved = 0;
    }
    else if (reserved > capacity) {
        this->reserved = capacity;
    }
    else {
        this->reserved = reserved;
    }
}

void FlightBooking::printStatus()
{
    double percentage = static_cast<double>(reserved) / capacity * 100;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << fixed << setprecision(2) << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
    int total_seats = reserved + number_of_seats;
    double max_capacity = capacity * 1.05;

    if (total_seats > max_capacity) {
        return false;
    }

    reserved = total_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats)
{
    int remaining_seats = reserved - number_of_seats;

    if (remaining_seats < 0) {
        return false;
    }

    reserved = remaining_seats;
    return true;
}

int main()
{
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);

    string command;
    while (command != "quit")
    {
        booking.printStatus();
        cout << "What would you like to do? ";
        getline(cin, command);

        string operation = command.substr(0, command.find(" "));
        int number_of_seats = stoi(command.substr(command.find(" ") + 1));

        if (operation == "add") {
            if (!booking.reserveSeats(number_of_seats)) {
                cout << "Cannot perform this operation" << endl;
            }
        }
        else if (operation == "cancel") {
            if (!booking.cancelReservations(number_of_seats)) {
                cout << "Cannot perform this operation" << endl;
            }
        }
    }

    return 0;
