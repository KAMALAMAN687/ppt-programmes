#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findErrorNums(std::vector<int> &nums)
{
    std::unordered_set<int> numSet;
    int duplicate = -1;
    int missing = -1;

    for (int num : nums)
    {
        // If the current number is already in the set, it's the duplicate
        if (numSet.count(num) > 0)
        {
            duplicate = num;
        }

        // Add the number to the set
        numSet.insert(num);
    }

    // Find the missing number by calculating the sum of 1 to n and subtracting the sum of nums
    int n = nums.size();
    int totalSum = (n * (n + 1)) / 2;
    int actualSum = 0;
    for (int num : nums)
    {
        actualSum += num;
    }
    missing = totalSum - (actualSum - duplicate);

    return {duplicate, missing};
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 4};

    std::vector<int> result = findErrorNums(nums);

    std::cout << "Duplicate: " << result[0] << std::endl;
    std::cout << "Missing: " << result[1] << std::endl;

    return 0;
}
