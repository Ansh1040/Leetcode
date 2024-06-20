class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin() , position.end());
        int start = 1, end = position[n-1] - position[0];
        while(start< end){
            int mid = (start + end+1)>>1;
            if(isPossible(position, m, mid)){
                start = mid;
            }else{
                end = mid-1;
            }
        }
        return start;
    }
    bool isPossible(vector<int>&arr, int m , int dis){
        int n = arr.size();
        int count = 1;
        int prev = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-prev>=dis){
                prev= arr[i];
                count++;
            }
            if(count>=m) return true;
        }
        return false;

    }
};