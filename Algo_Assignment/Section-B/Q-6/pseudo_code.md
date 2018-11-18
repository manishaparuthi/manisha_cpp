# Algorithm for finding Majority Element 
### - O(n.logn) approach - Divide and Conquer 
           
        Procedure GetMajorityElement(A[1...n])
        Input:  Array A of objects
        Output:  Majority element of A,element that occurs more than n/2 times.
        if n = 1:  
              return A[1]
        mid = ⌊n/2⌋
        left_major = GetMajorityElement(A[1...mid])
        right_major = GetMajorityElement(A[mid+1...n]
        if left_major == right_major:
            return left_major
        left_count = GetFrequency(A[1...n],left_major)   //count frequency of left_major in array A
        right_count = GetFrequency(A[1...n],right_major) //count frequency of right major in array A
        if left_count > mid+1:
            return left_major
        else if right_count > mid+1:
            return right_major
        else 
            return NO-MAJORITY-ELEMENT




      
