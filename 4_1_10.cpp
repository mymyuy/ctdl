#include <iostream>
#include <vector>
#include <map>
#include <random>
using namespace std;

pair<vector<int>, map<int, int>> randomNumbersAndCount(int n, int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);

    vector<int> numbers;
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int num = dist(gen);
        numbers.push_back(num);
        counts[num]++;
    }
    return {numbers, counts};
}

int main() {
    auto [numbers, counts] = randomNumbersAndCount(10, 1, 5);

    cout << "Numbers: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    cout << "Counts: ";
    for (auto& [num, count] : counts) {
        cout << num << ": " << count << " ";
    }
    cout << endl;
    return 0;
}
