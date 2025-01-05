#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string vectorToString(vector<int>& vec) {
    string result;
    for (int num : vec) {
        result += to_string(num);
    }
    return result;
}

vector<char> findMostFrequentDigits(string& str) {
    vector<char> frequentDigits;
    int maxCount = 1, currentCount = 1;

    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            frequentDigits.clear();
            frequentDigits.push_back(str[i]);
        } else if (currentCount == maxCount) {
            if (find(frequentDigits.begin(), frequentDigits.end(), str[i]) == frequentDigits.end()) {
                frequentDigits.push_back(str[i]);
            }
        }
    }

    sort(frequentDigits.begin(), frequentDigits.end());
    return frequentDigits;
}

string reduceConsecutiveDuplicates(string& str) {
    string reduced;
    reduced += str[0];
    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] != str[i - 1]) {
            reduced += str[i];
        }
    }
    return reduced;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    // Output 1
    string concatenated = vectorToString(numbers);
    cout << concatenated << endl;

    // Output 2
    vector<char> mostFrequent = findMostFrequentDigits(concatenated);
    for (char digit : mostFrequent) {
        cout << digit << " ";
    }
    cout << endl;

    // Output 3
    cout << reduceConsecutiveDuplicates(concatenated) << endl;

    return 0;
}

