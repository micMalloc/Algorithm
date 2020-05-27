void permutation (int arr[], int set_size, const int SIZE, const int THRESHOLD) {
    if (set_size == THRESHOLD) {
        return;
    }
    
    for (int idx = set_size; idx < SIZE; ++ idx) {
        swap(arr[set_size], arr[idx]);
        permutation(arr, set_size + 1, SIZE, THRESHOLD);
        swap(arr[set_size], arr[idx]);
    }
}
