#include<iostream>
#include<string>
#include<map>
#include<vector>

class evictingHash {
  int map<string, string> hash_;
  int map<string, long> lastAccessTime_;

  vector<string> keyHeap_;
  map<string, int> heapIndex_;

  int maxSize_;
  int now_;

  void evictingHash(int maxSize) : maxSize_(maxSize), currSize_(0), now_(0) {}

  bool get(const string& key, string& val) {
    auto itr = hash_.find(key);
    if( itr != hash_.end()) {
      lastAccessTime_[key] = ++now_;
      increaseHeapKey(key, lastAccessTime_[key]);
      return true;
    }
    return false;
  }

  void put(const string& key, const string& value) {
    if (hash_.size() == maxSize_) {
      string lru = extractMinFromHeap();
      hash_.erase(hash_.find(lru));
      lastAccessTime_.erase(lastAccessTime_.find(lru));
    }
    hash_.insert(make_pair(key, value));
    lastAccessTime_[key] = ++now_;
    pushToHeap(key, lastAccessTime_[key]);
  }

  void del(const string& key) {
      hash_.erase(hash_.find(key));
      lastAccessTime_.erase(lastAccessTime_.find(key));
      deleteFromHeap(key);
  }

  void increaseHeapKey(const string& key, long val) {
    keyHeap_[heapIndex_[key]] = val;
    adjustHeap(heapIndex_[key]);
  }

  string extractMinFromHeap() {
    swap(keyHeap_[0], keyHeap_[keyHeap_.size()-1]);
    heapIndex_[keyHeap_[0]] = 0;
    string minKey = keyHeap_.pop_back();
    if (keyHeap_.size() != 0) {
      adjustHeap(0);
    }
    return minKey;
  }

  void clearHeapAtIndex(int idx) {
    swap(keyHeap_[idx], keyHeap_[keyHeap_.size()-1]);
    heapIndex_[keyHeap_[]] = 0;
  }

};

int main() {
}
