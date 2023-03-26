#include <iostream>

using namespace std;

// insert sort
int main()
{
    // insert sort
    int a[10] = { 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 };
    int i, j, temp;
    for (i = 1; i < 10; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }

    cout << "insert sort: ";
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
Test Case 1:
Input: {5, 4, 3, 2, 1, 10, 9, 8, 7, 6}
Expected Output : insert sort : 1 2 3 4 5 6 7 8 9 10

Test Case 2 :
    Input : {2, 2, 2, 2, 2, 1, 1, 1, 1, 1}
Expected Output : insert sort : 1 1 1 1 1 2 2 2 2 2

Test Case 3 :
    Input : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
Expected Output : insert sort : 1 2 3 4 5 6 7 8 9 10

Test Case 4 :
    Input : {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Expected Output : insert sort : 1 2 3 4 5 6 7 8 9 10

Test Case 5 :
    Input : {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}
Expected Output : insert sort : 1 2 3 4 5 6 7 8 9 10

Test Case 6 :
    Input : {1, 10, 2, 9, 3, 8, 4, 7, 5, 6}
Expected Output : insert sort : 1 2 3 4 5 6 7 8





