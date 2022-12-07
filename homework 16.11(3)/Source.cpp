#include <conio.h>
#include <iostream>
#include <cstring>

using namespace std;


// replace child with children in a string and count number of replacements
void replace(char* input) {
    int count = 0;
    char* p = input;
    while ((p = strstr(p, "child")) != NULL) {
        count++;
        p += 5;
    }
    cout << "Number of replacements: " << count << endl;
}


int main()
{
    char str[100];
    cin.getline(str, sizeof(str));
    replace(str);
}