class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        vowels = set('aeiou')
        n = len(word)
        count = 0
        
        for start in range(n):
            vowel_count = {v: 0 for v in vowels}  # Dictionary to count each vowel
            consonant_count = 0
            unique_vowels = 0  # To track how many unique vowels we've seen
            
            for end in range(start, n):
                char = word[end]
                
                if char in vowels:
                    if vowel_count[char] == 0:
                        unique_vowels += 1  # New unique vowel encountered
                    vowel_count[char] += 1
                else:
                    consonant_count += 1  # It's a consonant
                    
                # If we have all vowels and exactly k consonants, increment the count
                if unique_vowels == 5:
                    if consonant_count == k:
                        count += 1
                    # Stop expanding if consonants exceed k
                    elif consonant_count > k:
                        break

        return count