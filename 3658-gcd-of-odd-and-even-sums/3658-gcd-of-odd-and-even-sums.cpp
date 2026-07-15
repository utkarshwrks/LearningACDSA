class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int ev=0;
        int od=0;
        for(int i=1;i<=n*2;i++){
            if(i%2==0){
                ev+=i;
            }else{
                od+=i;
            }
        }
        return gcd(ev,od);
    }
};