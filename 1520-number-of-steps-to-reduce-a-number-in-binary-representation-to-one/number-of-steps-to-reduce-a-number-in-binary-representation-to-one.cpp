class Solution {
public:
    int numSteps(string s) {
        // unsigned long long num =0;
        // for(int i=0 ; i<s.length() ; i++){
        //     if(s[s.length() - i -1] == '1' ) num+= pow(2,i);
        // }
        // unsigned long long ans=0;
        // cout<<num;
        // while(num != 1 ){
        //     if(num % 2 == 0) num /= 2;
        //     else num++; 
        //     ans++;
        // }
        // return ans;


        int ans=0;
        int carry=0;
        for(int i=s.length()-1 ; i>0 ; i--){
            if(s[i]- '0'+carry == 1 ) {
                ans+=2;
                carry=1;
            }
            else ans++;
        }

        return ans+carry;
    }
};