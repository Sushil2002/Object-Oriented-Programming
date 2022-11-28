// Assignment-11(OOP's)
// Vetor->Vector are same as dynamic arrays with abality to resize itself automatiaclly.Vector are placed in continous storage so that they can be accessed and treaversal using itreaction

// Problem Statement ->
// Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
class Student
{ // class
    // data types
    string name;
    string DOB;
    string tel_phn;

public:
    Student() // default Constructor
    {
        name = "";
        DOB = "";
        tel_phn = "";
    }
    void setdata()
    {
        cout << "Enter the Name-";
        cin.ignore();
        getline(cin, name);
        time_t ttime = time(nullptr);
        tm *local_time = localtime(&ttime);
        int year = 1900 + local_time->tm_year;
        int month = 1 + local_time->tm_mon;
        int day = local_time->tm_mday;
        string todayDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

        // exception handling for birthday
        while (true)
        {
            try
            {
                cout << "Enter Date Of Birth- ";
                getline(cin, DOB);
                int dayInt;
                int monthInt;
                int yearInt;
                stringstream dayStream, monthStream, yearStream; // used to convert string into an int
                dayStream << DOB.substr(0, 2);
                dayStream >> dayInt;
                monthStream << DOB.substr(3, 2);
                monthStream >> monthInt;
                yearStream << DOB.substr(6, 4);
                yearStream >> yearInt;
                if (DOB[2] != '/' || DOB[5] != '/')
                {
                    throw 0;
                }
                else if (yearInt > year)
                {
                    throw 0;
                }
                else if (yearInt == year && monthInt > month)
                {
                    throw 0;
                }
                else if (monthInt == month && dayInt > day && yearInt == year)
                {
                    throw 0;
                }
                break;
            }
            catch (int x)
            {
                cout << "Invalid date of birth!!!" << endl;
            }
        }
        while (true)
        {
            cout << "Enter your Telephone number: ";
            try
            {
                string temp;
                cin >> temp;
                if (temp.length() != 10)
                {
                    throw "Telephone number must 10 digit!!";
                }
                for (char i : temp)
                {
                    if (!isdigit(i))
                    {
                        throw "Telephnone number not must be charater!!";
                        break;
                    }
                }
                tel_phn = temp;
                break;
            }
            catch (const char *ex)
            {
                cout << *ex;
            }
            cout << "\nRecord Created !" << endl;
        }
        cout << "-------------------------" << endl;
    }
    void display()
    {
        cout << "-------------------------" << endl;
        cout << "Name is - " << name << endl;
        cout << "DOB is - " << DOB << endl;
        cout << "Telephone Number is - " << tel_phn << endl;
        cout << "-------------------------" << endl;
    }
    string name1()
    {
        return name;
    }
    ~Student(){}; // destructor
    static bool compareByname(const Student &a, const Student &b)
    {
        return a.name < b.name;
    }
};
int main()
{
    // vector are contioguous containers i.e they store their data on continuous memory
    Student s1;                                   // Object for class Student
    vector<Student /*Object_type*/> Student_list; // Container is an object that actually stores the data
    vector<Student>::iterator ptr;                // iterator is an object(like a pointer) that points to an element in containers.
    int ch;
    string sname;
    int Student_count = 0;
    do
    {
        int choice;
        system("color 0B"); // Color Changes
        cout << "\n***  MAIN MENU  ***" << endl;
        cout << "1.CREATE RECORD -" << endl;
        cout << "2.SERACHED RECORD -" << endl;
        cout << "3.DELETE RECORD -" << endl;
        cout << "4.DISPLAY ALL RECORD -" << endl;
        cout << "5.Sort" << endl;
        cout << "\nEnter the Choice -";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            s1.setdata();
            Student_list.push_back(s1);
            Student_count++;
            break;
        case 2:
            cout << "Enter the Name to be Searched -";
            cin.ignore();
            getline(cin, sname);
            cout << endl;
            for (ptr = Student_list.begin(); ptr != Student_list.end(); ptr++)
            {
                if (sname == ptr->name1())
                {
                    cout << "Record Found!" << endl;
                    ptr->display();
                    break;
                }
                else
                {
                    cout << "Record Was Not Created!" << endl;
                }
            }
            break;
        case 4:
            cout << "***   Student Record Are   ***" << endl
                 << endl;
            for (ptr = Student_list.begin(); ptr != Student_list.end(); ptr++)
            {
                ptr->display();
                cout << endl;
            }
            break;
        case 3:
            cout << "***   Delete Student Record   ***" << endl
                 << endl;
            cout << "Enter the Name to Be Deleted-";
            cin.ignore();
            getline(cin, sname);
            for (ptr = Student_list.begin(); ptr != Student_list.end(); ptr++)
            {
                if (sname == ptr->name1())
                {
                    Student_list.erase(ptr);
                    ptr->~Student();
                    Student_count--;
                    cout << "Record Deleted Succesfully!" << endl;
                    break;
                }
                else
                {
                    cout << "Record Was Not Created For Student!" << endl;
                }
            }
        case 5:
            sort(Student_list.begin(), Student_list.end(), Student::compareByname);
            break;
        }

    } while (ch != 6);
    return 0;
}