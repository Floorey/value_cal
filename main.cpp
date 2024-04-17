#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>


float calculateMedian(const std::vector<float>& values) {
    std::vector<float> sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end());
    size_t size = sortedValues.size();
    if (size % 2 == 0) {
        return (sortedValues[size / 2 - 1] + sortedValues[size / 2]) / 2.0f;
    } else {
        return sortedValues[size / 2];
    }
}
float calculateMean(const std::vector<float>& values) {
    return std::accumulate(values.begin(), values.end(), 0.0f) / values.size();
}
float calculateTwoStandardDevision(const std::vector<float>& values) {
    float maen = calculateMean(values);
    float sumSquareDiff = 0.0f;
    for (float val : values) {
        float diff = val - maen;
        sumSquareDiff += diff * diff;
    }
    float variance = sumSquareDiff / values.size();
    return 2.0f * std::sqrt(variance);
}


int main() {
    // init. random generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.001f, 1.000f);

    // vector for the random numbers
    std::vector<float> values;


    // count od numbers
    int count = 10;

    // generate and add to the vector
    for (int i = 0; i < count; ++i) {
        float g = dis(gen);
        values.push_back(g);
    }
    std::cout << " random values:" << std::endl;
    for (float h : values) {
        std::cout << h << std::endl;
    }
    float median = calculateMedian(values);
    std::cout << "Median:" << median << std::endl;

    float mean = calculateMean(values);
    std::cout << "Mean value:" << mean << std::endl;

    float twoStdDev = calculateTwoStandardDevision(values);
    std::cout << "2SD:" << twoStdDev << std::endl;

    return 0;
}
