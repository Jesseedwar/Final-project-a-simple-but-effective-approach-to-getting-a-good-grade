#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <stdexcept>
#include <algorithm>

// Function to generate random ELO data for 3. Scalability Analysis
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

// Merge Sort implementation
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort implementation
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// This Function is for performing scalability analysis
void processAndMeasure(const std::string& sortType) {
    size_t maxSize = 1000000;
    size_t step = 10000;

    for (size_t size = step; size <= maxSize; size += step) {
        std::vector<int> data = generateRandomELOData(size);
        auto start = std::chrono::high_resolution_clock::now();

        if (sortType == "Quick Sort") {
            quickSort(data, 0, data.size() - 1);
        }
        else if (sortType == "Merge Sort") {
            mergeSort(data, 0, data.size() - 1);
        }

        auto end = std::chrono::high_resolution_clock::now();
        double timeTaken = std::chrono::duration<double>(end - start).count();
        std::cout << sortType << " processed " << size << " elements in " << timeTaken << " seconds.\n";
    }
}

// This Function is used to measure and compare the space complexity
void scalabilityAnalysis() {
    std::vector<size_t> datasetSizes = { 100, 1000, 10000, 100000, 1000000 };
    std::cout << "Scalability Analysis:\n";

    for (size_t size : datasetSizes) {
        std::cout << "\nDataset size: " << size << "\n";

        // Generate random data
        std::vector<int> data = generateRandomELOData(size);

        // Test for Quick Sort
        std::vector<int> quickData = data;
        auto quickStart = std::chrono::high_resolution_clock::now();
        quickSort(quickData, 0, quickData.size() - 1);
        auto quickEnd = std::chrono::high_resolution_clock::now();
        double quickTime = std::chrono::duration<double>(quickEnd - quickStart).count();
        std::cout << "Quick Sort time: " << quickTime << " seconds.\n";

        // Test for Merge Sort
        std::vector<int> mergeData = data;
        auto mergeStart = std::chrono::high_resolution_clock::now();
        mergeSort(mergeData, 0, mergeData.size() - 1);
        auto mergeEnd = std::chrono::high_resolution_clock::now();
        double mergeTime = std::chrono::duration<double>(mergeEnd - mergeStart).count();
        std::cout << "Merge Sort time: " << mergeTime << " seconds.\n";
    }
}

// This function to measure and compare memory usage
void measureSpaceComplexity() {
    std::vector<size_t> datasetSizes = { 100, 1000, 10000, 100000, 1000000 };
    std::cout << "Space Complexity Analysis:\n";

    for (size_t size : datasetSizes) {
        std::cout << "\nDataset size: " << size << "\n";

        // Generate random data
        std::vector<int> data = generateRandomELOData(size);

        // Measure Quick Sort space usage
        size_t quickSortBaseSize = sizeof(data) + (sizeof(int) * data.size());
        size_t quickSortStackUsage = sizeof(int) * std::ceil(std::log2(data.size()));
        std::cout << "Quick Sort total memory usage: "
            << (quickSortBaseSize + quickSortStackUsage) / 1024.0 << " KB\n";

        // Measure Merge Sort space usage
        size_t mergeSortBaseSize = sizeof(data) + (sizeof(int) * data.size());
        size_t mergeSortTemporarySize = sizeof(int) * data.size();
        std::cout << "Merge Sort total memory usage: "
            << (mergeSortBaseSize + mergeSortTemporarySize) / 1024.0 << " KB\n";
    }
}

int main() {
    try {
        std::cout << "Choose sorting method:\n"
            << "1. Quick Sort Performance\n"
            << "2. Merge Sort Performance\n"
            << "3. Scalability Analysis\n"
            << "4. Measure and Compare Space Complexity\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Running The Quick Sort\n";
            processAndMeasure("Quick Sort");
        }
        else if (choice == 2) {
            std::cout << "Running The Merge Sort\n";
            processAndMeasure("Merge Sort");
        }
        else if (choice == 3) {
            scalabilityAnalysis();
        }
        else if (choice == 4) {
            measureSpaceComplexity();
        }
        else {
            throw std::invalid_argument("Invalid choice!");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
