class Solution {
public:
long helper(vector<int> &ar , int si , int ei , int target , long sum , vector<int> &output){
    if(target == sum){
        return 1;
    }

    if(sum > target){
        return 0;
    }

    if(output[sum] != -1)
    {
        return output[sum];
    }

    int ans = 0;
    for (int i = 0; i <= ei; i++)
    {   
        ans += helper(ar , i , ei , target , sum + ar[i] , output);
    }

    output[sum] = ans;
    return ans;

}

int combinationSum4(vector<int> &ar , int target){
    int n = ar.size();
    vector<int> output(target + 1 , -1);
    return helper(ar , 0 , n - 1 , target , 0 , output);
}
};