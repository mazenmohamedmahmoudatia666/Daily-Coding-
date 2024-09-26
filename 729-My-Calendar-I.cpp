class MyCalendar {
private:
    vector<pair<int, int>> bookings; // To store booked intervals

public:
    // Constructor
    MyCalendar() {}
    
    // Book a new event
    bool book(int start, int end) {
        // Check if the new booking overlaps with any existing booking
        for (const auto& event : bookings) {
            int bookedStart = event.first;
            int bookedEnd = event.second;
            if (max(start, bookedStart) < min(end, bookedEnd)) {
                return false; 
            }
        }
        
        // No overlap found, so we can book the new event
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
