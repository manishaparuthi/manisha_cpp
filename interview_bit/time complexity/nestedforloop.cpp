 int a = 0;
    for (i = 0; i < N; i++) {
        for (j = N; j > i; j--) {
            a = a + i + j;
        }
    }

    /*
    Total number of runs = N + (N - 1) + (N - 2) + … 1 + 0

= N * (N + 1) / 2

= 1/2 * N^2 + 1/2 * N

O(N^2) times.
*/
