// Assignment-08(OOPs)

// Template->Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular data type.
// Generic programming->The programs are written in such a way that it creates the most efficient code possible while allowing the code to apply to as many situations as possible without requiring any changes to the original code/logic itself.

// Problem Statement ->
// Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array

// selection sort..
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class A
{
public:
    void selection_sort() // template function
    {
        int j, min;
        int n;
        T *array;
        T temp;
        array = new T[n];
        char error = 'a';

        cout << "Enter Total Number Of Student-";
        try
        {
            cin >> n;
            if (!cin)
            {
                throw error;
            }
        }
        catch (...) // catches All ecxeption!0
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Total Number Of Student Cannot be Any Character.\nEnter the interger Vaule -" << endl;
            cin >> n;
        }

        bool go;
        char a;
        for (int i = 0; i < n; i++)
        {
            go = true;
            while (go)
            {
                try
                {
                    cout << "Enter the Element:";
                    if (cin >> array[i])
                    {
                        cin.get(a);
                        if (a != '\n')
                        {
                            cin.clear();
                            throw 0;
                        }
                        else
                        {
                            go = false;
                        }
                    }
                    else
                    {
                        throw 1;
                    }
                }
                catch (...)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nInavalid Number" << endl;
                }
            }
        }
        cout << "\nEnter List is-" << endl;
        cout << "[ ";
        // for displaying the entered list
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << "  ";
        }
        cout << "]";
        // Logic for Selection Sort!
        for (int i = 0; i < n; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (array[min] > array[j])
                {
                    min = j;
                }
            }
            // Swaping the elements
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
        cout << "\n\nSorted Array is -" << endl;
        cout << "[ ";
        // display the sorted array
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << "  ";
        }
        cout << "]";
    }
};
int main()
{
    int ch, n;
    do
    {
        system("color 0B"); // Color Changes
        cout << "\n*** MAIN MENU ***" << endl;
        cout << "1.SORTING FOR INTEGER ARRAY -" << endl;
        cout << "2.SORTING FOR FLOAT ARRAY -" << endl;
        cout << "3.EXIT" << endl;
        cout << "Enter Choice:";
        cin >> ch;
        cout << "\n--------------------------" << endl;
        switch (ch)
        {
        case 1:
            A<int> s1;
            s1.selection_sort();
            cout << "\n--------------------------" << endl;
            break;
        case 2:
            A<float> s2;
            s2.selection_sort();
            cout << "\n--------------------------" << endl;
            break;
        }
    } while (ch != 3);
    return 0;
}