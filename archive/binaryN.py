# This function uses queu data structure to print binary numbers 
def generatePrintBinary(n): 
      
    # Create an empty queue 
    from Queue import Queue 
    q = Queue() 
      
    # Enqueu the first binary number 
    q.put("1") 
  
    # This loop is like BFS of a tree with 1 as root 
    # 0 as left child and 1 as right child and so on 
    while(n>0): 
        n-= 1 
        # Print the front of queue 
        s1 = q.get()  
        print(s1) 
      
        s2 = s1 # Store s1 before changing it 
      
        # Append "0" to s1 and enqueue it 
        q.put(s1+"0") 
  
        # Append "1" to s2 and enqueue it. Note that s2 
        # contains the previous front 
        q.put(s2+"1") 
      
  
# Driver program to test above function 
n = 10
generatePrintBinary(n) 