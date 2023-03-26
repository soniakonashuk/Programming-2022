#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

void counting_sort(int arr[], int n) {
    // Find the maximum element in the input array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Create an array to store the count of each element
    int* count = new int[max_element + 1];
    for (int i = 0; i <= max_element; i++) {
        count[i] = 0;
    }

    // Store the count of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the count array to store the prefix sum
    for (int i = 1; i <= max_element; i++) {
        count[i] += count[i - 1];
    }

    // Generate the sorted output array
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted output array to the input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the dynamically allocated arrays
    delete[] count;
    delete[] output;
}

// Tests using doctest
TEST_CASE("Sort an array of one element") {
    int arr[] = { 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);

    int expected[] = { 1 };
    for (int i = 0; i < n; i++) {
        CHECK(arr[i] == expected[i]);
    }
}

TEST_CASE("Sort an array of multiple elements") {
    int arr[] = { 5, 3, 1, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);

    int expected[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < n; i++) {
        CHECK(arr[i] == expected[i]);
    }
}

TEST_CASE("Sort an array with duplicate elements") {
    int arr[] = { 5, 3, 1, 4, 2, 3, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);

    int expected[] = { 1, 1, 2, 3, 3, 4, 5, 5 };
    for (int i = 0; i < n; i++) {
        CHECK(arr[i] == expected[i]);
    }
}

