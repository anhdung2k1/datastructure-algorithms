Given an array of strings strs, group the anagrams together. You can return the answer in any order.<br/>

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.<br/>
 

Example 1:<br/>
```
  Input: strs = ["eat","tea","tan","ate","nat","bat"]
  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```
Example 2:<br/>
```
  Input: strs = [""]<
  Output: [[""]]
```
Example 3:<br/>
```
  Input: strs = ["a"]
  Output: [["a"]]
```

Constraints:<br/>
```
    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.
```