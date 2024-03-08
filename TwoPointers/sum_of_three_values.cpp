#include <iostream>
#include <vector>
#include <algorithm>


#define _GLIBCXX_USE_CXX11_ABI 0

bool FindSumOfThree(std::vector<int> &nums, int target)
{
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i<nums.size(); i++)
    {
        int left = i+1;
        int right = nums.size()-1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == target)
            {
                return true;
            }
            else if(sum < target)
            {
                ++left;
            }
            else{
                --right;
            }
        }
    }
    return false;
}

std::string Print(const std::vector<int>& nums)
{
    std::string result = "[";
    for (int i = 0; i < nums.size(); i++)
    {
        result += std::to_string(nums[i]);
        if (i != nums.size() - 1)
            result += ", ";
    }
    result += "]";
    return result;
}

// Driver code
int main()
{
    std::vector<std::vector<int>> numsLists = {
        {3, 7, 1, 2, 8, 4, 5},
        {-1, 2, 1, -4, 5, -3},
        {2, 3, 4, 1, 7, 9},
        {1, -1, 0},
        {2, 4, 2, 7, 6, 3, 1}};

    

    std::vector<int> testList = {10, 7, 20, -1, 8};
    for (int i = 0; i < numsLists.size(); i++)
    {
        std::cout << (i + 1) << ".\tInput array: " << Print(numsLists[i]) << std::endl;

        if (FindSumOfThree(numsLists[i], testList[i]))
            std::cout << " \tSum for " << testList[i] << " exists" << std::endl;
        else
            std::cout << " \tSum for " << testList[i] << " does not exist" << std::endl;

        std::cout << std::string(100, '-') << std::endl;
    }
    return 0;
}
