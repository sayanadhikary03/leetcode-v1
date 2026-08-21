class Solution {
public:
    // Function to reverse every word in the given string
    string reverseWords(string s) {
        int n = s.length(); // Length of string
        
        // List to store the words present in string
        vector<string> words;
        
        // Pointers to mark the start and end of a word
        int start, end;
        
        int i = 0;
        while(i < n) {
            
            // Finding the first character of a word (if any)
            while(i < n && s[i] == ' ') i++;
            
            // If no word is found, break 
            if(i >= n) break;
            
            start = i; // Storing the index of first character of word
            
            // Finding the last character of the word
            while(i < n && s[i] != ' ') i++;
            
            end = i-1; // Storing the index of last character of word
            
            // Add the found word to the list of words
            string wordFound = s.substr(start, end-start+1);
            words.push_back(wordFound);
        }
        
        string ans = "";
        
        // Adding all the words to result in the reverse order 
        for(int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            
            // Adding spaces in between words
            if(i != 0) ans.push_back(' ');
        }
        
        return ans; // Return the stored result
    } 
};