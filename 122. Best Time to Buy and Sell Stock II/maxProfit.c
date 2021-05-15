

int maxProfit(int* prices, int pricesSize){
    int total_profit = 0;
    int begin = 0;
    int lo_profit = 0;
    for(int i = 0; i + 1 < pricesSize; i++){
        if( prices[i+1] - prices[i] > 0  )
            lo_profit += prices[i+1] - prices[i];
        else if( prices[i+1] - prices[i] < 0  ){
            begin = i+1;
            total_profit += lo_profit;
            lo_profit = 0;
        }
    }
    if(  lo_profit != 0 )
        total_profit += lo_profit;
    return total_profit;
}