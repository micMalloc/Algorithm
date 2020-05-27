void combination (int arr[], int set_size, const int SIZE, const int THRESHOLD, int idx) {
    if (set_size == THRESHOLD) {
        return;
    }
    
    if (idx >= SIZE) return;
    
    arr[set_size] = idx;
    combination(arr, set_size + 1, SIZE, THRESHOLD, idx + 1);
    combination(arr, set_size, SIZE, THRESHOLD, idx + 1);
}
