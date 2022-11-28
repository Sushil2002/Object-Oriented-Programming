// Files->A file is a container in a computer system for storing information.
// Saved files are stored in the hard disk in a computer

/*Write a C++ program that creates an output file, writes information to it, closes the file,
open it again as an input file and read the information from the file.*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream> //handle both input and output of object on the file,ios::in/out
using namespace std;
class A
{
public:
	void write()
	{
		string text;
		// opening File through Constructor other way is to open through open function.
		ofstream file; // writing into file, by default ios::outS
		file.open("Assignment07.txt");
		if (file.is_open()) // checks if file open
		{
			cout << "Enter the Text In File  And Press $ to Get Out..:" << endl;
			cin.ignore();
			getline(cin, text, '$'); // Takes Multiple Lines!
			// user need to have type an $ to end input statement in file
			cout << endl;
			file << text; // Writing the text to the file
			file.close(); // closeing file.
			cout << "\n--------------------------" << endl;
		}
		else
		{
			cout << "Some Thing went wrong!" << endl;
		}
	}
	void read()
	{
		ifstream file("Assignment07.txt"); // by default ios::in ,for reading file
		string text;
		if (file.is_open()) // Wheither file is open or not!
		{
			while (!file.eof()) // eof()->key issues when reading input data files is knowing how much data to read, and when to stop reading data.Thats why we use eof()
			// eof()->its a memeber function of ios class it is used to check whether file pointer has reached to the end of the file character or not,while reading.
			{
				getline(file, text);
				cout << text << endl;
			}
			file.close();
			cout << "\n--------------------------" << endl;
		}
	}
	void append()
	{
		string text;
		fstream file; // appending into file
		file.open("Assignment07.txt", ios::app);
		if (file.is_open()) // if file open
		{
			cout << "Enter the Text For Appending Into File And Press $ to Get Out.. :" << endl;
			cin.ignore();
			getline(cin, text, '$'); // Takes Multiple Lines!
			// user need to have type an $ to end input statement in file
			file << text; // Writing the text to the file
			file.close(); // close file
			cout << "\n--------------------------" << endl;
		}
		else
		{
			cout << "Some Thing went wrong!" << endl;
		}
	}
};

int main()
{
	int ch;
	A a;
	system("color 0B"); // Color Changes
	do
	{
		cout << "\n";
		cout << "1.WRITE INTO FILE -" << endl;
		cout << "2.APPEND INTO FILE -" << endl;
		cout << "3.READ FILE -" << endl;
		cout << "4.EXIT" << endl;
		cout << "Enter Choice -";
		cin >> ch;
		cout << "\n--------------------------" << endl;
		switch (ch)
		{
		case 1:
			a.write();
			break;
		case 2:
			a.append();
			break;
		case 3:
			a.read();
			break;
		}
	} while (ch != 4);
	return 0;
}
