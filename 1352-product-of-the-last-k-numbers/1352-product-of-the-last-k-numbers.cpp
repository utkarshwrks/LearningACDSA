class ProductOfNumbers {
public:
    stack<int> s;

    ProductOfNumbers() {
        s.push(1);
    }

    void add(int num) {
        if(num == 0) {
            while(!s.empty()) s.pop();
            s.push(1);
        }
        else {
            s.push(s.top() * num);
        }
    }

    int getProduct(int k) {
        if(k >= s.size()) return 0;

        stack<int> temp = s;

        int total = temp.top();

        while(k > 0) {
            temp.pop();
            k--;
        }

        return total / temp.top();
    }
};