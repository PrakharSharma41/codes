//             look for problem by           MMPROD code on codechef

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int mod = 1e9+7;

int a[111111];

int cmp(int a, int b) {
    return abs(b) > abs(a);
}

int main() {
    ios::sync_with_stdio(0);
    int t, sn = 0;
    cin >> t;
    while (t --> 0) {
        int n, k;
        cin >> n >> k;
        bool zero = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            zero |= (a[i] == 0);
        }
        sort(a, a+n, cmp);  // sorting the array by absolute value
        
//        for(int i = 0; i < n; ++i) {
//            cout << a[i] << " ";
//            if (i == n-k-1)
//                cout << "\n";
//        }
//        cout << "\n";
        
        int sn = 1;
        vector<int> nums;
        int gneg = -1e9-1, gpos = 1e9+1;
        for(int i = 0, id = n-1; i < k; ++i, id--) {
            if (a[id] < 0) sn *= -1;
            nums.push_back(a[id]);
            if (a[id] < 0)
                gneg = max(gneg, a[id]);
            else
                gpos = min(gpos, a[id]);
        }
        
        if (sn > 0) {
            int ans = 1;
//            vector<int>::iterator x;
//            for(x = nums.begin();x!=nums.end();x++)
				for(auto x:nums)  
                ans = (ans * 1ll * x) % mod;
            cout << (ans + mod) % mod << "\n";
        } else {
            int mn = 1, mx = -1;
            for(int i = 0; i < n-k; ++i) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
            
            //cout << gneg << " " << mx << "\n";
            //cout << gpos << " " << mn << "\n";
            
            bool g1 = gneg != -1e-9-1 && mx != -1;
            bool g2 = gpos != 1e9+1 && mn != 1;
            if (g1 && g2) {
                int val, repl;
                if (mx * 1ll * gpos > mn * 1ll * gneg)
                    val = gneg, repl = mx;
                else
                    val = gpos, repl = mn;
                
                for(int i = 0; i < k; ++i)
                    if (nums[i] == val) {
                        nums[i] = repl;
                        break;
                    }
                int ans = 1;
                vector<int>::iterator x;
                for(x = nums.begin();x!=nums.end();x++)
                    ans = (ans * 1ll *(*x)) % mod;
                cout << (ans + mod) % mod << "\n";
            } else if (g1) {
                for(int i = 0; i < k; ++i)
                    if (nums[i] == gneg) {
                        nums[i] = mx;
                        break;
                    }
                int ans = 1;
                vector<int>::iterator x;
                for(x = nums.begin();x!=nums.end();x++)
                    ans = (ans * 1ll *(*x)) % mod;
                cout << (ans + mod) % mod << "\n";
            } else if (g2) {
                for(int i = 0; i < k; ++i)
                    if (nums[i] == gpos) {
                        nums[i] = mn;
                        break;
                    }
                int ans = 1;
                vector<int>::iterator x;
                for(x = nums.begin();x!=nums.end();x++)
                    ans = (ans * 1ll * (*x)) % mod;
                cout << (ans + mod) % mod << "\n";
            } else {
                if (zero)
                    cout << "0\n";
                else {
                    int ans = 1;
                    for(int i = 0; i < k; ++i)
                        ans = (ans * 1ll * a[i]) % mod;
                    cout << (ans + mod) % mod << "\n";
                }
            }
            
            
        }
    }
    return 0;
}
