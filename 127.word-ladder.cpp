/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (25.35%)
 * Likes:    1839
 * Dislikes: 901
 * Total Accepted:    300.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * // The distance(hit, hot) = 1, distance(hit, dot) = 2, started from hit.
 * // The distance(hit, dog) = 3, distance(hit, cog) = 3, Plateau.
 * // The distance(dot, dog) = 1, distance(dot, cog) = 2, started from dot.
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    // Function to compare the string's difference distance.

    int distance(string &begin, string &end, int length){
        int difference = 0;
        for(int i = 0; i < length; i++){
            if(begin[i] != end[i]) difference++;
            continue;
        }
        //cout << "Difference of begin and word" << difference << endl;
        return difference;
    }

    bool vectorContainTarget(string &endWord, vector<string>& wordList){
        for(auto _word: wordList){
            if(_word == endWord) return true;
        }
        return false;
    }

    // BFS and dynamic search.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size()==0) return 0;
        else{
            // If the word is not the wordList, then return 0;
            // Trim-Tree.
            if(!vectorContainTarget(endWord, wordList)) return 0;
            else{
                int ret = _ladderOneStep(beginWord, endWord, wordList);
                return ret;   
            }
            
        }
    }
    
    /*  Select the arg y: distance(x,y) = 1 started from x, then put y in a bfs vector.
        Add these word into the set for removing duplicated computations.
        For each distance, we only compute x who makes distance(x, y) equals 1, until we found the 
        target word or nothing left. 
        */
    // not recursive algorithm. BFS
    int _ladderOneStep(string currentBeginWord, string endWord, vector<string>& wordList){
        //int wordsListLength = wordList.size();
        // Store the 
        //set<int> indexToRemove;
        set<string> wordsSet(wordList.begin(), wordList.end());
        vector<string> wordQueue;
        bool leap_failed = true;
        int length = 1;
        wordQueue.push_back(currentBeginWord);
        int wordLength = currentBeginWord.size();
        //BFS pop out the first and insert the proper item into the end the vector.
        while (wordQueue.size() != 0)
        {
            wordList.clear();
            // Use wordsSet to initialize the wordList. Update the wordList.
            wordList.insert(wordList.begin(),wordsSet.begin(), wordsSet.end());
            // string tmpWrod = wordQueue.pop()
            // First enqueue the queue, then erase the first item.
            // For each level for the bfs search.
            int currentQueueSize = wordQueue.size();
            length+=1;
            for (int i = 0; i < currentQueueSize; i++)
            {
                string tmpWord = wordQueue[i];
                int wordListLength = wordList.size();
                for (int i = 0; i < wordListLength; i++)
                {
                    
                    if (distance(tmpWord, wordList[i], wordLength) == 1)
                    {
                        //std::cout << tmpWord << wordList[i] << std::endl;
                        leap_failed = false;
                        if (wordList[i] == endWord){
                            return length;
                        }
                        else
                        {
                            if (wordsSet.find(wordList[i]) != wordsSet.end())
                            {
                                wordQueue.push_back(wordList[i]);
                                wordsSet.erase(wordList[i]);
                            }
                        }
                    }
                }
            }
            if (leap_failed)
                    return 0;
                wordQueue.erase(wordQueue.begin(), wordQueue.begin()+currentQueueSize);
                leap_failed = true;
        }
        return length+1;
    }
};
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         queue<string> todo;
//         todo.push(beginWord);
//         int ladder = 1;
//         while (!todo.empty()) {
//             int n = todo.size();
//             for (int i = 0; i < n; i++) {
//                 string word = todo.front();
//                 todo.pop();
//                 if (word == endWord) {
//                     return ladder;
//                 }
//                 dict.erase(word);
//                 // For each char in word ,we want to find every mutation.
//                 for (int j = 0; j < word.size(); j++) {
//                     char c = word[j];
//                     for (int k = 0; k < 26; k++) {
//                         word[j] = 'a' + k;
//                         if (dict.find(word) != dict.end()) {
//                             todo.push(word);
//                         }
//                      }
//                      // restore the position of this word.
//                     word[j] = c;
//                 }
//             }
//             ladder++;
//         }
//         return 0;
//     }
// };

