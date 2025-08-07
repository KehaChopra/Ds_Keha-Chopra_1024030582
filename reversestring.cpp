#include <iostream>
using namespace std;

int main() {
    char s1[] = "keha";  
    
    int length = 0;
    
    while (s1[length] != '\0') {
        length++;
    }
    
    int first = 0;
    int last = length - 1;
    
    while (first < last) {
        char temp = s1[first];
        s1[first] = s1[last];
        s1[last] = temp;
        first++;
        last--;
    }
    
   
    cout << s1 << endl;
    
    return 0;
}
