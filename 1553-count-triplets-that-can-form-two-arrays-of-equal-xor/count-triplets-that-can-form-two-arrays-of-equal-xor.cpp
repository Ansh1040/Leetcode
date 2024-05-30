class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // int n = arr.size();
        // int pairs = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int a = 0;
        //         for(int k=i; k<j; k++){
        //             a ^= arr[k];
        //         }
                
        //         int b = 0;

        //         for(int k=j; k<n; k++){
        //             b ^= arr[k];
        //             if(a == b){
        //                 pairs++;
        //             }
        //         }
        //     }
            
        // }
        // return pairs;                                 brute force

        vector<int> prefixXor(begin(arr), end(arr));

        prefixXor.insert(prefixXor.begin(), 0); //initially the xor cumulative will be 0
        int n = prefixXor.size();

        for(int i = 1; i < n; i++) {
            prefixXor[i] ^= prefixXor[i-1];
        }

        int triplets = 0;

        for(int i = 0; i < n; i++) {
            for(int k = i+1; k < n; k++) {

                if(prefixXor[k] == prefixXor[i]) {
                    triplets += k-i-1;
                }

            }
        }

        return triplets;


    }
};