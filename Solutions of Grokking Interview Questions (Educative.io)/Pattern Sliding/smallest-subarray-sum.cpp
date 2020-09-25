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
// sliding window | T -> O(n)
int smallestSubArraySum2(vector<int> arr, int target)
{
    int n = arr.size();
    int windowStart = 0;
    int windowSum = 0;
    int subArraySize = -1;
    int minSize = n + 1;
    for (int windowEnd = 0; windowEnd < n; windowEnd++)
    {
        windowSum += arr[windowEnd];
        if (windowSum >= target)
        {
            subArraySize = windowEnd - windowStart + 1;
            minSize = min(subArraySize, minSize);
            while (windowSum >= target and windowStart <= windowEnd)
            {
                windowSum -= arr[windowStart++];
            }
        }
    }
    return minSize;
}

int main()
{
    vector<int> arr{3, 4, 1, 1, 6};
    int s = 8;
    int ans = smallestSubArraySum2(arr, s);
    cout << ans << endl;

    return 0;
}