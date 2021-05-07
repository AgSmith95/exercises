#include <iostream>
#include <vector>

int find(int val, const std::vector<int>& arr) {
    int left = 0;
    int right = arr.size();
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == val) {
            return mid;
        }

        if (arr[mid] < val) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    std::cout << find(5, arr1) << '\n';

    std::vector<int> arr2 = {3,3,3,3,3,3};
    std::cout << find(5, arr2) << '\n';

    std::vector<int> arr3 = {6,6,6,6,6,6,6};
    std::cout << find(5, arr3) << '\n';

    std::vector<int> arr4 = {5,5,5,5,5,5,5,5,5,5};
    std::cout << find(5, arr4) << '\n';

    std::vector<int> arr5 = {};
    std::cout << find(5, arr5) << '\n';

    std::vector<int> arr6 = {1,2,2,2,2,3,4,5,6,7,8,8,8,9,9,9,9,10};
    std::cout << find(5, arr6) << '\n';
    return 0;
}