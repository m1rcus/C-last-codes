#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() { return id; }
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking()
{
    id = 0;
    capacity = 0;
    reserved = 0;
}

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
    FlightBooking booking[10];

    string command;
    while (command != "quit")
    {
        cout << "What would you like to do? ";
        getline(cin, command);

        string operation = command.substr(0, command.find(" "));

        if (operation == "create") {
            int id = stoi(command.substr(command.find(" ") + 1));
            int capacity;
            cout << "Enter capacity for flight " << id << ": ";
            cin >> capacity;
            cin.ignore();

            booking[id] = FlightBooking(id, capacity, 0);
        }
        else if (operation == "delete") {
            int id = stoi(command.substr(command.find(" ") + 1));
            booking[id] = FlightBooking();
        }
        else if (operation == "add") {
            int id = stoi(command.substr(command.find(" ") + 1));
            int number_of_seats;
            cout << "Enter the number of seats to add to flight " << id << ": ";
            cin >> number_of_seats;
            cin.ignore();

            if (booking[id].getId() == 0) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }
            else if (!booking[id].reserveSeats(number_of_seats)) {
                cout << "Cannot perform this operation: capacity reached" << endl;
            }
        }
        else if (operation == "cancel") {
            int id = stoi(command.substr(command.find(" ") + 1));
            int number_of_seats;
            cout << "Enter the number of seats to cancel from flight " << id << ": ";
            cin >> number_of_seats;
            cin.ignore();

            if (booking[id].getId() == 0) {
                cout << "Cannot perform
