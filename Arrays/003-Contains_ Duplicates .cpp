class Solution {
public:
   
            bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;   //  "guest list" for fast lookups
        for (int n : nums) {       // Check each number one at a time
            if (seen.count(n)) {   // have I seen this before?
                return true;       // yes -> duplicate found!
            }
            seen.insert(n);        // no -> remember it for later
        }
        return false;              // got through the whole list, no repeats
    }
};
