class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int st=0;
        int end=n-1;

        while((end-st+1)>k){
            int first=abs(arr[st]-x);
            int last=abs(arr[end]-x);
            if (first <= last) {
                end--;
            } else {
                st++;
            }
        }
          return vector<int>(arr.begin() + st, arr.begin() + end + 1);
    }
};