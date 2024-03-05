
#include <string>
#include <iostream>
#include <vector>

// Problem: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
std::string IsPalindrome(std::string inputString)
{
    std::cout << "String to check: " << inputString << ". Length of string: "
              << inputString.length() << std::endl;
    int left = 0;
    int right = inputString.length() - 1;
    int i = 1;
    while (left < right) // The terminating condition for the loop is when both the pointers reach the same element or when they cross each other.
    {
        std::cout << "In iteration " << i
                  << ", left = " << left << ", right = " << right << std::endl;
        std::cout << "The current element being pointed to by the left pointer is \'"
                  << inputString[left] << "\'" << std::endl;
        std::cout << "The current element being pointed to by the right pointer is \'"
                  << inputString[right] << "\'" << std::endl;
        left++; // Heading towards the right
        right--; // Heading towards the left
        i++;
        std::cout << std::string(100, '-') << std::endl;
    }
    std::cout << "Loop terminated with left = " << left << ", right = " << right << std::endl;
    std::cout << "The pointers have either reached the same index, or have crossed each other, hence we don't need to look further." << std::endl;
    return "";
}

int main()
{
    std::vector<std::string> inputStrings = {"RACECAR", "ABBA", "TART"};
    for (int i = 0; i < inputStrings.size(); i++)
    {
        std::cout << "Test Case # " << i+1 << std::endl;
        IsPalindrome(inputStrings[i]);
        std::cout << std::string(100, '-') << std::endl << std::endl;
    }
}