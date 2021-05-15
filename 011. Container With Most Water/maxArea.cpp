#include<vector>
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> all_pair;
        int index = 0;
        for(auto i : height)
            all_pair.push_back(make_pair(i,index++));
        vector<int> result;
        int max = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<j){
            int tall = 0;
            int widthi = all_pair[i].second;
            int widthj = all_pair[j].second;
            if( all_pair[j].first > all_pair[i].first )
                tall = all_pair[i++].first;
            else
                tall = all_pair[j--].first;   
            if( (widthj - widthi) * tall > max )
                max = ( widthj - widthi) * tall;
        }
        return max;
    }
};