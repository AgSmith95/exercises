#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

/**
 * Rearrange the array in such a way that the
 *   sum of the elements of the first half is equal to the
 *   sum of the elements of the second half
 */

string arrToStr(int arr[], int arrLength) {
    string res;
    if (arrLength == 0) {
        return res;
    }
    res.append(std::to_string(arr[0]));
    for (int i = 1; i < arrLength; ++i) {
        res.append(",");
        res.append(std::to_string(arr[i]));
    }
    return res;
}

string ParallelSums(int arr[], int arrLength) {
    int sum = std::accumulate(arr, arr+arrLength, 0);
    if (sum % 2 == 1) {
        return "-1";
    }
    std::sort(arr, arr+arrLength);
    sum /= 2;
    if ((arr[0] + arr[arrLength-1]) > sum) {
        return "-1";
    }
    if (arrLength == 2) {
        return arrToStr(arr, arrLength);
    }
    int l = 1, r = arrLength - 1;
    while (l < r) {
        std::swap(arr[l], arr[r]);
        l += 2;
        r -= 2;
    }
    int suml = std::accumulate(arr, arr+(arrLength/2 - 1), 0);
    int sumr = std::accumulate(arr+(arrLength/2 + 1), arr+arrLength, 0);
    if (suml + arr[arrLength/2] == sum) {
        suml += arr[arrLength/2];
        sumr += arr[arrLength/2 - 1];
        std::swap(arr[arrLength/2], arr[arrLength/2 - 1]);
    }
    else if (suml + arr[arrLength/2 - 1] == sum) {
        suml += arr[arrLength/2 - 1];
        sumr += arr[arrLength/2];
    }
    if (suml != sumr) {
        return "-1";
    }
    std::sort(arr, arr+(arrLength/2));
    std::sort(arr+(arrLength/2), arr+arrLength);
    return arrToStr(arr, arrLength);
}

int main() {
    int A[] = {16, 22, 35, 8, 20, 1, 21, 11}; // 1,11,20,35,  8,16,21,22 -- 67
//    int A[] = {1,2,3,4}; // 1,4,  2,3 -- 5
//    int A[] = {1, 5, 3, 4, 5, 2}; // 1,4,5,  2,3,5 -- 10
    int arrLength = sizeof(A) / sizeof(*A);
    cout << ParallelSums(A, arrLength) << "\n";
    return 0;
}