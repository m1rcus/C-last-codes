#include <iostream>
#include <string>
using namespace std;

class GymMember {
public:
    GymMember(int id, string name);
    GymMember();
    void printStatus();
    bool extendSubscription(int number_of_months);
    bool cancelSubscription();
    int getId() { return id; }
private:
    int id;
    string name;
    int subscriptionMonths;
};

GymMember::GymMember()
{
    id = 0;
    name = "";
    subscriptionMonths = 0;
}

GymMember::GymMember(int id, string name)
    : id(id), name(name), subscriptionMonths(0)
{
}

void GymMember::printStatus()
{
    cout << "Member " << id << " : " << name << ", subscription valid for " << subscriptionMonths << " months" << endl;
}

bool GymMember::extendSubscription(int number_of_months)
{
    if (subscriptionMonths == 0) {
        return false;
    }

    subscriptionMonths += number_of_months;
    return true;
}

bool GymMember::cancelSubscription()
{
    if (subscriptionMonths == 0) {
        return false;
    }

    subscriptionMonths = 0;
    return true;
}

int main()
{
    GymMember members[10];

    string command;
    while (command != "quit")
    {
        cout << "What would you like to do? ";
        getline(cin, command);

        string operation = command.substr(0, command.find(" "));

        if (operation == "create") {
            int id = stoi(command.substr(command.find(" ") + 1, command.rfind(" ") - command.find(" ") - 1));
            string name = command.substr(command.rfind(" ") + 1);

            members[id] = GymMember(id, name);
        }
        else if (operation == "delete") {
            int id = stoi(command.substr(command.find(" ") + 1));
            members[id] = GymMember();
        }
        else if (operation == "extend") {
            int id = stoi(command.substr(command.find(" ") + 1, command.rfind(" ") - command.find(" ") - 1));
            int number_of_months = stoi(command.substr(command.rfind(" ") + 1));

            if (members[id].getId() == 0) {
                cout << "Cannot perform this operation: member " << id << " not found" << endl;
            }
            else if (!members[id].extendSubscription(number_of_months)) {
                cout << "Cannot perform this operation: subscription is not active" << endl;
            }
        }
        else if (operation == "cancel") {
            int id = stoi(command.substr(command.find(" ") + 1));

            if (members[id].getId() == 0) {
                cout << "Cannot perform this operation: member " << id << " not found" << endl;
            }
            else if (!members[id].cancelSubscription()) {
                cout << "Cannot perform this operation: subscription is not active" << endl;
            }
        }
        else if (operation == "quit") {
            break;
        }
    }

    return 0;
}
