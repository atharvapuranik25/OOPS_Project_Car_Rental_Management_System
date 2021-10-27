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

            cout << "\n Enter number of Days: ";
            cin >> days;

            finalrentalfee = rentalfee * days;
        }
    };

    class rent : public customerInfo, public car
    {
    public:
        void showrent()
        {
            cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
            cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
            cout << "\t\t	| Customer Name:" << "-----------------|" << setw(10) << customer_name << " |" << endl;
            cout << "\t\t	| Phone Number:" << "------------------|" << setw(10) << customer_contact << " |" << endl;
            cout << "\t\t	| Car Brand :" << "--------------------|" << setw(10) << brand << " |" << endl;
            cout << "\t\t	| Car Model :" << "--------------------|" << setw(10) << model << " |" << endl;
            cout << "\t\t	| Year :" << "-------------------------|" << setw(10) << year << " |" << endl;
            cout << "\t\t	| Number Plate :" << "-----------------|" << setw(10) << numplate << " |" << endl;
            cout << "\t\t	| KM Driven :" << "--------------------|" << setw(10) << kmdriven << " |" << endl;
            cout << "\t\t	| Number of days :" << "---------------|" << setw(10) << days << " |" << endl;
            cout << "\t\t	| Your Rental Amount is :" << "--------|" << setw(10) << finalrentalfee << " |" << endl;
            cout << "\t\t	 ________________________________________________________" << endl;
            cout << "\n";
            cout << "\t\t	 ________________________________________________________" << endl;
            cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
            cout << "\t\t	 require an authorised signture #" << endl;
            cout << " " << endl;
            cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
            cout << "\t\t	You are advised to pay up the amount before due date." << endl;
            cout << "\t\t	Otherwise penelty fee will be applied" << endl;
            cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
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

        customerInfo customer1;
        customer1.setDetails();

        cout << endl;

        rent obj1;
        obj1.display();
        obj1.showrent();

        //system("CLS");

        /*
        // Create an object of Car 1
        car carObj1;
        carObj1.brand = "BMW";
        carObj1.model = "X5";
        carObj1.year = 2016;
        carObj1.numplate = "MP-2022";
        carObj1.kmdriven = 234;

        // Create an object of Car 2
        car carObj2;
        carObj2.brand = "AUDI";
        carObj2.model = "Q7";
        carObj2.year = 2011;
        carObj2.numplate = "MP-3405";
        carObj2.kmdriven = 201;

        // Create an object of Car 3
        car carObj3;
        carObj3.brand = "Suzuki";
        carObj3.model = "Swift VXI";
        carObj3.year = 2005;
        carObj3.numplate = "MP-1999";
        carObj3.kmdriven = 678;

        // Create an object of Car 4
        car carObj4;
        carObj4.brand = "Honda";
        carObj4.model = "City";
        carObj4.year = 2018;
        carObj4.numplate = "MP-0007";
        carObj4.kmdriven = 458;


        // Create an object of Car 5
        car carObj5;
        carObj5.brand = "Suzuki";
        carObj5.model = "SX-4";
        carObj5.year = 2004;
        carObj5.numplate = "MP-3673";
        carObj5.kmdriven = 578;


        // Create an object of Car 6
        car carObj6;
        carObj6.brand = "Ford";
        carObj6.model = "Endeavour";
        carObj6.year = 2019;
        carObj6.numplate = "MP-5619";
        carObj6.kmdriven = 234;

        // Create an object of Car 7
        car carObj7;
        carObj7.brand = "Hyundai";
        carObj7.model = "Creta";
        carObj7.year = 2017;
        carObj7.numplate = "MP-1111";
        carObj7.kmdriven = 312;

        // Print attribute values
        cout << setw(7) << "S.No." << setw(15) << "Brand" << setw(15) << "Model" << setw(15) << "Year" << setw(15) << "Number Plate" << setw(15) << "Km Driven" << endl;
        cout << setw(7) << "1.)" << setw(15) << carObj1.brand << setw(15) << carObj1.model << setw(15) << carObj1.year << setw(15) << carObj1.numplate << setw(15) << carObj1.kmdriven << endl;
        cout << setw(7) << "2.)" << setw(15) << carObj2.brand << setw(15) << carObj2.model << setw(15) << carObj2.year << setw(15) << carObj2.numplate << setw(15) << carObj2.kmdriven << endl;
        cout << setw(7) << "3.)" << setw(15) << carObj3.brand << setw(15) << carObj3.model << setw(15) << carObj3.year << setw(15) << carObj3.numplate << setw(15) << carObj3.kmdriven << endl;
        cout << setw(7) << "4.)" << setw(15) << carObj4.brand << setw(15) << carObj4.model << setw(15) << carObj4.year << setw(15) << carObj4.numplate << setw(15) << carObj4.kmdriven << endl;
        cout << setw(7) << "5.)" << setw(15) << carObj5.brand << setw(15) << carObj5.model << setw(15) << carObj5.year << setw(15) << carObj5.numplate << setw(15) << carObj5.kmdriven << endl;
        cout << setw(7) << "6.)" << setw(15) << carObj6.brand << setw(15) << carObj6.model << setw(15) << carObj6.year << setw(15) << carObj6.numplate << setw(15) << carObj6.kmdriven << endl;
        cout << setw(7) << "7.)" << setw(15) << carObj7.brand << setw(15) << carObj7.model << setw(15) << carObj7.year << setw(15) << carObj7.numplate << setw(15) << carObj7.kmdriven << endl;
        */
        
        return 0;
    }
