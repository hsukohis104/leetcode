int climbStairs(int n){
    unsigned long long int dp_table[46];
    dp_table[0] = 1;
    dp_table[1] = 2;
    int i = 2;
    while( i <= n ){
        dp_table[i] =  dp_table[i-1] + dp_table[i-2];
        i++;
    }
    return dp_table[i-2];
}