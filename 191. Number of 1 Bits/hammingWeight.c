int hammingWeight(uint32_t n) {
    unsigned int temp = n;
    int ans = 0;
    for(int i = 0; i < 32; i++){
        if( ( temp >> i ) & 1 )
            ans++;
    }
    return ans;
}