#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
vector<int> res;
long long int permute(int a)
{
  if(a==0)
    return 1;
  if(a==1)
  
    return 1;
  
  return a*permute(a-1);
}

vector<long long int> list(int x)
{
  vector<long long int> result;
  for(int i=1;i<=x;i++)
    result.push_back(permute(i));
  
  return result;
}

void swapper(int &a,int &b)
{
  swap(a,b);
}

void swapper(int &&a,int &&b)
{
  int temp;
  temp = a;
  a =b;
  b = temp;
}
int main()
{
  
  
  swapper(53,43);
}