/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.91%)
 * Likes:    1313
 * Dislikes: 449
 * Total Accepted:    273.9K
 * Total Submissions: 915.2K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
// class Solution {
// public:
//     int countPrimes(int n){
//         vector<int> prime_vector{2};
//         if (n <=2 ) return 0;
//         bool is_prime;
//         int j;
//         for(int i = 3; i < n; i++){
//             is_prime = true;
//             for(j = 0; j < prime_vector.size() && prime_vector[j] * prime_vector[j] <= i; j++){
//                 if(i % prime_vector[j] == 0){is_prime = false;break;}
//             }
//             if(is_prime) prime_vector.push_back(i);
//         }
//         return prime_vector.size();
//     }
// };
class Solution {
public:
    int countPrimes(int n) {
        if (n == 2) return 0;
        bool sieve[n+1];
        memset(sieve, true, n+1);
        for(int i = 2; i*i < n; i++){
            if(sieve[i]){
                for(int j = i*i; j < n; j+= i){
                    sieve[j] = false;
                }
            }
        }
        int counter = 0;
        for(int i = 2; i < n; i++){
            if(sieve[i]){counter++;}
        }
        return counter;
    }
};
// @lc code=end

