

int getSum(int a, int b){
    int ans = 0;
    int carry = 0;
    for(int i = 0; i < 32; i++){
        if((a & 1) && (b & 1) ){
            if(carry)
                ans |= (1u << i);
            carry = 1;   
        }
        else if( (a & 1) || (b & 1) ){
            if(carry)
                carry = 1;  
            else{
                ans |= (1u << i);
                carry = 0;
            }
        }
        else{
            if(carry){
                ans |= (1u << i);
                carry = 0;  
            }
        }
        a = a >> 1;
        b = b >> 1;
    }
    return ans;
}