/*
LeetCode] Longest Substring Without Repeating Characters 解题报告
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

     int lengthOfLongestSubstring(string s) {  
          int count[26];  
          memset(count, -1, 26*sizeof(int));  
          int len=0, maxL = 0;  
          for(int i =0; i< s.size(); i++,len++)  
          {  
               if(count[s[i]-'a']>=0)  
               {  
                    maxL = max(len, maxL);  
                     len =0;          
                     i = count[s[i]-'a']+1;  
                     memset(count, -1, 26*sizeof(int));   
                }  
                count[s[i]-'a']=i;  
           }      
           return max(len, maxL);  
      }
*/
