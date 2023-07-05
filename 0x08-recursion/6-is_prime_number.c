int is_prime_number_helper(int n, int divisor) {
    if (n <= 2) {
        // Base case: 2 is the smallest prime number
        return (n == 2) ? 1 : 0;
    }

    if (n % divisor == 0) {
        // If the number is divisible by the divisor, it's not prime
        return 0;
    } else if (divisor * divisor > n) {
        // If we have checked all possible divisors, it's prime
        return 1;
    }

    // Continue checking with the next divisor
    return is_prime_number_helper(n, divisor + 1);
}

int is_prime_number(int n) {
    // Call the helper function starting with divisor 2
    return is_prime_number_helper(n, 2);
}
