int mySqrt(int x){ 
    long start = 0;
    long end = x;
    long mid = x / 2;
    long ans = 0;
    while( start <= mid && mid <= end){    
        if( mid * mid <= x ){
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
        mid = (start + end)/2;
    }
    return ans;
}