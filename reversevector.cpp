#include <iostream>
#include <vector>
using namespace std;

void linearVec(vector<int>& nums) {
	int n;
	n=nums.size();
	for(int i=0;i<n/2;i++){
		swap(nums[i],nums[n-i-1]);
	}
	 for (int val : nums) {
        cout << val << " ";
    }
	
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 50};
    

    linearVec(nums);

    return 0;
}
