public class lc50 {
    public double myPow(double x, int n) {
        if (n == 0) return 1;
        double pw = myPow(x, n/2);
        if (n%2 != 0) return (pw*pw) * (n > 0 ? x : 1/x);
        return (pw*pw);
    }
}
