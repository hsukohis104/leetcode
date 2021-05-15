int countPrimes(int n){
    int * table = (int *)malloc(sizeof(int)* n);
    memset(table, 0, n*sizeof(int));
    int ans = 0;
    for(int i = 2; i < n; i++){
        if(!table[i]){
            ans++;
            int count = 1;
            int index = i * count++;
            while(index < n){
                table[index] = 1;
                index = i * count++;
            }
        }
    }
    return ans;
}