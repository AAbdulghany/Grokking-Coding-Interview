#include <iostream>
#include <regex>
#include <string>

// A function that reverses characters from startRev to endRev in place
void StrRev(std::string &str, int startRev, int endRev) {
    while (startRev < endRev) {
        std::swap(str[startRev], str[endRev]);
        startRev++;
        endRev--;
    }
}

std::string ReverseWords(std::string sentence) {

    int strLen = sentence.length();

    StrRev(sentence, 0, strLen-1);

    for (int start = 0, end = 0; end <= strLen; ++end) {
        if ((sentence[end] == '\0') ||sentence[end] == ' ') {
            StrRev(sentence, start, end - 1);
            start = end + 1;
        }
    }

    return sentence;
}

int main(){
    std::string str = "we love cpp";

    str = ReverseWords(str);

    std::cout<<str;
}