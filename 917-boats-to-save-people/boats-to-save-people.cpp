class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        // int ans =0;
        // int sum =0 ;
        // for(int i=0 ; i<people.size() ; i++){
        //     sum += people[i];
        // }
        // if((sum % limit) ==0) return (sum / limit)+1;
        // else{
        //     ans = (sum / limit) +1;
        // }
        // return ans;

        int ans=0;
        for(int l=0, r=people.size()-1 ; l<=r ; r--){
            ans++;
            if (people[l]<=limit-people[r])
                l++;          
        }
        return ans;
    }
};