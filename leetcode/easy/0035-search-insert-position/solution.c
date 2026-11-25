int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found at index mid
        } 
        else if (nums[mid] < target) {
            left = mid + 1; // Target lies to the right
        } 
        else {
            right = mid - 1; // Target lies to the left
        }
    }

    // If not found, 'left' is the proper insertion index
    return left;
}