#include <iostream>
#include <string>
using namespace std;

const int PRIME = 101; // A prime number for hashing

long long calculateHash(const string& str, int start, int end) {
    long long hash = 0;
    long long multiplier = 1;

    for (int i = end; i >= start; --i) {
        hash = (hash + str[i] * multiplier) % PRIME;
        multiplier = (multiplier * 256) % PRIME; // 256 is the number of ASCII characters
    }

    return hash;
}
void reverseStr(string &s){
    int l=  0;
    int r=s.length()-1;
    while (l<r)
    {
        swap(s[l],s[r]);
        l++;
        r--;
    }
    
}
void findPalindromes(const string& text) {
    int n = text.length();

    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            long long forwardHash = calculateHash(text, start, end);

            string reversedSubstring = text.substr(start, end - start + 1);
            reverseStr(reversedSubstring);
            long long reverseHash = calculateHash(reversedSubstring, 0, reversedSubstring.length() - 1);
            
            if (forwardHash == reverseHash) {
                // Validate the palindrome
                string substring = text.substr(start, end - start + 1);
                if (substring == string(substring.rbegin(), substring.rend())) {
                    cout << substring << endl;
                }
            }
        }
    }
}
int main() {
    string text = "ABCBAB";
    cout << "Palindromic substrings in \"" << text << "\":" << endl;
    findPalindromes(text);
    return 0;
}
