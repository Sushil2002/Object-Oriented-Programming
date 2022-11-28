// Assignment-12(OOPs)

// Maps->Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.

// Problem Statement ->
// Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns the population of the state

#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string name;
    string search;
    int ch;

    map<string, long> list;
    map<string, long>::iterator ptr;
    map<string, long>::iterator it = list.begin();

    list["MAHARASTRA"] = 123563;
    list["GOA"] = 98456;
    list["WEST BENGAL"] = 14563;
    list["GUJRAT"] = 45693;
    list["ODISHA"] = 488965;
    list["PANJAB"] = 123645;
    list["DELHI"] = 74532;
    while (ch != 3)
    {
        cout << "\n\n1.Search State" << endl;
        cout << "2.Display All Data" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter Chioce:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int j;
            cout << "Enter the State Need To be Sraeched:";
            cin.ignore();
            getline(cin, search);
            for (int i = 0; i < search.length(); i++)
            {
                j = search[i];
                search[i] = toupper(j);
            }
            cout << "Your Searching For " << search << endl;
            for (ptr = list.begin(); ptr != list.end(); ptr++)
            {
                if (ptr->first == search)
                {
                    cout << (*ptr).first << " Population is " << (*ptr).second << endl
                         << endl;
                }
            }
            break;
        case 2:
            cout << endl;
            for (ptr = list.begin(); ptr != list.end(); ptr++)
            {
                cout << (*ptr).first << ":" << (*ptr).second << endl;
            }
            break;
        }
    }
    return 0;
}