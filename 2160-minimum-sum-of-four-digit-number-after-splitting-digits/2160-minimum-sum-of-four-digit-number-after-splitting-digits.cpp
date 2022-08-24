class Solution {
public:
    int minimumSum(int num) {
        priority_queue<int , vector<int> , greater<int>> pq;
        while(num > 0){
            pq.push(num % 10);
            num/=10;
        }
        int sum1 =0,sum2 = 0;
        sum1 += pq.top() * 10;
        pq.pop();
        sum2 += pq.top() * 10;
        pq.pop();
        sum1 += pq.top();
        pq.pop();
        sum2 += pq.top();
        pq.pop();
        return sum1 + sum2;
    }
};