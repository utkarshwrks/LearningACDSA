#include <iostream>
#include <vector>
using namespace std;

void linearVec(vector<int>& nums, int target) {
    bool found = false;  

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            cout << "Found position = " << i << endl;  
            found = true;
            break;  
        }
    }

    if (!found) {
        cout << "Not found" << endl;
    }
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 50};
    int target = 30;

    linearVec(nums, target);

    return 0;
}
