/*
 AUTHOR: Andrew Le
 Email: andrewle19@csu.fullerton.edu
 4/26/17
 Predictive parsing table class
 accepts/ rejects statement depending on the input matching the language
 also handles returning specefic errors
 */

#ifndef predicitveParsingTable_h
#define predicitveParsingTable_h


#include <string>
#include <stack>
using namespace std;


class predictiontable
{
private:
    
    const int charSize = 30;
    const int stateSize = 22;
    stack<char> s; // char stack
    
    // array of language
    char specialcharacters[30] = {'z','t','u','v','w','p','q','r','s','+','-','*','/','=',
        '(',')',',',';',':','0','1','2','3','4','5','6','7','8','9','$'};
    
    // array of states
    char states[22] = {'A','B','C','D','E','S','F','G','X','H','I','J','K','Y','L','Z','M',
        'N','O','P','Q','R'};
    
    // 2d array of the predictive table
    string table[22][30] = {"zB;DtGw","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","m","e","e","RC","RC","RC","RC","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","e","e","RC","RC","RC","RC","l","l","l","l","l","e","l","l","l","e","QC","QC","QC","QC","QC","QC","QC","QC","QC","QC","e",
        "e","e","F:E;","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","m","e","e","e","BS","BS","BS","BS","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",",E","l","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","u","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","HX","e","HX","HX","HX","HX","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","G","l","G","G","G","G","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","I","e","J","J","J","J","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","v(B);","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","e","e","B=K;","B=K;","B=K;","B=K;","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","m","e","LY","LY","LY","LY","LY","LY","e","e","e","LY","e","e","e","e","LY","LY","LY","LY","LY","LY","LY","LY","LY","LY","e",
        "e","e","e","e","e","e","e","e","e","+LY","-LY","e","e","e","e","l","e","l","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","e","e","MZ","MZ","MZ","MZ","MZ","MZ","e","e","e","MZ","e","e","e","e","MZ","MZ","MZ","MZ","MZ","MZ","MZ","MZ","MZ","MZ","e",
        "e","e","e","m","e","e","e","e","e","l","l","*MZ","/MZ","e","e","l","e","l","e","e","e","e","e","e","e","e","e","e","e","e",
        "e","e","e","e","e","B","B","B","B","N","N","e","e","e","(K)","e","e","e","e","N","N","N","N","N","N","N","N","N","N","e",
        "e","e","e","e","e","e","e","e","e","OQP","OQP","e","e","e","e","e","e","e","e","OQP","OQP","OQP","OQP","OQP","OQP","OQP","OQP","OQP","OQP","e",
        "e","e","e","e","e","e","e","e","e","+","-","e","e","e","e","e","e","e","e","l","l","l","l","l","l","l","l","l","l","e",
        "e","e","e","e","e","e","m","m","e","l","l","l","l","e","e","l","e","l","e","QP","QP","QP","QP","QP","QP","QP","QP","QP","QP","e",
        "e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","0","1","2","3","4","5","6","7","8","9","e",
        "e","e","e","e","e","p","q","r","s","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e"};
    
    
public:
    
    // default constructor
    predictiontable()
    {
        s.push('A');
        
    }
    
    // pushs to stack depending which state and key is wanted
    // INPUT: int stateindex- index of State, keyindex- index of key
    // OUTUPUT: none
    void advanceState(int stateindex,int keyindex)
    {
        s.pop(); // pops the top of the stack
        
        // loop to push states into the stack starts at end of string state because we want to
        // push from then end first
        if (table[stateindex][keyindex] == "e")
        {
            
            cout << "error" << endl;
            cout << stateindex << " " << keyindex << endl;
        }
        for(int i = (int)table[stateindex][keyindex].length()-1; i >= 0 ;i--)
        {
            s.push(table[stateindex][keyindex][i]); // push the table index to stack
            // cout << "push: " << s.top() << endl;
        }
        
    }
    
    // Checks whether the word is accepted by the Predictive parsing Table
    // Uses many helper functions to accomplish this
    // INPUT: string word- the target Word
    // OUTPUT: Returns True or False depending on accepted or rejected
    bool check(string word)
    {
        
        bool accepted = false; // if the word is accepted or rejected
        string match; // string match to check if the input string matches
        int i = 0; // the index of the key we want to search
        // until the stack is empty
        while(s.empty() == false)
        {
            // change any alphabetical character to a lower to match the parsing table
            if(isalpha(word[i]))
            {
                word[i] = tolower(word[i]);
            }
            
            
            if(checkspecial(word[i])) // check if search key is valid
            {
               // cout << "read: " << word[i] << endl;
                // cout << "pop: " << s.top() << endl;
                if(checkspecial(s.top()) && s.top() == word[i]) // check if top of stack is special character and is equal to word
                {
                    match += s.top(); // append top to match
                  // cout << "match: " << s.top() << endl;
                    s.pop(); // pop the stack3
                    i++;
                }
                else if(checkspecial(s.top())) // checks if the top of the stack is a special char if so then it is missing because no match
                {
                    cout << s.top() << " is Missing" << endl;
                    return false;
                }
                else if(checkState(s.top())) // checks if top of stack is a state
                {
                    advanceState(stateindex(s.top()),keyindex(word[i])); // advances the state
                }
                else if(s.top() == 'l') // if the state is lamda then pop the stack
                {
                    s.pop();
                }
                else if(s.top() == 'e') // if illegal expression error code is at the top of stack
                {
                    cout << "Illegal Expression" << endl;
                    return false;
                }
                else if(s.top() == 'm') // if missing semicolon is at the top of the stack
                {
                    cout << "; is Missing" << endl;
                    return false;
                }
                else // if none of above is true reject the input
                {
                    return false;
                }
            }
            else // if the search key is not valid
            {
                cout << "Illegal Expression" << endl;
                return false;
            }
        }
        // final check if the word is in the language
        if(match == word)
        {
            accepted = true;
        }
        
        return accepted;
    }
    
    
    // check if the key is in the special character array or language
    // INPUT: char key- key we want to search for
    // OUPUT: true or false
    bool checkspecial(char key)
    {
        bool special = false;
        
        for(int i = 0; i < charSize; i++)
        {
            // checks if key is a special char
            if(specialcharacters[i] == key)
            {
                special = true;
            }
            
        }
        return special;
    }
    
    // Find which state index we are at
    // INPUT: char state- the letter of the state
    // OUTPUT: returns index of the state
    bool checkState(char state)
    {
        for(int i = 0;i < stateSize;i++)
        {
            if(states[i] == state) // checks if state is actually a state
            {
                return true; // returns  true
            }
            
        }
        return false; // returns false
    }
    
    // find the index of key(use after we know key is already in index
    // INPUT: char key- the key we want to search for
    // OUPUT: the index of the key
    int keyindex(char key)
    {
        // if the key is an aphabetical char then change it to lower case to match the table
        if(isalpha(key))
        {
            key = tolower(key);
        }
        
        for(int i = 0;i < charSize;i++)
        {
            if(specialcharacters[i] == key) // searchs for location of key in list
            {
                return i; // returns the index
            }
            
        }
        return -1; // returns -1 if not found
    }
    
    // Find which state index we are at
    // INPUT: char state- the letter of the state
    // OUTPUT: returns index of the state
    int stateindex(char state)
    {
        for(int i = 0;i < stateSize;i++)
        {
            if(states[i] == state) // searches for location of key in list
            {
                return i; // returns the index
            }
        }
        return -1; // returns -1 if not found
    }
    
    
    
};




#endif /* predicitveParsingTable_h */
