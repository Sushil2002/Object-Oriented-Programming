/*Develop a program in C++ to create a database of student’s  information  system  containing  the following  information:  Name,  Roll  number, Class,  Division,  Date  of  Birth,  Blood  group, Contact  address,  Telephone  number,  Driving license no. and other. Construct the database with suitable  member  functions.  Make  use  of constructor, default constructor, copy constructor, destructor,  static  member  functions,  friend  class, this  pointer,  inline  code  and  dynamic  memory allocation  operators-new  and  delete  as  well  as exception handling.
1.constructor  2.default/copy constructor 3.destructor  4.static member function  5.friend class 6.this pointer 7.inline code  8.new & dlelete operator  9.Inline function
*/

#include <iostream>
#include <cstring>
#include <sstream>
#include <ctime>

using namespace std;

class student //  creating a class student
{
    string *name;
    string *Roll_no;
    string *cls, *div, *dob, *blood_grp;
    string *cnt_address;
    string *tel_no, *Dl_no;
    static int count; // static members are initialized to zero

public:
    student();          // Declaring  constructor
    ~student();         // Destructor
    student(student &); // copy constructor

    // Declaring member functions
    void inp_data();
    void display_data();
    void update_data();
    void delete_data();

    static int showcount()
    {
        return count;
    }
};

student ::student() // defining  constructor
{
    name = new string;
    Roll_no = new string;
    cls = new string;
    div = new string;
    dob = new string;
    blood_grp = new string;
    cnt_address = new string;
    tel_no = new string;
    Dl_no = new string;

    count++;
    cout << "Constructor called" << endl;
}

student ::~student() //  defining destructor
{
    delete name;
    delete Roll_no;
    delete cls;
    delete dob;
    delete div;
    delete blood_grp;
    delete cnt_address;
    delete tel_no;
    delete Dl_no;
    cout << "Destructor Called" << endl;
}

student::student(student &obj) // copy constructor
{
    this->name = obj.name;
    this->Roll_no = obj.Roll_no;
    this->cls = obj.cls;
    this->dob = obj.dob;
    this->div = obj.div;
    this->blood_grp = obj.blood_grp;
    this->cnt_address = obj.cnt_address;
    this->tel_no = obj.tel_no;
    this->Dl_no = obj.Dl_no;
}

void student ::inp_data() // defining function get_data
{
    string input;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, input);
    *name = input;

    cout << "Enter your roll no ." << endl;

    cin >> *Roll_no;

    cout << "Enter your Class: ";
    cin >> *cls;
    cout << "Enter your division: ";
    cin >> *div;

    while (true)
    {
        cout << "Enter your tel_no." << endl;
        cin >> input;
        if (input.length() != 10)
        {

            cout << "Invalid telephone no" << endl;
            continue;
        }
        for (char i : input)
        {
            if (!isdigit(i))
            {
                cout << "Telephone no. must be a digit " << endl;
                break;
            }
        }
        *tel_no = input;
        break;
    }
    cout << "Enter your Driving license number: ";
    cin >> *Dl_no;
    cout << "Enter your blood group: ";
    while (true)
    {
        cin >> *blood_grp;
        if (*blood_grp == "A+" || *blood_grp == "B+" || *blood_grp == "A-" || *blood_grp == "B-" || *blood_grp == "AB+" || *blood_grp == "AB-" || *blood_grp == "O+" || *blood_grp == "O-")
            break;
        else
        {
            cout << "Invalid blood group entered" << endl;
            cout << "Enter again" << endl;
        }
    }

    cout << "Enter your Contact address: ";
    cin.ignore();
    getline(cin, input);
    *cnt_address = input;

    // Code to find today's date
    time_t ttime = time(nullptr);
    tm *local_time = localtime(&ttime);
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    int day = local_time->tm_mday;
    string todayDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
    while (true)
    {
        try
        {
            cout << "Enter your birthday (dd/mm/yyyy): ";
            cin >> input;
            int dayInt;
            int monthInt;
            int yearInt;
            stringstream dayStream, monthStream, yearStream; // used to convert string into an int
            dayStream << input.substr(0, 2);
            dayStream >> dayInt;
            monthStream << input.substr(3, 2);
            monthStream >> monthInt;
            yearStream << input.substr(6, 4);
            yearStream >> yearInt;
            if (input[2] != '/' || input[5] != '/')
            {
                throw "Invalid birthdate format";
            }

            else if (yearInt > year)
            {
                throw "Invalid birthdate";
            }
            else if (yearInt == year && monthInt > month)
            {
                throw "Invalid birthdate";
            }
            else if (monthInt == month && dayInt > day && yearInt == year)
            {
                throw "Invalid birthdate";
            }
            else if (monthInt == 00 && dayInt == 00 && yearInt == 00)
            {
                throw "Invalid birthdate";
                ;
            }
            *dob = input;
            break;
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
}

void student ::display_data() // defining function display_data
{

    cout << "Name is " << *this->name << endl;
    cout << "Roll no is " << *this->Roll_no << endl;
    cout << "Class is " << *this->cls << endl;
    cout << "Division is " << *this->div << endl;
    cout << "Telephone no is " << *this->tel_no << endl;
    cout << "DLNo is " << *this->Dl_no << endl;
    cout << "Blood group is " << *this->blood_grp << endl;
    cout << "Contact address is " << *this->cnt_address << endl;
    cout << "Birthday is " << *this->dob << endl;
}

int student::count = 0;
void student::update_data() // defining function update_data
{
    string input;
    int ch;
    cout << "For updating previous name press 1 else 0" << endl;
    cin >> ch;
    cin.ignore();
    if (ch == 1)
    {
        cout << "Enter new name" << endl;
        getline(cin, input);
        *name = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous Roll_no .press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new Roll_no " << endl;
        cin >> input;
        *Roll_no = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }

    cout << "For updating previous class press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new class " << endl;
        cin >> input;
        *cls = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous division press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new divison " << endl;
        cin >> input;
        *div = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous telephone no. press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new telephone no. " << endl;
        cin >> input;
        *tel_no = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous driving license no. press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new driving licenses no ." << endl;
        cin >> input;
        *Dl_no = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous blood group press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new blood group " << endl;
        cin >> *blood_grp;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous contact address  press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new address " << endl;
        cin.ignore();
        getline(cin, input);
        *cnt_address = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
    cout << "For updating previous date of birth press 1 else 0" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Enter new date of birth " << endl;
        cin >> input;
        *dob = input;
    }
    else if (ch == 0)
    {
        cout << "Previous data retrieved " << endl;
    }
}

void student ::delete_data() // defining function delete_data
{
    delete Roll_no,
        delete div,
        delete tel_no,
        delete Dl_no,
        delete name,
        delete cls,
        delete blood_grp,
        delete cnt_address,
        delete dob;
    count--;
}

int main()
{
    student *s[50]; // pointer to object
    int ch;
    int position;
    do
    {
        cout << "------MENU------" << endl;
        cout << "1. Input details of object" << endl;
        cout << "2. display Data of the object" << endl;
        cout << "3. Copy details of an object to another " << endl; // currently giving error
        cout << "4. Update details of an object " << endl;
        cout << "5. Delete the object" << endl;
        cout << "0. End" << endl;
        cout << "No of objects present at this time is " << student::showcount() << endl;
        cout << "Which operation do you want to perform ? ";
        cin >> ch;
        if (ch == 1)
        {

            s[student::showcount() - 1] = new student;
            cout << "Enter the position of object to Input details " << endl;
            cin >> position;

            {

                cout << "Getting details of object at position " << position << endl;
                s[position - 1]->inp_data(); // pointer to object uses -> referencing operator
            }
        }
        else if (ch == 2)
        {

            cout << "Enter the position of student whose data needs to be displayed" << endl;
            cin >> position;
            if (student::showcount() < position)
            {
                cout << "User not found " << endl;
            }

            else
            {

                s[position - 1]->display_data();
            }
        }

        else if (ch == 3)
        {
            int p1;
            cout << "Enter the position of object whose details are to be copied :" << endl;
            cin >> p1;
            if (student::showcount() < p1)
            {
                cout << "User not found " << endl;
            }

            else
            {
                s[student::showcount()] = new student;
                s[student::showcount() - 1] = s[p1 - 1];
            }
        }
        else if (ch == 4)
        {
            cout << "Enter position at which you want to update data" << endl;
            cin >> position;
            if (student::showcount() < position)
            {
                cout << "User not found" << endl;
            }
            else
            {
                s[position - 1]->update_data();
            }
        }

        else if (ch == 5)
        {
            cout << "Enter the position whose details are to be destroyed " << endl;
            cin >> position;
            if (student::showcount() < position)
            {
                cout << "User not found " << endl;
            }
            else
            {
                s[position - 1]->delete_data();
            }
        }

    } while (ch);

    cout << "Program terminated" << endl;
    return 0;
}
