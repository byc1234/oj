/*
(Leetcode) Longest Substring with At Most K Distinct Characters | Changhaz's Codeplay

public class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s == null || s.length() == 0 || k <= 0) {
            return 0;
        }
        int start = 0;
        int res = 1;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        map.put(s.charAt(0), 1);
        for (int end = 1; end < s.length(); end++) {
            char ch = s.charAt(end);
            if (map.containsKey(ch)) {
                map.put(ch, map.get(ch)+1);
            } else {
                if (map.size() == k) {
                    res = Math.max(res, end - start);
                    //full map, need to remove the first character in ths substring
                    for (int index = start; index < end; index++) {
                        map.put(s.charAt(index), map.get(s.charAt(index))-1);
                        start++;
                        if (map.get(s.charAt(index)) == 0) {
                            //have removed all occurance of a char
                            map.remove(s.charAt(index));
                            break;
                        }
                    }
                }
                map.put(ch, 1);
            }
        }
        res = Math.max(res, s.length() - start);
        return res;
    }
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstringKDistict(string s, int k) {
  int ht[256];
  fill_n(ht, 256, 0);
  int start = 0;
  int maxL = 0;
  int uChCnt = 0;
  for (int i = 0, len = 0; i < s.length(); i++, len++) {
     char ch = s[i];
     if (ht[ch]) {
       ht[ch]++;
     } else {
// When we met a unique character, we check if we had a total unique chars.
       if (uChCnt == k) {
cout << "i: " << i <<  ", " << i - start << endl;
          maxL = max(maxL, i - start);
          for (int j = start; j < i; j++) {
             ht[s[j]]--;
             start++;
             if (ht[s[j]] == 0) {
               uChCnt--;
               break;
             }
          }
       }
       uChCnt++; 
       ht[ch]++;
     }
  }
cout << "last: " << (int)s.length() - start << endl;
  maxL = max(maxL, (int)s.length() - start);
  return maxL;
}

int main() {
   cout << lengthOfLongestSubstringKDistict("eceba", 3) << endl;
}
