

int reverse(int x){
    long temp;
    if(x<0){
        temp = x;
        temp *=(-1);
    }
    else
        temp = x;
    int size = 0;
    int x_temp[10];
    for(long i = temp; i > 0; i /= 10)
        x_temp[size++] = i%10;
    long count = 1;
    int ans = 0;
    for(int i = size - 1; i >= 0; i--){
        long over_check = count * x_temp[i];
        if(over_check > 2147483647)
            return false;
        ans += count * x_temp[i];
        count *= 10;
    }
    if(x < 0)
        ans *= (-1);
    if((x > 0 && ans < 0) || (x < 0 && ans > 0))
        return false;
    return ans;
}