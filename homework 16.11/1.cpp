#include <iostream>

using namespace std;

int main()
{
  const int n = 3;
  const int m = 3;

  int A[n][m] = {{0, 0, 1}, {0, 0, 0}, {0, 1, 0}};

  int c = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (A[i][j] == 0)
      {
        c++;
      }
    }

    if (c == 3)
    {
      cout << i;
    }
    else
    {
      c = 0;
    }
  }

  return 0;
}