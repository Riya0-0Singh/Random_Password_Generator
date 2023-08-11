#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string generateRandomPassword(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    const int charsetSize = sizeof(charset) - 1;
    
    string password;
    for (int i = 0; i < length; ++i) {
        password += charset[rand() % charsetSize];
    }
    return password;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
    
    int passwordLength;
    cout << "Enter the length of the password: ";
    cin >> passwordLength;
    
    if (passwordLength <= 0) {
      cout << "Invalid password length. Please enter a positive integer." << std::endl;
        return 1;
    }
    
    string password = generateRandomPassword(passwordLength);
    cout << "Generated password: " << password << endl;
    
    return 0;
}
