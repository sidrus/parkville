#ifndef STRING_H
#define STRING_H

static unsigned int strlen(const char* string) {
    unsigned int len = 0;
    while(*string++) {
        len++;
    }
    return len;
};

static char* strrev(const char* original) {
    char* reversed;
    int rev_pos = 0;
    int orig_pos = strlen(original) - 1;

    while(orig_pos > -1) {
        reversed[rev_pos++] = original[orig_pos--];
    }

    // null-terminate the new string
    reversed[rev_pos] = '\0';

    return reversed;
};

static char* uint_to_str(const unsigned long original_value) {
    char* string;

    long position = 0;
    unsigned long current_value = original_value;
    while(current_value > 1) {
        char ascii_char = (current_value % 10) + '0';
        string[position] = ascii_char;

        current_value /= 10;
        position++;
    }

    // null-terminate the string
    string[position] = '\0';

    // values are written to the new array in reverse order.  If there is more
    // than one value, we need to reverse the character array.
    if(strlen(string) > 1) {
        string = strrev(string);
    }

    return string;
};

#endif
