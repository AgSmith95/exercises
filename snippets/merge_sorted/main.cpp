#include <iostream>

void merge_sprted(int *p1, int n1, int *p2, int n2) {
    int *p1c = p1 + n1 - 1,
        *p2c = p2 + n2 - 1,
        *p   = p1 + n1 + n2 - 1;
    while (p >= p1) {
        if ((p1c >= p1) && (p2c >= p2)) {
            if (*p1c > *p2c) {
                *p = *p1c;
                --p1c;
            }
            else {
                *p = *p2c;
                --p2c;
            }
        }
        else if (p1c < p1) {
            *p = *p2c;
            --p2c;
        }
        else {
            break;
        }
        --p;
    }
}

void print_arr(int *p, int len) {
    std::cout << "[ ";
    for (int *P = p; P < p+len; ++P) {
        std::cout << *P << ' ';
    }
    std::cout << "]\n";
}

int main() {
    {
        int arr1[] = {1, 3, 5, 10, 13, 0, 0, 0},
            arr2[] = {7, 8, 14};
        merge_sprted(arr1, 5, arr2, 3);
        print_arr(arr1, 8);
    }
    {
        int arr1[] = {5, 6, 7, 8, 9, 0, 0, 0},
            arr2[] = {1, 2, 3};
        merge_sprted(arr1, 5, arr2, 3);
        print_arr(arr1, 8);
    }
    {
        int arr1[] = {1, 2, 3, 0, 0, 0},
            arr2[] = {1, 2, 3};
        merge_sprted(arr1, 3, arr2, 3);
        print_arr(arr1, 6);
    }
    {
        int arr1[] = {2, 2, 3, 0, 0, 0},
                arr2[] = {1, 2, 3};
        merge_sprted(arr1, 3, arr2, 3);
        print_arr(arr1, 6);
    }
    std::cout << "\n";
    return 0;
}