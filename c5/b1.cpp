#include <iostream>

using namespace std;

bool valid_formula(string s){
    int ngoactrai = 0, ngoacphai = 0, congtru = 0, nhanchia = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') ngoactrai++;
        else if(s[i] == ')') ngoacphai++;
        else if(s[i] == '+' || s[i] == '-') congtru++;
        else if(s[i] == '*' || s[i] == '/') nhanchia++;
    }
    if (ngoactrai == ngoacphai){
        if(ngoactrai == congtru) return 0;
    }
    return 1;
}

int main()
{
    string input = "";
    cin >> input;
    cout << valid_formula(input);
    return 0;
}
