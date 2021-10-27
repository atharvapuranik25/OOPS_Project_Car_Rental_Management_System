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
        
        customerInfo()
        {
            customer_name = "NULL";
            customer_contact = 0;
        }

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
        string numplate;
        int kmdriven;
        int rentalfee;
        int days;
        int carnum;
        int finalrentalfee;

        car()
        {
            brand = "NULL";
            model = "NULL";
            year = 0;
            numplate = "NULL";
            kmdriven = 0;
            rentalfee = 0;
            days = 0;
            carnum = 0;
            finalrentalfee = 0;
        }

        void display()
        {
            cout << setw(7) << "S.No." << setw(15) << "Brand" << setw(15) << "Model" << setw(15) << "Year" << setw(15) << "Number Plate" << setw(15) << "Km Driven" << setw(15) << "Rental Fee" << endl;
            cout << setw(7) << "1.)" << setw(15) << "BMW" << setw(15) << "X5" << setw(15) << "2016" << setw(15) << "MP-2022" << setw(15) << "234" << setw(15) << "1100" << endl;
            cout << setw(7) << "2.)" << setw(15) << "Audi" << setw(15) << "Q7" << setw(15) << "2011" << setw(15) << "MP-3405" << setw(15) << "201" << setw(15) << "1000" << endl;
            cout << setw(7) << "3.)" << setw(15) << "Suzuki" << setw(15) << "Swift VXI" << setw(15) << "2005" << setw(15) << "MP-1999" << setw(15) << "678" << setw(15) << "600" << endl;
            cout << setw(7) << "4.)" << setw(15) << "Honda" << setw(15) << "City" << setw(15) << "2018" << setw(15) << "MP-0007" << setw(15) << "458" << setw(15) << "800" << endl;
        
            cout << "\n\nChoose a Car from the above option: ";
            cin >> carnum;

            if (carnum == 1)
            {
                brand = "BMW";
                model = "X5";
                year = 2016;
                numplate = "MP-2022";
                kmdriven = 234;
                rentalfee = 1100;
            }
            else if (carnum == 2)
            {
                brand = "Audi";
                model = "Q7";
                year = 2011;
                numplate = "MP-3405";
                kmdriven = 201;
                rentalfee = 1000;
            }
            else if (carnum == 3)
            {
                brand = "Suzuki";
                model = "Swift VXI";
                year = 2005;
                numplate = "MP-1999";
                kmdriven = 678;
                rentalfee = 600;
            }
            else if (carnum == 4)
            {
                brand = "Honda";
                model = "City";
                year = 2018;
                numplate = "MP-0007";
                kmdriven = 458;
                rentalfee = 800;
            }
            else
            {
                cout << "Invalid Input";
            }

            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Number PLate: " << numplate << endl;
            cout << "KM Driven: " << kmdriven << endl;
            cout << "Rental Fee: " << rentalfee << endl;

            cout << "\nEnter number of Days: ";
            cin >> days;

            finalrentalfee = rentalfee * days;
        }
    };

    class rent : public customerInfo, public car
    {
    public:
        void showrent()
        {
            cout << "\n                 Car Rental - Customer Invoice                  " << endl;
            cout << "///////////////////////////////////////////////////////////" << endl;
            cout << "| Customer Name:" << "-----------------|" << setw(15) << customer_name << " |" << endl;
            cout << "| Phone Number:" << "------------------|" << setw(15) << customer_contact << " |" << endl;
            cout << "| Car Brand :" << "--------------------|" << setw(15) << brand << " |" << endl;
            cout << "| Car Model :" << "--------------------|" << setw(15) << model << " |" << endl;
            cout << "| Year :" << "-------------------------|" << setw(15) << year << " |" << endl;
            cout << "| Number Plate :" << "-----------------|" << setw(15) << numplate << " |" << endl;
            cout << "| KM Driven :" << "--------------------|" << setw(15) << kmdriven << " |" << endl;
            cout << "| Number of days :" << "---------------|" << setw(15) << days << " |" << endl;
            cout << "| Your Rental Amount is :" << "--------|" << setw(15) << finalrentalfee << " |" << endl;
            cout << " ________________________________________________________" << endl;
            cout << endl;
            cout << " ________________________________________________________" << endl;
            cout << " # This is a computer generated invoce and it does not" << endl;
            cout << " require an authorised signture #" << endl;
            cout << endl;
            cout << "///////////////////////////////////////////////////////////" << endl;
            cout << "You are advised to pay up the amount before due date." << endl;
            cout << "Otherwise penelty fee will be applied" << endl;
            cout << "///////////////////////////////////////////////////////////" << endl;
        }
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

        rent obj1;

        obj1.setDetails();

        system("CLS");
        
        obj1.display();

        system("CLS");

        obj1.showrent();
        
        return 0;
    }
