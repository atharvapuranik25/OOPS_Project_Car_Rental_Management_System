    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <iomanip>

    using namespace std;

    class customerInfo //add more info
    {
    public:
        string customer_name;
        int customer_contact;
    public:
        void setDetails()
        {
            cout << "Name: ";
            cin >> customer_name;
            cout << "Phone Number: ";
            cin >> customer_contact;
        }
        void getDetails()
        {
            cout << "\nName: " << customer_name;
            cout << "\nPhone Number: " << customer_contact<<endl;
        }
    };

    class car
    {
    public:
        string brand;
        string model;
        int year;
    };

    class welcome //welcome class
    {
    public:
        int password;

        welcome()
        {
            cout << "Welcome to\nCar Rental Service";   //make this interesting
            cout << "\n\nEnter Password: ";
            cin >> password;
            if (password == 12345) {
                cout << "Access Granted \n\n";
            }
            else {
                cout << "Try Again \n\n";
            }
        }
    };

    int main()
    {
        welcome myObj;

        customerInfo customer1;
        customer1.setDetails();
        customer1.getDetails();

        //system("CLS");

        // Create an object of Car
        car carObj1;
        carObj1.brand = "BMW";
        carObj1.model = "X5";
        carObj1.year = 1999;

        // Create another object of Car
        car carObj2;
        carObj2.brand = "Ford";
        carObj2.model = "Mustang";
        carObj2.year = 1969;

        // Print attribute values
        cout << setw(7) << "S.No." << setw(15) << "Brand" << setw(15) << "Model" << setw(15) << "Year" << endl;
        cout << setw(7) << "1." << setw(15) << carObj1.brand << setw(15) << carObj1.model << setw(15) << carObj1.year << endl;
        cout << setw(7) << "2." << setw(15) << carObj2.brand << setw(15) << carObj2.model << setw(15) << carObj2.year << endl;
        return 0;
    }
