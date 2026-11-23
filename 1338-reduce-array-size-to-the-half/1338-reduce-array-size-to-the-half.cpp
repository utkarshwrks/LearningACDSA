class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int x: arr){
            mp[x]++;
        }
        priority_queue<int> pq;

        for(auto it : mp){
            pq.push(it.second);
        }

        int target=n/2;
        int sum=0;
        int cnt=0;

        while(sum<target){
            sum += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;


    }
};