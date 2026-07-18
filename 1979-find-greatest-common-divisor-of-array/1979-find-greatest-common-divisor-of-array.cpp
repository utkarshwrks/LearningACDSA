class Solution {
public:
   
    int findGCD(vector<int>& nums) {
       int min=INT_MAX, max=INT_MIN;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<min){
min=nums[i];
        }if(nums[i]>max){
            max=nums[i];
        }

       }
        
        while(min>0&&max>0){
            if(min>max){
                min=min%max;
            }else{
                max=max%min;
            }
        }
        if(min==0) return max;
        return min;
    
        
    }
};