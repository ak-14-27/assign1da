#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}


int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;


    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}


int maxSubArraySum(int arr[], int left, int right) {
   
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    return max(
        maxSubArraySum(arr, left, mid),
        maxSubArraySum(arr, mid + 1, right),
        maxCrossingSum(arr, left, mid, right)
    );
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}
