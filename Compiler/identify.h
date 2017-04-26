// Author: Andrew Le
// Identifier class
// Takes out extra white space/comment lines/blank lines then writes the new code in txt file


#ifndef IDENTIFY_h
#define IDENTIFY_h
#include <fstream>

using namespace std;

class identify
{
private:
    
    string words[200]; // can store a program that is 200 lines
    string special[9] = {"=","*","-",";","(",")","+",",",":"}; // list of special characters
    int size; // stores the size of the array
    string reservedwords[5] = {"PROGRAM","BEGIN","END.","INTEGER","PRINT"}; // reserved words
public:
    
    // default constructor
    identify()
    {
        size = 0;
    }
    
    // gets word at specific index
    // INPUT: index of word
    // OUTPUT: return word[i]
    string getWord(int index)
    {
        return words[index];
    }
    
    
    // Checks if the string is a reserved word
    // INPUT: w- string we are checking
    // OUTPUT: returns the length of the word using it as an index 
    int isReserved(string w)
    {
        string word;
        for (int i = 0; i < w.length(); i++)
        {
            word += w[i];
            for(int j = 0; j < 5; j++)
            {
                if(word == reservedwords[j])
                {
                    words[size] = word;
                    size++; //increment the size
                    return (int)word.length();
                }
            }
        }
        return 0;
    }
    
    
    // checks if the string is a special char
    // Input: string w
    // Output: false/true
    bool isSpecial(char w)
    {
        bool isSpecial = false;
        for (int i = 0; i < 9; i++)
        {
            if (special[i].find(w) != special[i].npos) // checks to see if s is in special char list by comparing if it is found at a position that is not the nth position
            {
                isSpecial = true;
            }
        }
        
        return isSpecial;
    }
    
    
    // Checks string to see if there are comment lines and extra uneeded white space and removes both stores data into string array
    // Input: string w - line from the file
    // Output: None
    void check(string w)
    {
        
        int comment = 0; // stores the amt of // backslash lines if 2 then it is a comment line we will ignores
        int i = isReserved(w); // checks if the string contains reserved word returns the legnth of reserved word and uses the length of that word as the starting point of i
        while (i < w.length())
        {
            // if there is a comment found it will ignore rest of the line
            if (comment == 2)
            {
                break;
            }
            else
            {
                if (w[i] == '/') // if a backspace key is a char
                {
                    comment++; // increment comment
                    i++;
                }
                else if (isspace(w[i])) // if white space then increment
                {
                    i++;
                }
                else if (isSpecial(w[i])) // if char is a special char
                {
                    if(words[size].empty()) // if the current word is empty add on the special character
                    {
                        words[size] = w[i];
                        size++;// increment the size
                    }
                    else // else the current word has items so add special char to next word and increment 2
                    {
                        words[size+1] = w[i];
                        size += 2;
                    }
                    i++;
                }
                else // then the char is a letter or a digit so just add to existing words array
                {
                    words[size] = words[size] + w[i];
                    i++;
                }
                
            }
        }
    }
    
    
    // check reserved checks all the words making sure none of the required reserved words are missing
    // INPUT: None
    // OUTPUT: msg on which are missing and bool true or false
    
    bool checkReserved()
    {
        
        // stores result of test for BEGIN/INT/PROGRAM/END.
        bool hasInt = false, hasBegin = false, hasProg = false, hasEnd = false;
        for(int i = 0; i < 200; i++)
        {
            if(words[i] == "INTEGER")
            {
                hasInt = true;
            }
            if(words[i] == "BEGIN")
            {
                hasBegin = true;
            }
            if(words[i] == "PROGRAM")
            {
                hasProg = true;
            }
            if(words[i] == "END.")
            {
                hasEnd = true;
            }
        }
        // if everything passes the test
        if(hasInt == true && hasBegin == true && hasProg == true && hasEnd == true)
        {
            cout << "has everything" << endl;
            return true;
        }
        
        // error messeges for when each of the reserved words are missing
        if(hasInt == false)
        {
            cout << "INTEGER is expected(integer missing or spelled wrong" << endl;
        }
        if(hasBegin == false)
        {
            cout << "BEGIN is expected(begin missing or spelled wrong" << endl;
        }
        if(hasProg == false)
        {
            cout << "PROGRAM is expected(program missing or spelled wrong" << endl;
        }
        if(hasEnd == false)
        {
            cout << "END. is expected(end. missing or spelled wrong" << endl;
        }
        return false;
        
    }
    
    // prints out all the data properly formated into file
    // Input: output ofstream to write to file
    // Ouput: None
    void printfile(ofstream &out)
    {
        int i = 0; // iterator
        
        while (i < size) // loop ends when i reachs the size
        {
            // if the word index is ; or BEGIN then we go to new line
            if (words[i] == ";" || words[i] == "BEGIN")
            {
                out << words[i] << endl;
            }
            else
            {
                out << words[i] << " ";
            }
            i++; // increment
        }
        
    }
    

    
};


#endif /* indentify_h */
