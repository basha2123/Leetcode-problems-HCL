#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'areBracketsProperlyMatched' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code_snippet as parameter.
 */

bool areBracketsProperlyMatched(string s) {
    stack<char>st;
    
    for(char c:s){
        if( c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        
        else if(  c==')' || c=='}' || c==']'){
            
             if(st.empty()) return false;
             
             if ( (c ==')' && st.top()=='(') ||
                 (c =='}' && st.top()=='{') ||
                 (c ==']' && st.top()=='[') ){
                    st.pop();
             }
             else return false;
        }  

    }  
    return st.empty();
}
int main()
{
    string code_snippet;
    getline(cin, code_snippet);

    bool result = areBracketsProperlyMatched(code_snippet);

    cout << result << "\n";

    return 0;
}
