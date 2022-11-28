// Assignment-03(OOPs)
// Vetor->Vector are same as dynamic arrays with abality to resize itself automatiaclly.Vector are placed in continous storage so that they can be accessed and treaversal using itreaction

// Problem Statement ->

/*Imagine  a  publishing  company  which  does marketing for book and audio cassette versions. Create a class publication that stores the title (a string)  and  price  (type  float)  of  publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write  a  program  that  instantiates  the book  and tape class, allows user to enter data and displays the  data  members.  If  an  exception  is  caught, replace  all  the  data  member  values  with  zero values.
 */
/*0.Inheritance  1.Hierarchical Inheritance is Being Used!  2. Default Constructor 3.Access Specifier 4.Exceptional Handling  */

#include <iostream>
#include <string>
#include <windows.h> //For Color
#include <bits/stdc++.h>
using namespace std;
class publication // Base class or Parent class
{
public:
    string title;
    float price;

    void setdata() // Function For setting the Data
    {
        try
        {
            cout << "Enter Book Title - ";
            cin.ignore();
            getline(cin, title);
            if (title.length() == 0)
            {
                throw 0;
            }
            else
            {
                for (auto i : title)
                {
                    if (isdigit(i))
                    {
                        throw 0;
                        break;
                    }
                }
            }
        }
        catch (...) // Single catch block for all Exceptions!
        {
            cout << "Exception is caught,all the data member values are Set to be Zero!" << endl;
            title = "";
            price = 0.0;
            return;
        }
        try
        {
            cout << "Enter Book Price - ";
            if (cin >> price)
            {
            }
            else
            {
                throw 0;
            }
        }
        catch (...)
        {
            cin.clear();
            cin.ignore();
            cout << "Exception is caught,all the data member values are Set to be Zero!" << endl;
            title = "";
            price = 0.0;
            return;
        }
    }
    string name1()
    {
        return title;
    }
    ~publication(){};
    void display()
    {

        int c;
        for (int i = 0; i < title.length(); i++)
        {
            c = title[i];
            title[i] = toupper(c);
        }
        cout << "Title is " << title << endl;
        cout << "Price is " << price << "/-" << endl;
    }
};

class book : public publication // Derived Class -01/(Child class)
{
private:
    int pagecount;

public:
    void setdata_book() // Function For setting the Data
    {
        setdata(); // Base class setdata Function is getting call
        try
        {
            cout << "Enter PageCount - ";

            if (title.length() == 0)
            {
                pagecount = 0;
            }
            else if (cin >> pagecount)
            {
            }
            else
            {
                throw 0;
            }
        }
        catch (...) // Single catch block for all Exceptions
        {
            cin.clear();
            cin.ignore();
            cout << "Exception is caught,all the data member values are Set to be Zero!" << endl;
            title = "";
            price = 0.0;
            pagecount = 0;
            return;
        }
    }

    void display_book()
    {
        display(); // Base class display function is getting call
        cout << "PageCount is " << pagecount << endl;
    }
    ~book(){}; // Destructor
};
class tape : public publication // Derived Class - 02
{
private:
    float playtime;

public:
    void setdata_tape() // Function For setting the Data
    {
        setdata(); // Base class setdata Function is getting call
        try
        {
            cout << "Enter PlayTime(Tape) in MIN - ";

            if (title.length() == 0)
            {
                playtime = 0.0;
            }
            else if (cin >> playtime)
            {
            }
            else
            {
                throw 0;
            }
        }
        catch (...) // Single catch block for all Exceptions
        {
            cin.clear();
            cin.ignore();
            cout << "Exception is caught,all the data member values with zero values." << endl;
            title = "";
            price = 0.0;
            playtime = 0.0;
            return;
        }
    }

    void display_tape()
    {
        display(); // Base class display Function is getting call
        cout << "PlayTime  is " << playtime << " min" << endl;
    }
    ~tape(){};
};
int main() // Main function
{
    // Constructor->Default Constructor is Automatically get called When Object is Creadted!
    book b1;                // Class Book object Of array and calling Constructor
    tape t1;                // Class Tape object Of array
    vector<book> book_list; ////Number of objects that are created are stored in the container
    // Container store the data in sorted manner!
    vector<book>::iterator it; // Act as pointer to the vector, which will point the object

    // Function associated to vector->.end(),.begin(),etc.
    vector<tape> tape_list;     // Number of objects that are created are stored in the vector
    vector<tape>::iterator ptr; // Act as pointer to the vector, which will point the object
    string name;
    string title;
    int ch = 0, b_count, t_count; // Inatialization
    do
    {
        system("color 0B"); // Color Changes
        cout << "\n-----------------------------------" << endl;
        cout << "1.Create New Book - " << endl;
        cout << "2.Create New Tape - " << endl;
        cout << "3.Display All Books - " << endl;
        cout << "4.Display All Tapes - " << endl;
        cout << "5.Search Book - " << endl;
        cout << "6.Search Tape - " << endl;
        cout << "7.Delete Book - " << endl;
        cout << "8.Delete Tape - " << endl;
        cout << "9.Display All Data(Books And Tape)" << endl;
        cout << "10.Exit - " << endl;
        cout << "\n-----------------------------------" << endl;
        cout << "Enter Choice - ";
        cin >> ch;
        cout << "\n";
        // system("color 0F");
        switch (ch)
        {
        case 1:
            b1.setdata_book();
            book_list.push_back(b1); // it push the new created book at end!
            b_count++;
            break;
        case 2:
            t1.setdata_tape();
            tape_list.push_back(t1);
            t_count++;
            break;
        case 3:
            cout << "\n * * * BOOKS DEATAILS ARE... * * *- " << endl
                 << endl;
            for (it = book_list.begin(); it != book_list.end(); it++) //.begin()->return an itreaction  poiting to the first element in vector
            {
                it->display_book();
                cout << endl;
            }
            break;
        case 4:
            cout << "\n * * * TAPE DEATAILS ARE... * * *- " << endl
                 << endl;
            for (ptr = tape_list.begin(); ptr != tape_list.end(); ptr++) //.end()->Return an iteration poiting to the theortical element that follow the last element in the vector
            {
                ptr->display_tape();
                cout << endl;
            }
            break;
        case 5:
            cout << "\n * * * SEARCHING BOOK...* * *- " << endl
                 << endl;

            if (b_count != 0)
            {
                cout << "Enter the Book Name To be Searched - ";
                cin.ignore();
                getline(cin, name);
                int j = 0;
                for (int i = 0; i < name.length(); i++)
                {
                    j = name[i];
                    name[i] = toupper(j);
                }
                cout << "Book Searched is " << name;
                cout << endl;
                for (it = book_list.begin(); it != book_list.end(); it++)
                {
                    if (name == it->name1())
                    {
                        cout << "Book Found!" << endl
                             << endl;
                        it->display_book();
                        break;
                    }
                    else
                    {
                        cout << "Record Was Not Created!" << endl;
                    }
                }
            }
            break;
        case 6:
            cout << "\n * * * SEARCHING TAPE...* * *- " << endl
                 << endl;
            cout << "Enter the Tape Name to be searched - ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
            if (t_count != 0)
            {
                for (ptr = tape_list.begin(); ptr != tape_list.end(); ptr++)
                {
                    if (name == ptr->name1())
                    {
                        ptr->display_tape();
                        break;
                    }
                    else
                    {
                        cout << "Record Was Not Created!" << endl;
                    }
                }
            }
            break;
        case 7:
            cout << "\n * * * DELETE BOOK...* * *- " << endl
                 << endl;
            cout << "Enter the Book Name to be Deleted - ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
            for (it = book_list.begin(); it != book_list.end(); it++)
            {
                if (name == it->name1())
                {
                    book_list.erase(it);
                    it->~book();
                    cout << "Delete Successfully!" << endl;
                    b_count--;
                    break;
                }
                else
                {
                    cout << "No Entry For Book!" << endl;
                }
            }
            break;
        case 8:
            cout << "\n * * * DELETE TAPE...* * *- " << endl
                 << endl;
            cout << "Enter the Book Name to be Deleted - ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
            for (ptr = tape_list.begin(); ptr != tape_list.end(); ptr++)
            {
                if (name == ptr->name1())
                {
                    tape_list.erase(ptr);
                    ptr->~tape();
                    cout << "Delete Successfully!" << endl;
                    t_count--;
                    break;
                }
            }
            break;
        case 9:

            cout << "\n * * * DEATAILS OF ALL DATA... * * *- " << endl
                 << endl;
            for (it = book_list.begin(); it != book_list.end(); it++)
            {
                it->display_book();
                cout << endl;
            }
            for (ptr = tape_list.begin(); ptr != tape_list.end(); ptr++)
            {
                ptr->display_tape();
                cout << endl;
            }
            break;
        }
    } while (ch != 10);
    return 0;
}