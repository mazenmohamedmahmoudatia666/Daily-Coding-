class KthLargest {
    // 'num' stores the value of k, which represents the kth largest element.
    int num; 
    
    // Priority queue 'pq' to store the top k largest elements.
    // It's a min-heap (smallest element at the top) using 'greater<int>'.
    priority_queue<int, vector<int>, greater<int>> pq;
    
public:
    // Constructor that initializes the KthLargest object.
    // 'k' is the kth largest element we want to track, and 'nums' is the initial list of numbers.
    KthLargest(int k, vector<int>& nums) {
        num = k; // Set the value of k.
        
        // Iterate through each element in the initial list 'nums'.
        for (auto ele : nums) {
            // Push the current element into the priority queue.
            pq.push(ele);
            
            // If the size of the priority queue exceeds k,
            // pop the smallest element to maintain only the top k largest elements.
            if (pq.size() > k) pq.pop();
        }
    }
    
    // Function to add a new value 'val' to the KthLargest object.
    // It returns the kth largest element after the addition.
    int add(int val) {
        // Add the new value to the priority queue.
        pq.push(val);
        
        // If the size of the priority queue exceeds k,
        // pop the smallest element to maintain the size at k.
        if (pq.size() > num) pq.pop();
        
        // The kth largest element is now the smallest element in the priority queue.
        return pq.top();
    }
};
