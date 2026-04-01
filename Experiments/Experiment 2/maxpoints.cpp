#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<long double, int> mp;
            int same = 1;
            int vertical = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    same++;
                } else if (points[i][0] == points[j][0]) {
                    vertical++;
                } else {
                    long double slope = (long double)(points[j][1] - points[i][1]) /
                                        (points[j][0] - points[i][0]);
                    mp[slope]++;
                }
            }
            int curr = vertical;
            for (auto &p : mp) curr = max(curr, p.second);
            res = max(res, curr + same);
        }
        return res;
    }
};
