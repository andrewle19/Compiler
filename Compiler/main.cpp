/*
 
Author: Andrew Le
Email: andrewle19@csu.fullerton.edu
4/17/17
 
Compiler that transforms a text file with code into a c++ executable code if it has no errors present

*/

#include <iostream>
#include <string>
#include "identify.h"
#include <fstream>
using namespace std;



int main()
{
    
    ifstream data; // handles opening and reading of the file data.txt
    ofstream output; // handles oppening and writing of the file newdata.txt
    string statement; // takes in lines from the txt file
    identify parser; // parses through txt file to take out undesirables
    data.open("finalv1.txt"); // opens the code file
    
    
    // checks if file successfully opened
    if (data.is_open())
    {
        // takes in lines as long as the file is not at eof
        while (data.eof() != true)
        {
            getline(data, statement); // gets the line
            // checks for comment lines/extra white space removes all of them saves data to array in class
            parser.check(statement);
        }
        // opens the finalv2.txt file or writes to it depending on if it exists
        output.open("finalv2.txt");
        parser.printfile(output); // prints all the new data to file
        
        cout << "Outputing to file" << endl;
        output.close(); // close filex
        if(parser.checkReserved())
        {
            cout << "cool" << endl;
        }
        else
        
        {
            cout << "not cool" << endl;
        }
    }
    else
    {
        cout << "Could not open data.txt" << endl;
    }
    
   
    
    
    data.close(); // close the file
    system("pause");
    return 0;
}
