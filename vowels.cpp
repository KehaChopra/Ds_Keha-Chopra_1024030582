#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int j = 0; 
    int i = 0;

    while (str[i] != '\0') {  
        char ch = str[i];
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            str[j++] = ch; 
        }
        i++;
    }

    str[j] = '\0'; 

    cout << "String without vowels: " << str.c_str() ;

    return 0;
}
