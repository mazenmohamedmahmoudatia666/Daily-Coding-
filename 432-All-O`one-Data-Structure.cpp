class AllOne {
public:
    // Ordered set to store counts in ascending order, this will help in getting the minimum count key
    set<pair<int, string>> incrs;
    
    // Ordered set (with greater<>) to store counts in descending order, this helps in getting the maximum count key
    set<pair<int, string>, greater<>> decrs;
    
    // Unordered map to store the count of each string in constant time
    unordered_map<string, int> um;

    // Constructor to initialize the data structure
    AllOne() {
    }

    // Function to increment the count of a string key
    void inc(string key) {
        // If the key already exists, remove the previous count from both sets
        if (um.find(key) != um.end()) {
            incrs.erase({um[key], key});
            decrs.erase({um[key], key});
        }
        
        // Increment the count in the unordered_map
        um[key]++;

        // Insert the updated count of the key into both sets
        incrs.insert({um[key], key});
        decrs.insert({um[key], key});
    }

    // Function to decrement the count of a string key
    void dec(string key) {
        // If the key exists, remove the previous count from both sets
        if (um.find(key) != um.end()) {
            incrs.erase({um[key], key});
            decrs.erase({um[key], key});
        }
        
        // Decrement the count in the unordered_map
        um[key]--;

        // If the count is greater than 0, insert the updated count into both sets
        if (um[key] > 0) {
            incrs.insert({um[key], key});
            decrs.insert({um[key], key});
        } else {
            // If the count becomes 0, remove the key from the unordered_map
            um.erase(key);  
        }
    }

    // Function to get the key with the maximum count
    string getMaxKey() {
        // If the set is empty, return an empty string
        if (decrs.empty()) {
            return \\;
        }
        // The first element in decrs has the highest count, return its key
        return decrs.begin()->second;
    }

    // Function to get the key with the minimum count
    string getMinKey() {
        // If the set is empty, return an empty string
        if (incrs.empty()) {
            return \\;
        }
        // The first element in incrs has the lowest count, return its key
        return incrs.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * std::string param_3 = obj->getMaxKey();
 * std::string param_4 = obj->getMinKey();
 */