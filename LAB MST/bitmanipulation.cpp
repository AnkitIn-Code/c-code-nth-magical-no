#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int bit = 0; bit < 32; bit++) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & (1 << bit)) {
                count++;
            }
        }
        if(count % 3 != 0) {
            ans = ans | (1 << bit);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 2, 3, 2};

    cout << singleNumber(nums);

    return 0;
}
