bool binary_search (int arr[], const int KEY, int left, int right) {
    int mid;
    
    if (left > right) return false;
    
    mid = (left + right) >> 1;
    
    if (arr[mid] == KEY) {
        return true;
    }
    else if (arr[mid] > KEY) {
        return binary_search(arr, KEY, left, mid - 1);
    }
    else {
        return binary_search(arr, KEY, mid + 1, right);
    }
}
