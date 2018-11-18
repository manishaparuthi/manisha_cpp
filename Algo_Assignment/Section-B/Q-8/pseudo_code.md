# Algorithm
### - O(n^2) approach - Greedy Aprroach


        Procedure: MinmumCost(rate[1.....n])
        1.Input : Array rate of size n
        2.Output : An order in which to buy the license so that the total amount spent is minimized.
        3.sort the rate array  in decreasing order according to rate value//selection sort is used here(n^2 because question demands polynomial in n
        4.month =  1
        5.base = 100
        6.total_cost = 0 //initialize
        7.for i =1 to n 
        8.     cost for ith license = rate[i] * month * base 
        9.      month = month + 1
        10.     total_cost += cost for ith license
