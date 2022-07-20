public class lc134 {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int res = 0;
        int sum = 0;
        int totalGas = 0;
        int totalCost = 0;
        
        for (int i = 0; i < gas.length; i++){
            sum += gas[i] - cost[i];
            if (sum < 0){
                sum = 0;
                res = i + 1;
            }
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if (totalGas < totalCost){
            return -1;
        } else {
            return res;
        }
    }
}
