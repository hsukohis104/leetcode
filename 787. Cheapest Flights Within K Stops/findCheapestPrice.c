int Relaxation(int a, int b, int c){
    if( a + b < c )
        return a + b;
    else
        return c;
}
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    int ** dp_table = (int**)malloc( n * sizeof(int*));
    for(int i = 0; i < n; i++){
        dp_table[i] = (int*)malloc(sizeof(int)*(K+2));
        for(int j = 0; j < (K+2); j++){
            dp_table[i][j] = 1e9;
        }
            
    }
    dp_table[src][0] = 0;
    for(int i = 1; i < K + 2; i++){
        dp_table[src][i] = 0;
        for(int j = 0; j < flightsSize; j++){
            dp_table[flights[j][1]][i] = Relaxation( dp_table[flights[j][0]][i-1], flights[j][2], dp_table[flights[j][1]][i]);
        }
    }
    if( dp_table[dst][K+1] >= 1e9 )
        return  -1;
    else
        return dp_table[dst][K+1];  
}
