
#include <iostream>
#include <vector>
using namespace std;

//get minimum values of 3 variables
int min(int x, int y, int z)
{
  if (x <= y && x <= z)
  {
    return x;
  }
  else if (y <= z && y <= x)
  {
    return y;
  }
  else if (z <= y && z <= x)
  {
    return z;
  }
}
//using Top-down technique and memoization to solve the problem
int get_change_recursively(int m, vector<int> &dp)
{
  if (m == 0)
  {
    return 0;
  }
  if (m < 0)
  {
    //get Biggest value to not selected during comparing with other variables
    return 1000000;
  }
  //using memoization to not calculate values again and again
  if (dp[m] != 0)
  {
    return dp[m];
  }
  //the minimum change coins available
  if (m == 1 || m == 3 || m == 4)
  {
    dp[m] = 1;
    return 1;
  }

  dp.at(m) = min(get_change_recursively(m - 1, dp) + 1, get_change_recursively(m - 3, dp) + 1, get_change_recursively(m - 4, dp) + 1);
  return dp.at(m);
}

int get_change(int m)
{
  //generate vector to save calculated values to not recalculate them again
  vector<int> dp(m + 1, 0);
  return get_change_recursively(m, dp);
}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
