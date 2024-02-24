#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int char_to_int(char c)
{
  if (c >= '0' && c <= '9')
  {
    return c - '0';
  }
  else
  {
    return c - 'A' + 10;
  }
}

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char int_to_char(int digit)
{
  return alphabet[digit];
}

string divide(const string &first_number, int r, int s, int *remainder)
{
  string result;
  int current_remainder = 0;

  for (char digit : first_number)
  {
    int current_digit = char_to_int(digit);

    int current_result = (current_digit + current_remainder * r) / s;
    current_remainder = (current_digit + current_remainder * r) % s;

    result.push_back(int_to_char(current_result));
  }

  *remainder = current_remainder;

  size_t trim_position = result.find_first_not_of('0');
  result = (trim_position != string::npos) ? result.substr(trim_position) : "0";

  return result;
}

string convert(const string &first_number, int r, int s)
{
  string current_number = first_number;
  string result;
  while (current_number != "0")
  {
    int remainder;
    current_number = divide(current_number, r, s, &remainder);
    result.push_back(int_to_char(remainder));
  }

  reverse(result.begin(), result.end());

  return result.empty() ? "0" : result;
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    string n;
    int r, s;
    cin >> n >> r >> s;

    string result = convert(n, r, s);

    cout << result << endl;
  }

  return 0;
}
