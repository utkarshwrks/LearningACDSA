
class Solution {
public:
    using ll = long long;

    ll lcm(ll a, ll b) {
        if (a == 0 || b == 0) return 0;

        ll g = gcd(a, b);
        if (a / g > LLONG_MAX / b) return -1;

        return (a / g) * b;
    }

    ll lcms(int i, int j, vector<int>& nums) {
        ll result = nums[i];

        for (int k = i + 1; k <= j; k++) {
            result = lcm(result, nums[k]);
            if (result == -1) return -1;
        }
        return result;
    }

    ll gcds(int i, int j, vector<int>& nums) {
        ll result = nums[i];

        for (int k = i + 1; k <= j; k++) {
            result = gcd(result, (ll)nums[k]);
        }
        return result;
    }

    ll prods(int i, int j, vector<int>& nums) {
        ll result = 1;

        for (int k = i; k <= j; k++) {
            if (nums[k] != 0 && result > LLONG_MAX / nums[k])
                return -1;

            result *= nums[k];
        }
        return result;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ll prod = prods(i, j, nums);
                ll g = gcds(i, j, nums);
                ll l = lcms(i, j, nums);

                if (prod == -1 || l == -1) continue;

                if (g != 0 && l > LLONG_MAX / g) continue;

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
