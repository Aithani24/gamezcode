#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system("cls")
using namespace std;

void Login();
void Registration();
void forget();

int main()
{
    int choice;
    while (true) // Infinite loop for menu
    {
        cout << "\t\t\t\t--------  REGISTRATION AND LOGIN  --------\n\n\n\n";
        cout << "\t\t\t\t  --------         WELCOME      --------\n\n\n\n";
        cout << "\t 1. Press 1 to LOGIN\n";
        cout << "\t 2. Press 2 for REGISTRATION\n";
        cout << "\t 3. Press 3 in case you forgot password\n";
        cout << "\t 4. Press 4 to EXIT\n";
        cout << "\t Please Enter one choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Login();
            break;
        case 2:
            Registration();
            break;
        case 3:
            forget();
            break;
        case 4:
            cout << "\t Thank you for using the system! Goodbye.\n";
            return 0;
        default:
            system("cls");
            cout << "\t Invalid choice! Please select from the options given above.\n";
        }
    }
}

void Login()
{
    int count = 0;
    string userID, password, id, pass;
    system("cls");
    cout << "\t Please enter the username and password:\n";
    cout << "\t USERNAME: ";
    cin >> userID;
    cout << "\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userID && pass == password)
        {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "\n"
             << userID << ", your LOGIN is successful!\nThank you for logging in!\n";
    }
    else
    {
        cout << "\n LOGIN ERROR: Please check your username and password.\n";
    }
}

void Registration()
{
    string ruserID, rpassword;
    system("cls");
    cout << "\t Enter the username: ";
    cin >> ruserID;
    cout << "\t Enter the password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << endl;
    f1.close();

    system("cls");
    cout << "Registration is successful!\n";
}

void forget()
{
    int option;
    system("cls");
    cout << "\t Forgot your password? No worries!\n";
    cout << "1. Press 1 to search for your ID by username.\n";
    cout << "2. Press 2 to go back to the main menu.\n";
    cout << "\t Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\tEnter the username you remember: ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
                cout << "\nYour account is found!\n";
                cout << "Your password is: " << spass << endl;
                break;
            }
        }
        f2.close();

        if (count == 0)
        {
            cout << "\nSorry! Your account was not found.\n";
        }
        break;
    }
    case 2:
        return; // Return to main menu
    default:
        cout << "\t Invalid choice! Please try again.\n";
        forget();
    }
}
