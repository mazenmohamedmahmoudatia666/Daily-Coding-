class Solution {
public:
    bool isPowerOfTwo(int n) {

        
        for(int i =0;i<31;i++){
        int ans = pow(2,i);
            
            if(ans == n)return true;

        }
        return false;
    }
};

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        
        while(n>0){
            if(n==1)return true;
            if(n %2 !=0)break;
            n /=2;
        }
        return false;
    }
};

*/