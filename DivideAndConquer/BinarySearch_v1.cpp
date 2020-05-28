bool binary_search (int arr[], const int SIZE, const int KEY) {
    int left, right, mid;
    
    left = 0;
    right = SIZE - 1;
    
    while (left <= right) {
        mid = (left + right) >> 1;
        
        if (arr[mid] == KEY) {
            return true;
        }
        else if (arr[mid] > KEY) {
            right = mid - 1;
        }
        else left = mid + 1;
    }
    
    return false;
}
