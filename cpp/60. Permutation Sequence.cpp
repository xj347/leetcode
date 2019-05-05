class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> num_seq(n, 1);
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; i++)
        {
            num_seq[i] = i+1;
            factorial[i] = factorial[i-1] * i;
        }
        k--;
        for (int i = n-1; i >= 0; i--)
        {
            int p = k / factorial[i];
            k = k % factorial[i];
            res.push_back('0' + num_seq[p]);
            num_seq.erase(num_seq.begin() + p);
        }
        return res;
    }
};