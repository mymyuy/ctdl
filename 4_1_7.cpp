#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> countCharacters(const string& s) {
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    return freq;
}

int main() {
    string s = "hello world";
    auto result = countCharacters(s);
    for (auto& [c, count] : result) {
        cout << c << ": " << count << endl;
    }
    return 0;
}
