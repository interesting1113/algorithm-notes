const int N = 2e4 + 10;

class MyHashSet {
public:
    vector<int> hash[N];

    MyHashSet() {

    }

    int find(int index, int key) {
        for (int i = 0; i < hash[index].size(); i ++) {
            if (hash[index][i] == key) {
                return i;
            }
        }
        return -1;
    }

    void insert(int index, int key) {
        hash[index].push_back(key);
    }

    void add(int key) {
        int t = key % N;
        int k = find(t, key);
        if (k == -1) insert(t, key);
    }

    void remove(int key) {
        int t = key % N;
        int k = find(t, key);
        if (k != -1) hash[t].erase(hash[t].begin() + k);
    }

    bool contains(int key) {
        int t = key % N;
        int k = find(t, key);
        return k != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */