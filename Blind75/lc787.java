import java.util.*;

public class lc787 {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] prices = new int[n];
        Arrays.fill(prices, Integer.MAX_VALUE);
        prices[src] = 0;
        for (int i = 0; i <= k; i++){
            // make copy of prices
            int[] tmp = Arrays.copyOf(prices, n);
             // System.out.println("tmp[next]: " + Arrays.toString(tmp));
            for (int[] flight : flights){
                int cur = flight[0], next = flight[1], price = flight[2];
                // System.out.println("int[]: " + Arrays.toString(flight));
                if (prices[cur] == Integer.MAX_VALUE) continue;
               
                tmp[next] = Math.min(tmp[next], prices[cur] + price);
                 // System.out.println("tmp[next]: " + tmp[next]);
            }
            prices = tmp;
        }
        return prices[dst] == Integer.MAX_VALUE ? -1 : prices[dst];
    }
}
