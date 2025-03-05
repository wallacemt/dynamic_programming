char* longestPalindrome(char* s) {
    int start = 0, maxLen = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        for(int j = 0; j <= 1; j++) {
            int left = i, right = i + j;
            while(left >= 0 && right < len && s[left] == s[right]) {
                left--; right++;
            }
            int currLen = right - left - 1;
            if(currLen > maxLen) {
                start = left + 1;
                maxLen = currLen;
            }
        }
    }
    return strndup(s + start, maxLen);
}

