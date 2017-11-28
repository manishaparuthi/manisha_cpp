int j = 0;
        for(int i = 0; i < n; ++i) {
            while(j < n && arr[i] < arr[j]) {
                j++;
            }
        }
        
        
        /* the complexity of this code is: O(n).
        As j is not intitalizing inside the for loop */
