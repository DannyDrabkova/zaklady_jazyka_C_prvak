#include <stdio.h>
#include <string.h>



// Prints occurrences of txt[] in pattern[]
int knuth(char* string, char* pattern)
{
    if(string == NULL || pattern == NULL) {
        return -1;
    }
    int M = strlen(pattern);
    int N = strlen(string);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int o = 1;
    while (o < M) {
        if (pattern[o] == pattern[len]) {
            len++;
            lps[o] = len;
            o++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[o] = 0;
                o++;
            }
        }
    }

    int i = 0; // index for txt[]
    int j = 0; // index for pattern[]
    while (i < N) {
        if (pattern[j] == string[i]) {
            j++;
            i++;
        }

        if (j == M) {
           return i - j;
            j = lps[j - 1];
        }

            // mismatch after j matches
        else if (i < N && pattern[j] != string[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return -1;
}


// Driver program to test above function
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    knuth(txt, pat);
    return 0;
}