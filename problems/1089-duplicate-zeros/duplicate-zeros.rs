/*

Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

*/

use std::collections::VecDeque;

impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let mut queue: VecDeque<i32> = VecDeque::new();
        for num in arr.iter_mut() {
            queue.push_back(*num);
            if *num == 0 {
                queue.push_back(0);
            }
            *num = queue.pop_front().expect("error! oh no!");
        }
    }
}
