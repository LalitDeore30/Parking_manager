
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    string vehicle_type;
    string vehicle_name;
    int vehicle_number;

    Vehicle()
    {
        vehicle_number = -1;
    }
};

class Parking
{
public:
    const int size = 5;
    Vehicle arr[5];

    Parking() {}

    void insertAtPosition(string type, string name, int number, int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid position. Cannot insert vehicle at this position." << endl;
            return;
        }

        if (arr[idx].vehicle_number != -1)
        {
            cout << "Parking space is occupied." << endl;
            return;
        }

        arr[idx].vehicle_type = type;
        arr[idx].vehicle_name = name;
        arr[idx].vehicle_number = number;
        cout << "Vehicle parked successfully." << endl;
    }

    void exitParking(int vehicleNumber)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].vehicle_number == vehicleNumber)
            {
                arr[i].vehicle_type = "";
                arr[i].vehicle_name = "";
                arr[i].vehicle_number = -1;
                cout << "Vehicle with Number Plate " << vehicleNumber << " has exited from the parking." << endl;
                return;
            }
        }

        cout << "Vehicle with Number Plate " << vehicleNumber << " not found in the parking." << endl;
    }

    int searchParking(int vehicleNumber)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].vehicle_number == vehicleNumber)
            {
                return i + 1;
            }
        }
        cout << "Vehicle with Number Plate " << vehicleNumber << " not found in the parking." << endl;
        return -1;
    }

    int counting_vehicle()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].vehicle_number != -1)
            {
                count++;
            }
        }
        return count;
    }

    void showEmptyParkingSpaces()
    {
        cout << "Empty Parking Spaces: ";
        bool Found = false;

        for (int i = 0; i < size; i++)
        {
            if (arr[i].vehicle_number == -1)
            {
                if (Found)
                {
                    cout << ", ";
                }
                cout << i + 1;
                Found = true;
            }
        }

        if (!Found)
            cout << "None";

        cout << endl;
    }

    void display()
    {
        cout << "Parking List:" << endl;

        for (int i = 0; i < size; i++)
        {
            if (arr[i].vehicle_number != -1)
            {
                cout << "Vehicle Type: " << arr[i].vehicle_type << endl;
                cout << "Vehicle Name: " << arr[i].vehicle_name << endl;
                cout << "Vehicle Number (Number Plate): " << arr[i].vehicle_number << endl;
                cout << endl;
            }
            else
            {
                cout << "Empty" << endl;
                cout << endl;
            }
        }
    }
};

int main()
{
    Parking parking;
    int choice;

    while (true)
    {
        cout << "******** WELCOME TO CENTRAL MALL ********" << endl;
        cout << "Parking Menu" << endl;
        cout << "1. Park a vehicle (Starting from 0 th position)" << endl;
        cout << "2. Exit parking" << endl;
        cout << "3. Display parking list" << endl;
        cout << "4. Check how many vehicles are parked in the parking area" << endl;
        cout << "5. Show empty parking spaces" << endl;
        cout << "6. Check the position/parking number where you park your vehicle" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string type, name, option;
            int number, idx;

            cout << "Enter Vehicle Type (car/bike): ";
            cin >> type;

            if (type == "car")
            {
                cout << "You have to pay Rs.50 for the parking." << endl;
            }
            else if (type == "bike")
            {
                cout << "You have to pay Rs.30 for the parking." << endl;
            }
            cout << "Enter 'pay' to continue otherwise you are not allowed to park your vehicle : ";
            cin >> option;

            if (option == "pay")
            {
                cout << "Enter Vehicle Name: ";
                cin >> name;
                cout << "Enter Vehicle Number (Number Plate): ";
                cin >> number;
                cout << "Enter the parking idx where you want to park the vehicle: ";
                cin >> idx;
                parking.insertAtPosition(type, name, number, idx);
            }
            else
            {
                cout << "Payment not received." << endl;
            }
            break;
        }
        case 2:
        {
            int number;
            cout << "Enter Vehicle Number (Number Plate) to exit from parking: ";
            cin >> number;
            parking.exitParking(number);
            break;
        }
        case 3:
            parking.display();
            break;
        case 4:
            cout << "Number of vehicles parked: " << parking.counting_vehicle() << endl;
            break;
        case 5:
            parking.showEmptyParkingSpaces();
            break;
        case 6:
        {
            int number;
            cout << "Enter Vehicle Number (Number Plate) to check parking position: ";
            cin >> number;
            int position = parking.searchParking(number);
            cout << "Parking number: " << position - 1 << endl;
        }
        }
    }

    return 0;
}
