class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
         set<int> s;
        for(auto &x: mp ){
            if(s.contains(x.second)){
                return false;
            }

            s.insert(x.second);
        }

        return true;
 

    }
};