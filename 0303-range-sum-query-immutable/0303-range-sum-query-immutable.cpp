class NumArray {
    vector<int> ps;
    
public:
    NumArray(vector<int>& nums) : ps(nums.size()) {
        ps[0] = nums[0];
        for (auto i {1uz}; i < nums.size(); i++)
            ps[i] = ps[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return ps[right] - (left > 0 ? ps[left-1] : 0); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */