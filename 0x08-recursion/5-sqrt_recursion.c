int _sqrt_recursion(int n) {
    if (n < 0) {
        return -1; // Error: negative number
    }
    else if (n == 0 || n == 1) {
        return n; // Base case: square root of 0 or 1 is the number itself
    }
    else {
        return sqrt_recursive(n, 1, n); // Initial recursive call with search space [1, n]
    }
}
