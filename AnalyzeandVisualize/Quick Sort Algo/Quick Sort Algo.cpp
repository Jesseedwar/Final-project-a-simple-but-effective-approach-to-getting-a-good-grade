#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <stack>
#include <algorithm>

// This Function to generates the random ELO data
std::vector<int> generateRandomELOData(size_t size) {
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1000, 3000);

    for (size_t i = 0; i < size; ++i) {
        data[i] = dist(gen);
    }
    return data;
}

// Iterative Quick Sort implementation
void iterativeQuickSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    std::stack<std::pair<size_t, size_t>> stack;
    stack.push(std::make_pair(0, arr.size() - 1));

    while (!stack.empty()) {
        std::pair<size_t, size_t> range = stack.top();
        stack.pop();

        size_t low = range.first;
        size_t high = range.second;

        if (low < high) {
            int pivot = arr[high];
            size_t i = low;

            for (size_t j = low; j < high; j++) {
                if (arr[j] <= pivot) {
                    std::swap(arr[i], arr[j]);
                    i++;
                }
            }
            std::swap(arr[i], arr[high]);
            size_t pi = i;

            // This push partitions onto the stack
            if (pi > 0) stack.push(std::make_pair(low, pi - 1));
            stack.push(std::make_pair(pi + 1, high));
        }
    }
}

// Merge Sort implementation
void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (size_t i = 0; i < n1; i++) L[i] = arr[left + i];
    for (size_t i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Analyze and visualize performance of both
void analyzeAndVisualizePerformance() {
    std::vector<size_t> datasetSizes = { 100, 1000, 10000, 100000, 1000000 };

    std::cout << "Analyzing performance on different input types:\n";

    for (size_t size : datasetSizes) {
        std::cout << "\nDataset size: " << size << "\n";

        std::vector<int> randomData = generateRandomELOData(size);
        std::vector<int> sortedData = randomData;
        std::sort(sortedData.begin(), sortedData.end());
        std::vector<int> reversedData = sortedData;
        std::reverse(reversedData.begin(), reversedData.end());

        // Random Data
        {
            auto quickStart = std::chrono::high_resolution_clock::now();
            iterativeQuickSort(randomData);
            auto quickEnd = std::chrono::high_resolution_clock::now();
            double quickTime = std::chrono::duration<double>(quickEnd - quickStart).count();
            std::cout << "Quick Sort (Random): " << quickTime << " seconds.\n";

            auto mergeStart = std::chrono::high_resolution_clock::now();
            mergeSort(randomData, 0, randomData.size() - 1);
            auto mergeEnd = std::chrono::high_resolution_clock::now();
            double mergeTime = std::chrono::duration<double>(mergeEnd - mergeStart).count();
            std::cout << "Merge Sort (Random): " << mergeTime << " seconds.\n";
        }

        // Sorted Data
        {
            auto quickStart = std::chrono::high_resolution_clock::now();
            iterativeQuickSort(sortedData);
            auto quickEnd = std::chrono::high_resolution_clock::now();
            double quickTime = std::chrono::duration<double>(quickEnd - quickStart).count();
            std::cout << "Quick Sort (Sorted): " << quickTime << " seconds.\n";

            auto mergeStart = std::chrono::high_resolution_clock::now();
            mergeSort(sortedData, 0, sortedData.size() - 1);
            auto mergeEnd = std::chrono::high_resolution_clock::now();
            double mergeTime = std::chrono::duration<double>(mergeEnd - mergeStart).count();
            std::cout << "Merge Sort (Sorted): " << mergeTime << " seconds.\n";
        }

        // Reversed Data
        {
            auto quickStart = std::chrono::high_resolution_clock::now();
            iterativeQuickSort(reversedData);
            auto quickEnd = std::chrono::high_resolution_clock::now();
            double quickTime = std::chrono::duration<double>(quickEnd - quickStart).count();
            std::cout << "Quick Sort (Reversed): " << quickTime << " seconds.\n";

            auto mergeStart = std::chrono::high_resolution_clock::now();
            mergeSort(reversedData, 0, reversedData.size() - 1);
            auto mergeEnd = std::chrono::high_resolution_clock::now();
            double mergeTime = std::chrono::duration<double>(mergeEnd - mergeStart).count();
            std::cout << "Merge Sort (Reversed): " << mergeTime << " seconds.\n";
        }
    }
}

int main() {
    try {
        std::cout << "Starting performance analysis...\n";
        analyzeAndVisualizePerformance();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
