#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to find the smallest BDN number divisible by N
long long findSmallestBDN(int N) {
    queue<long long> q; // Queue for BFS
    unordered_set<int> seenRemainders; // To track remainders we've already seen

    q.push(1); // Start with the first BDN number: 1
    while (!q.empty()) {
        long long current = q.front();
        q.pop();

        // Check if this number is divisible by N
        if (current % N == 0) {
            return current;
        }

        // Calculate the remainder of the current number when divided by N
        int remainder = current % N;

        // If this remainder hasn't been seen before, add new numbers to the queue
        if (seenRemainders.find(remainder) == seenRemainders.end()) {
            seenRemainders.insert(remainder);

            // Append '0' and '1' to the current number to generate new BDN numbers
            q.push(current * 10);     // Append '0'
            q.push(current * 10 + 1); // Append '1'
        }
    }

    return -1; // This should never happen as there's always a solution
}

int main() {
    int N;

    // Input the number N
    cout << "Enter the number N: ";
    cin >> N;

    // Find the smallest BDN number divisible by N
    long long result = findSmallestBDN(N);

    // Output the result
    cout << "The smallest BDN number divisible by " << N << " is: " << result << endl;

    return 0;
}