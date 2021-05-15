uint32_t reverseBits(uint32_t n) {
    for(int i = 0; i < 16; i++){
        if( n & ( 1u << i ) ){
            if( !(n & ( 1u << (31-i) ))){
                n = n | ( 1u << (31-i) );
                n = n & (~( 1u << i ));
            }
        }
        else{
            if( n & ( 1u << (31-i) ) ){
                n = n | ( 1u << i );
                n = n & (~( 1u << (31-i) ));
            }
        }
    }
    return n;
}