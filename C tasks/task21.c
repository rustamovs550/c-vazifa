#include <stdio.h>
#include <ctype.h>

void countCharacters(const char* str) {
    int count[256] = {0}; // Initializing counter array with 0
    
    // Counting occurrences of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)tolower(str[i]);
        count[ch]++;
    }
    
    // Displaying character count information in alphanumeric order
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0 && isalnum(i)) {
            printf("%c: %d\n", (char)i, count[i]);
        }
    }
}

int main() {
    const char* text = "Google Inc. has used this technique to improve the completion of its Search Engine.";
    countCharacters(text);
    
    return 0;
}