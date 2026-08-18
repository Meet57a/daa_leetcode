class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    long dist(vector<int>& p) {
        return (long)p[0] * p[0] + (long)p[1] * p[1];
    }
    
    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) return;
        
        int pivotIdx = partition(points, left, right);
        
        int rank = pivotIdx - left + 1; // number of elements in [left, pivotIdx]
        
        if (rank == k) {
            return; // first k elements are exactly the k closest
        } else if (rank < k) {
            quickSelect(points, pivotIdx + 1, right, k - rank);
        } else {
            quickSelect(points, left, pivotIdx - 1, k);
        }
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        // Choose a random pivot to avoid worst-case O(n^2) on adversarial/sorted input
        int randIdx = left + rand() % (right - left + 1);
        swap(points[randIdx], points[right]);
        
        long pivotDist = dist(points[right]);
        int storeIdx = left;
        
        for (int i = left; i < right; i++) {
            if (dist(points[i]) < pivotDist) {
                swap(points[i], points[storeIdx]);
                storeIdx++;
            }
        }
        
        swap(points[storeIdx], points[right]);
        return storeIdx;
    }
};