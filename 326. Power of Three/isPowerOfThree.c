

bool isPowerOfThree(int n){
    int temp = n;
    if(n <= 0 )
        return false;
    while(temp%3==0){
        temp/=3;
    }
    if(temp==1)
        return true;
    return false;
}