unsigned int _strspn(char* s, char* accept) {
    unsigned int length = 0;  // Initialize the length counter

    while (*s != '\0' && strchr(accept, *s) != NULL) {
        length++;  // Increment the length counter
        s++;  // Move to the next character in the string
    }

    return length;  // Return the number of bytes in the initial segment of s
}
