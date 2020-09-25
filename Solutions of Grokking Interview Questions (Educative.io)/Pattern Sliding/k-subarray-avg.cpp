// *** This Template was created by Tasfik Rahman ***
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce | T -> O(n^2)
vector<double> subArrayAvg(int *arr, int n, int k)
{
    vector<double> ans;
    for (int start = 0; start <= n - k; start++)
    {
        int sum = 0;
        for (int i = start; i < start + k; i++)
        {
            sum += arr[i];
        }
        double avg = (double)sum / k;
        ans.push_back(avg);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int n = sizeof(arr) / sizeof(int);
    int k = 5;
    vector<double> ans = subArrayAvg(arr, n, k);
    for (double avg : ans)
    {
        cout << avg << ", ";
    }
    return 0;
}