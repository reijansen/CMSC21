#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// scans a word and update the array
void scan_word(int* occurrences) {
    char c;
    while ((c = getchar()) != '\n') {
        // checks if a character is an alphabet
        if (isalpha(c)) {
            (*(occurrences + (toupper(c) - 'A')))++;
        }
    }
}

// checks if two words are anagrams
bool is_anagram(int* occurrences1, int* occurrences2) {
    for (int i = 0; i < 26; i++) {
        // checks if the occurences of the letters differs
        if (*(occurrences1 + i) != *(occurrences2 + i)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // arrays that store the count of each letters
    int occurrences1[26] = {0};
    int occurrences2[26] = {0};

    printf("Enter first word: ");
    scan_word(occurrences1);

    printf("Enter second word: ");
    scan_word(occurrences2);

    // checks if the words are anagrams
    bool anagram = is_anagram(occurrences1, occurrences2);

    if (anagram) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}
