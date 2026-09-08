class RandomizedCollection {
public:

    vector<int> nums;

    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {
    }

    bool insert(int val) {

        bool existed = mp.count(val);

        nums.push_back(val);

        mp[val].insert(nums.size() - 1);

        return !existed;
    }

    bool remove(int val) {

        if (!mp.count(val)) {
            return false;
        }

        // Get any index of val
        int idx = *mp[val].begin();

        // Last index
        int lastIdx = nums.size() - 1;

        // Last value
        int lastVal = nums[lastIdx];

        // Remove val's index
        mp[val].erase(idx);

        // If val's set becomes empty
        if (mp[val].empty()) {
            mp.erase(val);
        }

        // Replace target with last element
        if (idx != lastIdx) {

            nums[idx] = lastVal;

            // Last element's old index
            mp[lastVal].erase(lastIdx);

            // Last element's new index
            mp[lastVal].insert(idx);
        }

        // Remove last element
        nums.pop_back();

        return true;
    }

    int getRandom() {

        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */