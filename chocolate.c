#include <stdio.h>

int main() {
    int n, k;

    // Input n and k
    printf("Input n and k (separated by space): ");
    scanf("%d %d", &n, &k);

    int chocolates = n;  // Initial chocolates bought
    int wrappers = n;    // Initial wrappers

    // Exchange wrappers for additional chocolates
    while (wrappers >= k) {
        int exchanged_chocolates = wrappers / k;
        chocolates += exchanged_chocolates;
        wrappers = exchanged_chocolates + (wrappers % k);
    }

    // Display the total chocolates Sahil can have
    printf("Total Chocolates: %d\n", chocolates);

    return 0;
}
