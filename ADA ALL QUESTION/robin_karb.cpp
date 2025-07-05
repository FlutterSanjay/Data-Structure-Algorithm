#include <iostream>
#include <string>
using namespace std;

class RabinKarp {
private:
    string pattern;
    int prime; // A prime number used for the hashing function
    int d;     // Number of characters in the input alphabet (e.g., 256 for ASCII)

public:
    // Constructor to initialize the pattern, prime, and alphabet size
    RabinKarp(const string &pat, int primeNum = 101, int alphabetSize = 256)
        : pattern(pat), prime(primeNum), d(alphabetSize) {}

    // Function to search for the pattern in the given text
    void search(const string &text) {
        int m = pattern.size();
        int n = text.size();
        int patHash = 0;  // Hash value for the pattern
        int textHash = 0; // Hash value for the text
        int h = 1;        // The value of d^(m-1) % prime

        // Precompute h = d^(m-1) % prime
        for (int i = 0; i < m - 1; ++i)
            h = (h * d) % prime;

        // Calculate the hash value of the pattern and the first window of the text
        for (int i = 0; i < m; ++i) {
            patHash = (d * patHash + pattern[i]) % prime;
            textHash = (d * textHash + text[i]) % prime;
        }

        // Slide the pattern over the text one by one
        for (int i = 0; i <= n - m; ++i) {
            // Check if the hash values of the current window and pattern are equal
            if (patHash == textHash) {
                // Check for characters one by one in case of hash collision
                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    cout << "Pattern found at index " << i << endl;
                }
            }

            // Calculate hash value for the next window of text
            if (i < n - m) {
                textHash = (d * (textHash - text[i] * h) + text[i + m]) % prime;

                // If textHash is negative, convert it to a positive value
                if (textHash < 0)
                    textHash = (textHash + prime);
            }
        }
    }
};

int main() {
    string text;
    string pattern;

    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    RabinKarp rk(pattern);
    rk.search(text);

    return 0;
}