#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Two pointer Technique is normally used for searching and it uses two pointers over a loop in the given data structure . It's common approach to solve coding problems that involve strings , arrays and linkedlists


Two pointers can reduce an O(n^3) or O(n^2) to O(n) which is wise solution.
Best Case O(n)
Worst Case O(nlogn)





There are two versions of the Twopointer Technique.

Two coming from the oppisite sides , and it ends the loop when they meet eachother 


Two going the same destination and one goes slower and the other goes faster, which is sliding window
*/



//Two pointer Oppisite direction

vector<int> Two_Sum_Sorted(vector<int> &nums,int target)
{
  int start = 0;
  int end = nums.size()-1;
  vector<int> result;
  while(start<end)
  {
    int sum = nums[start] + nums[end];
    if(sum==target)
    {
      result[0] = start+1;
      result[1] = end +1;
    }
    else if(sum < target)
    {
      start++;//if sum is less than target we move forward
    }
    else 
    {
      end--; //if sum greater than target, we move forward
    }
  }
  return result;
}


















///Brute Force NOT SLIDING WINDOW O(N*K) WHICH IS UNOPTIMAL
int Get_MaxSum_Array_Of_SizeK_BRUTE_FORCE(vector<int> &A,int k)
{
  int Max_Sum = 0;
  for(int i; i<=A.size()-k;i++)
  {
    int Window_Sum = 0;
    for(int j = i; j < i + k;j++)
    {
      Window_Sum += A[j];
    }
    Max_Sum = max(Max_Sum,Window_Sum);
  }
  return Max_Sum;  
}


//Sliding window as well but this is optimized to O(n+k)
int Get_MaxSum_Array_Of_SizeK_OPTIMAL_SOLUTION(vector<int> &A,int k)
{
  int Window_Sum =0, Max_Sum=0;

  for(int i=0;i<k;i++)
  {
    Window_Sum += A[i];
  }

  for (int end = k;end < A.size(); end++)
  {
    Window_Sum += A[end] - A[end-k];
    Max_Sum = max(Max_Sum,Window_Sum);
  }
  return Max_Sum;
}






int main()
{

}