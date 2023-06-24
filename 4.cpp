#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int> &digits)
{
    int n = digits.size();
    int carry = 1; // Initialize carry to 1 since we want to increment the number

    for (int i = n - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0)
        {
            // No more carry, early return
            return digits;
        }
    }

    // If there is still a carry after the loop, insert it at the beginning
    if (carry != 0)
    {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main()
{
    std::vector<int> digits = {1, 2, 9};

    std::vector<int> result = plusOne(digits);

    std::cout << "Result: ";
    for (int digit : result)
    {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}
