#include <iostream>
#include <string>

using namespace std;

int i = 0;         // Index for parsing the input string
string input;      // Input string to be validated

// Function Prototypes
bool S();
bool L();
bool LPrime();

// Recursive Descent Parser Functions

// S → ( L ) | a
bool S() {
    if (i < input.length() && input[i] == 'a') {
        i++; // Consume 'a'
        return true;
    } else if (i < input.length() && input[i] == '(') {
        i++; // Consume '('
        if (L()) {
            if (i < input.length() && input[i] == ')') {
                i++; // Consume ')'
                return true;
            }
        }
    }
    return false;
}

// L → S L'
bool L() {
    if (S()) {
        return LPrime();
    }
    return false;
}

// L' → , S L' | ε
bool LPrime() {
    if (i < input.length() && input[i] == ',') {
        i++; // Consume ','
        if (S()) {
            return LPrime();
        } else {
            return false;
        }
    }
    return true; // Epsilon (ε) transition
}

// Function to validate the input string
void validate(string str) {
    input = str;
    i = 0; // Reset index

    if (S() && i == input.length()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
}

// Main function to test the parser
int main() {
    string test_cases[] = {
        "a", "(a)", "(a,a)", "(a,a,a)", "(a,a),(a,a)", "a,a", "(a,a,a)a"
    };

    for (const string& test : test_cases) {
        cout << "Input: " << test << " -> ";
        validate(test);
    }

    return 0;
}
