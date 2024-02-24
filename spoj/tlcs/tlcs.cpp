#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Based on Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
Chapter 15.4 "Finding the longest common subsequence"
*/

string nwp(string u, string w)
{
  int n = u.length();
  int k = w.length();

  vector<vector<int>> macierz(n + 1, vector<int>(k + 1, 0));

  for (int i = 0; i <= n; ++i)
    macierz[i][0] = 0;

  for (int j = 0; j <= k; ++j)
    macierz[0][j] = 0;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= k; ++j)
    {
      if (u[i - 1] == w[j - 1])
      {
        macierz[i][j] = macierz[i - 1][j - 1] + 1;
      }
      else
      {
        macierz[i][j] = max(macierz[i - 1][j], macierz[i][j - 1]);
      }
    }
  }

  string podciagi = "";
  int i = n, j = k;

  while (i > 0 && j > 0)
  {
    if (u[i - 1] == w[j - 1])
    {
      podciagi += u[i - 1];
      i -= 1;
      j -= 1;
    }
    else if (macierz[i - 1][j] > macierz[i][j - 1])
    {
      i -= 1;
    }
    else
    {
      j -= 1;
    }
  }

  reverse(podciagi.begin(), podciagi.end());
  return podciagi;
}

int main()
{
  int n;
  cin >> n;
  for (int t = 1; t <= n; ++t)
  {
    int lx, ly;
    cin >> lx;
    string x;
    cin >> x;
    cin >> ly;
    string y;
    cin >> y;

    string result = nwp(y, x);
    cout << "case " << t << " ";
    if (result.length() < 1)
    {
      cout << "N" << endl;
      continue;
    }
    else
    {
      cout << "Y" << endl;
    }
    cout << result.length() << endl;

    int left_index = 0, right_index = 0;
    vector<int> left_indexes, right_indexes;

    for (int i = 0; i < max(x.length(), y.length()); ++i)
    {
      if (left_index < result.length() && x[i] == result[left_index])
      {
        left_index += 1;
        left_indexes.push_back(i + 1);
      }
      if (right_index < result.length() && y[i] == result[right_index])
      {
        right_index += 1;
        right_indexes.push_back(i + 1);
      }
    }

    for (int i = 0; i < result.length(); ++i)
    {
      cout << result[i] << " " << left_indexes[i] << " " << right_indexes[i] << endl;
    }
  }
  return 0;
}
