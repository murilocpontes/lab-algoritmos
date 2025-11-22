#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

long long getCrossingSum(const std::vector<int>& vec, int start, int mid, int end){
	long long leftSum = std::numeric_limits<long long>::min();
    long long currentSum = 0;
    for(int i = mid; i >= start; i--){
        currentSum += vec[i];
        if (currentSum > leftSum) {
            leftSum = currentSum;	
        }
    }

	long long rightSum = std::numeric_limits<long long>::min();
    currentSum = 0;
    for(int i = mid + 1; i <= end; i++){
        currentSum += vec[i];
        if (currentSum > rightSum) {
            rightSum = currentSum;
        }
    }
	return std::max({leftSum, rightSum, leftSum + rightSum});
}

long long greaterSubVector(std::vector<int>& vec, int start, int end){
	if(start == end){
		return vec[start];
	}

	int mid = start + (end - start)/2;

	long long maxLeftSum = greaterSubVector(vec, start, mid);
	long long maxRightSum = greaterSubVector(vec, mid + 1, end);
	long long maxCrossingSum = getCrossingSum(vec, start, mid, end);

	return (std::max({maxLeftSum, maxCrossingSum, maxRightSum}));
}

int main(){
	int n;
	std::vector<int> vec;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		vec.push_back(a);
	}
	
	std::cout << greaterSubVector(vec, 0, n-1) << std::endl;

	return 0;
}