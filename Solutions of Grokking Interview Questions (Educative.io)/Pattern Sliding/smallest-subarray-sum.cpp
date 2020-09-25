// *** This Template was created by Tasfik Rahman ***
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce | T -> O(n^3)
int smallestSubArraySum(vector<int> arr, int target)
{
    int n = arr.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int start = j, end = j + i - 1;
            int sum = 0;
            for (int k = start; k <= end; k++)
            {
                sum += arr[k];
            }
            if (sum >= target)
                return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{3, 4, 1, 1, 6};
    int s = 8;
    int ans = smallestSubArraySum(arr, s);
    cout << ans << endl;

    return 0;
}