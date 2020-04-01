#include <bits/stdc++.h>
using namespace std;
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bool check(vector<int> &arr, int mid, int k)
{
    int cnt = 0;
    for(int i=1; i<arr.size(); i++)
    {
        int diff = arr[i]-arr[i-1];
        int sessNeeded = (diff-1)/mid;
        cnt += sessNeeded;
        if(cnt > k) return false;
    }
    return true;
}



int solve()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int maxDiff = INT_MIN;
    int ans = 0;
    for(int i=1; i<n; i++) maxDiff = max(maxDiff,arr[i]-arr[i-1]);
    if (maxDiff==1) return 1;
        //here comes binary search logic
    int s = 1, e = maxDiff;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(check(arr,mid,k))
        {
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;
    }
    return ans;
}

int main()
{
    _fast_;
    int t; cin >> t;
    int i = 1;
    while(t--)
    {
        cout << "Case #" << i << ": " << solve() << endl;
        i+=1;
    }
    return 0;
}
