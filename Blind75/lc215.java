import java.util.PriorityQueue;

public class lc215 {
    public int findKthLargest(int[] nums, int k){
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        // min heap
        for (int n : nums){
            heap.add(n);
            System.out.println(heap);
            if (heap.size() > k){
                System.out.println("heap: " + heap);
                System.out.println("removed: " + heap.poll());
              
            }
        }

        return heap.peek();
    }

    public static void main(String[] args) {
        lc215 lc = new lc215();
        int[] nums = {3,2,1,5,6,4};
        int k = 2;
        lc.findKthLargest(nums, k);

    }
}
