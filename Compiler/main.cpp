/*
 
Author: Andrew Le
Email: andrewle19@csu.fullerton.edu
4/17/17
 
Compiler that transforms a text file with code into a c++ executable code if it has no errors present

*/

#include <iostream>
#include <string>
#include "identify.h"
#include "predictiveParsingTable.h"
#include <fstream>
using namespace std;



int main()
{
    predictiontable compiler; // intialize the predictive parsing table
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
        
        cout << "Removing Comment Lines and Unessecary Whitespace" << endl;
        output.close(); // close file
        
        if(parser.checkReserved() && parser.checkColon())
        {
            string statement; // combine all the parsed words in one statement
            
            // inserts parsed words into one statement
            // if any of the words are the reserved words replace them with special placeholder
            for (int i = 0; i < parser.getSize(); i++)
            {
                if(parser.getWord(i) == "PROGRAM")
                {
                    statement += 'z';
                }
                else if(parser.getWord(i) == "INTEGER")
                {
                    statement += 'u';
                }
                else if(parser.getWord(i) == "PRINT")
                {
                    statement += 'v';
                }
                else if(parser.getWord(i) == "END.")
                {
                    statement += 'w';
                }
                else if(parser.getWord(i) == "BEGIN")
                {
                    statement += 't';
                }
                // not a reserved word so we just add
                else
                {
                    statement += parser.getWord(i);
                }
               
            }
            
            // checks if code is accepted then proceeds ask user which language user wants to compile code in
            if(compiler.check(statement))
            {
                int choice; // user choice one what to comple
                bool quit = false; // quits when user picks choice
               
                cout << "Accepted Code" << endl;
                
                while(quit != true)
                {
                    // menu of langagues
                    cout << "1. Compile to C++" << endl;
                    cout << "2. Compile to Python" << endl;
                    cout << "Enter choice(1-2):";
                    cin >> choice;
                    
                    if(choice == 1) // if user wants c++
                    {
                        cout << "Compiling to C++ file..." << endl;
                        output.open("Final.cpp");
                        parser.writeCplus(output);
                        quit = true; // quits the loop
                        output.close();
                    }
                    
                    else if(choice == 2) // if user wants python
                    {
                        cout << "Compiling to Python file..." << endl;
                        output.open("Final.py");
                        parser.writePython(output);
                        quit = true; // quits out of loop
                        output.close();
                    }
                    
                    else // handles invalid input
                    {
                        cout << "Invalid Input " << endl;
                    }
                }
               
            }
           
            // does not write to cpp if rejected
            else
            {
                cout << "Rejected Code" << endl;
            }
            
        }
       
    }
    else
    {
        cout << "Could not open finalv1.txt" << endl;
    }
    
   
    
    
    data.close(); // close the file
    system("pause");
    return 0;
}
