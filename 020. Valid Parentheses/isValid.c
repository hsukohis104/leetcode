bool isValid(char * s){
    char stack[3800];
    int stack_top = 0;;
    while( s[0] != '\0' ){
        if( s[0] == '(' || s[0] == '{'|| s[0] == '[' ){
            stack[stack_top] = s[0];
            stack[++stack_top] = '\0';
        }
        else{
            if(stack_top == 0)
                return false;
            stack_top--;
            if( !((s[0] == ')' && stack[stack_top] =='(' ) || ( s[0] == '}' && stack[stack_top] =='{' ) 
                  || ( s[0] == ']' && stack[stack_top] =='[' )) ){
                return false;
            }
            stack[stack_top] = '\0';
        }
        s++;   
    }
    if( stack_top > 0 )
        return false;
    return true;
}