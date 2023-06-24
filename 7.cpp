#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums)
{
    int n = nums.size();
    int left = 0; // Pointer for non-zero elements

    // Move all non-zero elements to the front
    for (int num : nums)
    {
        if (num != 0)
        {
            nums[left] = num;
            left++;
        }
    }

    // Fill the remaining elements with zeros
    for (int i = left; i < n; i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    std::vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    std::cout << "Modified Array: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
