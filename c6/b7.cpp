#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

// Function to check if two strings differ by exactly one character
bool isAdjacent(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false; // More than one difference
        }
    }
    return diff == 1;
}

// Function to find the shortest path from s to t
int shortestPath(const vector<string>& S, const string& s, const string& t) {
    // If s and t are the same, no need to move
    if (s == t) return 0;

    // Create a set of all words for quick lookup
    unordered_set<string> wordSet(S.begin(), S.end());

    // BFS queue: pair of (current word, distance)
    queue<pair<string, int>> q;
    q.push({s, 0});

    // Set to track visited words
    unordered_set<string> visited;
    visited.insert(s);

    while (!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();

        // Check all words in the set
        for (const string& word : wordSet) {
            if (visited.find(word) == visited.end() && isAdjacent(current, word)) {
                // If we reach the target word, return the distance + 1
                if (word == t) {
                    return dist + 1;
                }

                // Otherwise, add the word to the queue and mark it as visited
                q.push({word, dist + 1});
                visited.insert(word);
            }
        }
    }

    // If no path is found, return -1
    return -1;
}

int main() {
    // Input the source and target words
    string s, t;
    cin >> s >> t;

    // Input the list of words
    vector<string> S;
    string word;
    while (cin >> word) {
        S.push_back(word);
    }

    // Find the shortest path
    int result = shortestPath(S, s, t);

    // Output the result
    cout << "Shortest path length: " << result << endl;

    return 0;
}