##Longest Substring Without Repeating Characters
2015-08-07 09:46:58

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

>Tags: `Hash Table` `Two Pointers` `String`

###题目分析
找到一个字符串里没有重复字符的最长子串。

###我的解决方法
有两个指针分别记录最长子串的开头和结尾，使用哈希表记录一个字符是否在子串中出现。

然后遍历字符串，如果后一个字符在哈希表里边没有出现，那结尾的指针就往后移动，如果出现了，记录下当前无重复字符子串的长度，并使用循环把开头的指针往后移，直到不出现重复的字符。

~~~c++
int lengthOfLongestSubstring(string s) {
    bool hash[128] = {false};
    int begin = 0, end = 0, max_len = 0;
    for (int i = 0; i < s.length(); i++) {
        if (hash[s[i]]) {
            max_len = max_len > (end - begin) ? max_len : (end - begin);
            while(hash[s[i]]) {
                hash[s[begin++]] = false;
            }
        }
        end++;
        hash[s[i]] = true;
    }
    return max_len > (end - begin) ? max_len : (end - begin);;
}
~~~

###更好地解决方法

使用动态规划的解决方法：

~~~c++
/**
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 */
 
int lengthOfLongestSubstring(string s) {
    // for ASCII char sequence, use this as a hashmap
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }

    return longest;
}
~~~
