//Hint:- Solved using Greedy Approach.
#include <bits/stdc++.h>
using namespace std;
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve()
{
    int n; cin >> n; int b; cin >> b;
    int s = 0; int c = 0;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(auto i : arr)
    {
        s+=i;
        if(s<=b)
        {
            c+=1;
        }
    }
    return c;
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
