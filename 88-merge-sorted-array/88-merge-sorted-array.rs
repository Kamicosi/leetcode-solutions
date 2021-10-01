/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

*/

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut result: Vec<i32> = Vec::new();
        let mut j: i32 = 0;
        let mut k: i32 = 0;
        loop {
            match (nums1.get(j as usize), nums2.get(k as usize)) {
                (Some(num1), Some(num2)) => {
                    if j < m && *num1 < *num2 {
                        result.push(*num1);
                        j += 1;
                    } else if k < n {
                        result.push(*num2);
                        k += 1;
                    } else {
                        break;
                    }
                },
                (Some(num), None) => {
                    if j < m {
                        result.push(*num);
                        j += 1;
                    } else {
                        break;
                    }
                },
                (None, Some(num)) => {
                    if k < n {
                        result.push(*num);
                        k += 1;
                    } else {
                        break;
                    }
                },
                (None, None) => {
                    break;
                }
            }
        }
        *nums1 = result;
    }
}
