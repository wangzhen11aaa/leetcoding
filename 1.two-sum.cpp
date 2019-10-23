/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> vp_map;
    //     // Initialize map
    //     int index = 0;
    //     for (vector<int>::iterator num_iter = nums.begin(); num_iter != nums.end(); num_iter++, index++){
    //         vp_map[*num_iter] = index;
    //     }
    //     vector<int> result;
    //     index = 0;
    //     for (vector<int>::iterator num_iter = nums.begin(); num_iter != nums.end(); num_iter++, index++){
    //         if (vp_map.find(target - *num_iter) == vp_map.end()) continue;
    //         else{
    //             // Gurantee element not the same.
    //             if(index == (vp_map.find(target - *num_iter))->second) continue;
    //             else{
    //                 result.push_back(index);
    //                 result.push_back((vp_map.find(target - *num_iter))->second);
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }

    vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}

    
    // 1. (Binary search)Locate the position of some element, return normal index if found, else -1. Not right, for it is sorted.
    // int locate(vector<int> & nums, int start_index, int end_index, int target_element){
        
    // }
    // 2.Use Set

};

