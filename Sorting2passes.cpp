class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countzero=0,countone=0,counttwo=0;
    for(int i=0;i<nums.size();i++){
        
        if(nums[i]==0){
            countzero++;
        }
        else if(nums[i]==1){
            countone++;
        }else{
            counttwo++;
        }
    }
    int idx=0;
    for(int i=0;i<countzero;i++){
        nums[idx++]=0;
    }
    for(int i=0;i<countone;i++){
        nums[idx++]=1;
    }
    for(int i=0;i<counttwo;i++){
        nums[idx++]=2;
    }
    }
};