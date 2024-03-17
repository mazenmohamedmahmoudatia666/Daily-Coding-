class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int count = 0;
        int n = dist.size();
        vector<double> time(n);

        for(int i = 0; i < n; i++)
        {
            time[i] = (double)dist[i] / speed[i];
        }
       // [1,1,2,3], speed = [1,1,1,1]
        sort(time.begin(),time.end());
       //  1 1 2 3

        int t = 0;
        // 1
        for(auto x : time)
        {
            if(x > t)
            {
                count++;
                t++;
            }
            else break;
        }

        return count;
    }
};