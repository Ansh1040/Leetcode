class Solution {
public:
    // int getLucky(string s, int k) {
    //     // Convert each character in the string to its corresponding numeric value
    //     string number = "";
    //     for (char x : s) {
    //         number += to_string(x - 'a' + 1);
    //     }
        
    //     // Perform the transformation `k` times
    //     while (k > 0) {
    //         int temp = 0;
    //         for (char x : number) {
    //             temp += x - '0';  // Sum the digits of the current number
    //         }
    //         number = to_string(temp);  // Convert the sum back to a string
    //         k--;
    //     }
    //     return stoi(number);  // Return the final result as an integer
    // }

    int sumDigits(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sum = 0 ; 
        for(auto it: s){
            int value = it - 'a' + 1;
            if(value>=10){
                sum+= value%10 + value/10; 
            }else
                sum = sum + value; 
        }

        k--;//since I did the sum once;
        while(k-- && sum>=10){//furthur trasformations starts here
            sum = sumDigits(sum);
        } 
        return sum;
    }


};