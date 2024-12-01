# Final-project-a-simple-but-effective-approach-to-getting-a-good-grade
Summary
This program provides performance and space complexity analysis for Quick Sort and Merge Sort algorithms. 
Users can test the algorithms on different dataset sizes, analyze scalability, and visualize performance on various input types (e.g., random, sorted, and reversed datasets). Results can also be saved to a CSV file for further analysis.

Features
Quick Sort: This sorts a dataset using a Quick Sort algorithm and will display an execution time.
Merge Sort: This sorts a dataset using a Merge Sort algorithm and will display an execution time.
Scalability Analysis: This measures the execution time of both algorithms across increasing dataset sizes.
Measure and Compare Space Complexity: This calculates the memory usage of both algorithms for different dataset sizes.
Analyze and Visualize Performance On Different Input Types: This evaluates the sorting performance of random, sorted, and reversed datasets up to 1,000,000 elements.
Save Quick Sort and Merge Sort Results to CSV: This saves the sorted results and execution metrics into a CSV file.

Used Libraries
<iostream>, <fstream>, <sstream>, <vector>, <string>, <chrono>, <random>, <cmath>, <algorithm>

Setup Instructions
1.Download the source code to your machine by cloning the repository or downloading the .zip file.
2. Random ELO data will generate using std::vector<int> generateRandomELOData(size_t size); to simulate a certain amount of chess games played.

Running The Program
Enter the number corresponding to the option you'd like to execute
1. Quick Sort: Parses and sorts data using Quick Sort, displaying the time taken.
2. Merge Sort: Parses and sorts data using Merge Sort, displaying the time taken.
3. Scalability Analysis: Compares performance of both algorithms on datasets of sizes 100, 1,000, 10,000, and 100,000.
4. Measure and Compare Space Complexity: Displays memory usage of Quick Sort and Merge Sort for different dataset sizes.
5. Analyze and Visualize Performance on Different Input Types: Measures sorting performance on random, sorted, and reversed datasets.
6. Save Results to CSV: Outputs sorted results and metrics to a CSV file
