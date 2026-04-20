class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int slow = 0;
        int fast = 1;
      
        int n = prices.size();
      
        int max_diff = 0;
        int diff = 0;
      
        for(int fast = 1;fast<n;fast++){
            if(prices[fast] > prices[slow]){
                diff = prices[fast] - prices[slow];
                max_diff = max(diff,max_diff); 
            }
            else slow = fast;
        }
        return max_diff;
    }
};
