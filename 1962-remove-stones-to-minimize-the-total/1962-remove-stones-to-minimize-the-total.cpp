class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int> heap(piles.begin(), piles.end());
        
        int sum = 0;
        for(int num : piles){
            sum += num;
        }
        
        while(k>0){
            int top = heap.top(); heap.pop();
            int remove = floor(top/2);
            top -= remove;
            sum -= remove;
            
            heap.push(top);
            k--;
        }
        
        return sum;
    }
};