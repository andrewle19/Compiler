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
    const charSize = 29;
    const stateSize = 22;
    stack<char> s; // char stack
    
    // array of language
    char specialcharacters[charSize] = {'z','T','U','V','W','p','q','r','s','+','-','*','/','=','/','='
        '(',')',',',';',':','0','1','2','3','4','5','6','7','8','9','$'};
    
    // array of states
    char states[stateSize] = {'A','B','C','D','E','S','F','G','X','H','I','J','K','Y','L','Z','M',
    'N','O','P','Q','R'};
    
    // 2d array of the predictive table
    string table[22][29];
    
    
public:
    
    // default constructor
    predictiontable()
    {
        s.push('$');
        s.push('E');
        
    }
    
    // pushs to stack depending which state and key is wanted
    // INPUT: int stateindex- index of State, keyindex- index of key
    // OUTUPUT: none
    void advanceState(int stateindex,int keyindex)
    {
        s.pop(); // pops the top of the stack
        
        // loop to push states into the stack starts at end of string state because we want to
        // push from then end first
        for(int i = (int)table[stateindex][keyindex].length()-1; i >= 0 ;i--)
        {
            s.push(table[stateindex][keyindex][i]); // push the table index to stack
            cout << "push: " << s.top() << endl;
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
            if(checkspecial(word[i])) // check if search key is valid
            {
                cout << "read: " << word[i] << endl;
                if(checkspecial(s.top())) // check if top of stack is special character
                {
                    match += s.top(); // append top to match
                    cout << "pop: " << s.top() << endl;
                    cout << "match: " << s.top() << endl;
                    s.pop(); // pop the stack
                    i++;
                }
                else if(checkState(s.top())) // checks if top of stack is a state
                {
                    advanceState(stateindex(s.top()),keyindex(word[i])); // advances the state
                }
                else if(s.top() == 'L') // if the state is lamda then pop the stack
                {
                    s.pop();
                }
                else // if none of above is true reject the input
                {
                    return false;
                }
            }
            
            else // if the search key is not valid
            {
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
        for(int i = 0; i < stateSize; i++)
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
        for(int i = 0;i < charSize;i++)
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
        for(int i = 0;i < 8;i++)
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
        for(int i = 0;i < 5;i++)
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
