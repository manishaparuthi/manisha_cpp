# Algorithm 
### Assumption: 
It is assumed that we will buy on some day and sell on some later day,means we will not buy multiple times 
 (we can do only one transaction).

    Procedure max_profit(price[1...n]):
    Input : Array Price of size n
    Output : max_profit 
	  1.	min_el = price[0]
	  2.	max_diff = price[1] - price[0]
      3.  buy = 0
      4.  sell = 1
	  5.  temp = 0
      6.	for i = 0 to n-1
	  7.		  if price[i] - min_el > max_diff
	  8.			  max_diff = price[i] - min_el
	  9.			  buy = temp
	  10.		    sell = i
	  11.		  if price[i] < min_el
	  12.			  min_el = price[i]
	  13.			  temp = i
	  14.	    if max_diff <= 0
	  15.		    print "No buy and sell days".
      16.  return max_diff
    
    
 # Time Complexity
    
      1. Line 1-5 would take constant time
      2. Line 6-16 would take O(n) time. (for loop running n times)
      
  ## Hence time complexity is O(n)
