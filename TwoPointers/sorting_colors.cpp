#include <iostream>
#include <vector>

std::vector<int> SortColors(std::vector<int>& colors) {

    // Initialize the red, white, and blue pointers
    int red = 0;
    int white = 0;
    int blue = colors.size() - 1;

    while (white <= blue) {

        // If the white pointer is pointing to red
        if (colors[white] == 0) {

            // Swap the values if the red pointer is not pointing to red
            if (colors[red] != 0) {
                std::swap(colors[red], colors[white]);
            }

            // Increment both the red and white pointers
            white++;
            red++;
        }

        // If the white pointer is pointing to white, no swapping is required
        // Just increment the white pointer
        else if (colors[white] == 1) {
            white++;
        }

        // If the white pointer is pointing to blue
        else {

            // Swap the values if the blue pointer is not pointing to blue
            if (colors[blue] != 2) {
                std::swap(colors[white], colors[blue]);
            }

            // Decrement the blue pointer
            blue--;
        }
    }

    return colors;
}

// Iterate over the inputs and print the sorted array for each
std::string VectorToString(const std::vector<int>& vec) {
    std::string result = "";
    for (int i = 0; i < vec.size(); i++) {
        result += std::to_string(vec[i]);
        if (i != vec.size() - 1) {
            result += ", ";
        }
    }
    return result;
}

// Driver code
int main() {
    std::vector<std::vector<int>> inputs = {
        {0, 1, 0},
        {1, 1, 0, 2},
        {2, 1, 1, 0, 0},
        {2, 2, 2, 0, 1, 0},
        {2, 1, 1, 0, 1, 0, 2}
    };

    for (int i = 0; i < inputs.size(); i++) {
        std::cout << i + 1 << ".\tcolors: " << VectorToString(inputs[i]);
        std::cout << "\n\n\tThe sorted array is: " << VectorToString(SortColors(inputs[i]));
        std::cout << "\n" << std::string(100, '-') << std::endl;
    }

    return 0;
}