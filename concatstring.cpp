
#include <iostream>
using namespace std;

int main() {
    char s1[100] = "hello";
    char s2[7] = "world";
    
    int i = 0;
    int len1 = 0;
    
    while (s1[len1] != '\0') {
        len1++;
    }
    
    int len2 = 0;
    while (s2[len2] != '\0') {
        len2++;
    }
    
   
    for (int j = 0; j < len2; j++) {
        s1[len1 + j] = s2[j];
    }
    
   
    s1[len1 + len2] = '\0';
    
  
    cout << s1;
    
  return 0;
}
