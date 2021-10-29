    #include <iostream>
    #include <cstring>
    #include <stdlib.h>
    #include <iomanip>
    #include <fstream>
    #include <stdio.h>

    using namespace std;

    class customerInfo
    {
    public:
        char customer_name[20];
        char customer_contact[10];
        
        customerInfo()
        {
            strcpy_s(customer_name, "no name");
            customer_contact[10] = 0;
        }
        
        void setDetails()
        {
            cout << "\t\t\tName: ";
            cin >> customer_name;
            cout << "\t\t\tPhone Number: ";
            cin >> customer_contact;
        }
        void getDetails()
        {
            cout << "\n\t\t\tName: " << customer_name;
            cout << "\n\t\t\tPhone Number: " << customer_contact<<endl;
        }

    };

    class car
    {
    public:
        char brand[20];
        char model[10];
        int year;
        char numplate[6];
        int kmdriven;
        int rentalfee;
        int days;
        int carnum;
        int finalrentalfee;

        car()
        {
            strcpy_s(brand, "no brand");
            strcpy_s(model, "null");
            year = 0;
            strcpy_s(numplate, "null");
            kmdriven = 0;
            rentalfee = 0;
            days = 0;
            carnum = 0;
            finalrentalfee = 0;
        }

        void getCarInfo()
        {
            cout << "Enter Brand: ";
            cin >> brand;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Number Plate: ";
            cin >> numplate;
            cout << "Enter KM Driven: ";
            cin >> kmdriven;
            cout << "Enter Rental Fee: ";
            cin >> rentalfee;
        }

        void showCarInfo()
        {
            cout << "\n" << brand << " " << model << " " << year << " " << numplate << " " << kmdriven << " " << rentalfee;
        }

        void storeCar()
        {
            ofstream fout;
            fout.open("carlist.txt",ios::app|ios::binary);
            fout.write((char*)this,sizeof(*this));
            fout.close();
        }

        void viewAllCars()
        {
            ifstream fin;
            fin.open("carlist.txt", ios::in | ios::binary);
            if (!fin)
            {
                cout << "File Not Found";
                exit(0);
            }
            else
            {
                fin.read((char*)this,sizeof(*this));
                while (!fin.eof())
                {
                    showCarInfo(); 
                    fin.read((char*)this, sizeof(*this));
                }
                fin.close();
            }
        }

        void searchCar(char* t)
        {
            ifstream fin;
            fin.open("carlist.txt", ios::in | ios::binary);
            if (!fin)
            {
                cout << "\nFile not found";
                exit(0);
            }
            else
            {
                int flag = 0;
                fin.read((char*)this, sizeof(*this));
                while (!(fin.eof()) && flag==1)
                {
                    if (!strcmp(t, this->brand))
                    {
                        showCarInfo();
                        fin.read((char*)this, sizeof(*this));
                    }
                    int pos = fin.tellg();
                    fin.seekg(pos);
                    fin.read((char*)this, sizeof(*this));
                    flag++;
                }
                
                fin.close();
            }
        }

        void deleteCar(char* t)
        {
            ifstream fin;
            ofstream fout;
            fin.open("carlist.txt", ios::in | ios::binary);
            if (!fin)
            {
                cout << "\nFile not found";
                exit(0);
            }
            else
            {
                fout.open("tempfile.txt", ios::out | ios::binary);
                fin.read((char*)this, sizeof(*this));
                while (!fin.eof())
                {
                    if (strcmp(brand, t))
                    {
                        fout.write((char*)this, sizeof(*this));
                    }
                    fin.read((char*)this, sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("carlist.txt");
                rename("tempfile.txt", "carlist.txt");
            }
        }
    };

    class rent : public customerInfo, public car
    {
    public:
        void showrent()
        {
            finalrentalfee = rentalfee * days;

            cout << "\n\t\t\t                 Car Rental - Customer Invoice                  " << endl;
            cout << "\t\t\t///////////////////////////////////////////////////////////" << endl;
            cout << "\t\t\t| Customer Name:" << "-----------------|" << setw(15) << customer_name << " |" << endl;
            cout << "\t\t\t| Phone Number:" << "------------------|" << setw(15) << customer_contact << " |" << endl;
            cout << "\t\t\t| Car Brand :" << "--------------------|" << setw(15) << brand << " |" << endl;
            cout << "\t\t\t| Car Model :" << "--------------------|" << setw(15) << model << " |" << endl;
            cout << "\t\t\t| Year :" << "-------------------------|" << setw(15) << year << " |" << endl;
            cout << "\t\t\t| Number Plate :" << "-----------------|" << setw(15) << numplate << " |" << endl;
            cout << "\t\t\t| KM Driven :" << "--------------------|" << setw(15) << kmdriven << " |" << endl;
            cout << "\t\t\t| Number of days :" << "---------------|" << setw(15) << days << " |" << endl;
            cout << "\t\t\t| Your Rental Amount is :" << "--------|" << setw(15) << finalrentalfee << " |" << endl;
            cout << "\t\t\t ________________________________________________________" << endl;
            cout << endl;
            cout << "\t\t\t| Your Total Rental Amount :" << "-----|" << setw(15) << finalrentalfee << " |" << endl;
            cout << "\t\t\t ________________________________________________________" << endl;
            cout << "\t\t\t # This is a computer generated invoce and it does not" << endl;
            cout << "\t\t\t require an authorised signture #" << endl;
            cout << endl;
            cout << "\t\t\t///////////////////////////////////////////////////////////" << endl;
            cout << "\t\t\tYou are advised to pay up the amount before due date." << endl;
            cout << "\t\t\tOtherwise penelty fee will be applied" << endl;
            cout << "\t\t\t///////////////////////////////////////////////////////////" << endl;
        }
    };

    class password
    {
    public:
        int ps;

        password()
        {
            cout << "\n\n\t\t\tEnter Password: ";
            cin >> ps;
            if (ps == 12345) {
                cout << "\n\t\t\tAccess Granted \n\n";
            }
            else {
                cout << "\n\t\t\tIncorrect Password\n\n";
                exit(0);
            }
        }
    };

    int main()
    {
        cout << "\t\t\t##########################################################################"<<endl;
        cout << "\t\t\t##                                                                      ##" << endl;
        cout << "\t\t\t##                            WELCOME TO                                ##" << endl;
        cout << "\t\t\t##                        CAR RENTAL SERVICE                            ##" << endl;
        cout << "\t\t\t##                                                                      ##" << endl;
        cout << "\t\t\t##########################################################################"<<endl;

        password myObj;
        int choice;

        cout << "\n\t\t\tChoose One-" << endl;
        cout << "\t\t\t1. Rent a Car" << endl;
        cout << "\t\t\t2. Give Car" << endl;
        cout << "\t\t\tEnter 1 or 2: ";
        cin >> choice;

        if (choice == 1)
        {
            system("CLS");
            rent obj1;
            obj1.setDetails();
            system("CLS");
            cout << "List of Available Cars-\n\n";
            cout << "Brand\tModel\tYear\tNumber Plate\tKM Driven\tRental Fee\n";
            obj1.viewAllCars();
            cout << "\n\nEnter the Brand of the Car you would like to Rent: ";

            char brand[20];
            cin >> brand;
            obj1.searchCar(brand);
            cout << endl;
            cout << "Brand: "<< obj1.brand << endl;
            cout << "Model: " << obj1.model << endl;
            cout << "Year: " << obj1.year << endl;
            cout << "Number Plate: " << obj1.numplate << endl;
            cout << "KM Driven: " << obj1.kmdriven << endl;
            cout << "Rental Fee: " << obj1.rentalfee << endl;

            cout << "\nEnter number of days you want to rent the car for: ";
            cin >> obj1.days;

            system("CLS");
            obj1.showrent();
            //obj1.deleteCar(brand);
        }

        else if (choice == 2)
        {
            system("CLS");
            rent obj1;
            obj1.setDetails();
            system("CLS");
            cout << "Enter Details of the Car-\n" << endl;
            obj1.getCarInfo();
            obj1.storeCar();
            cout << "\n\nCar Details Stored Successfully..." << endl;
        }

        else
        {
            cout << "Invalid Input";
        }
        

        /*
        rent obj1;

        obj1.setDetails();

        system("CLS");
        
        obj1.display();

        system("CLS");

        obj1.showrent();
        */
        return 0;
    }
