//! Check if characters in a given string slice are unique.

use std::collections::HashSet;

/// Brute force algorithm.
///
/// - Time complexity: O(N^2)
/// - Space complexity: O(1)
pub fn is_unique_1(s: &str) -> bool {
    let n = s.len();
    let s = s.as_bytes();

    for i in 0..n {
        for j in i + 1..n {
            if s[i] == s[j] {
                return false;
            }
        }
    }

    true
}

/// Uses an array which checks if the character has already appeared.
///
/// Only ASCII characters are acceptible. If it takes non-ASCII characters, it will panic with
/// `index out of bounds`.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
pub fn is_unique_2(s: &str) -> bool {
    let mut cnt: [bool; 128] = [false; 128];

    for c in s.chars() {
        if cnt[c as usize] {
            return false;
        }

        cnt[c as usize] = true;
    }

    true
}

/// Uses a bit checker (`u128`) where each bit means whether a character has already appeared.
///
/// Only ASCII characters are acceptible. If it takes non-ASCII characters, it may output incorrect
/// answer.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
pub fn is_unique_3(s: &str) -> bool {
    let mut bit_for_check: u128 = 0;
    for c in s.chars() {
        if (bit_for_check & (1u128 << (c as u8))) != 0 {
            return false;
        }

        bit_for_check |= 1u128 << (c as u8);
    }

    true
}

/// Uses a hash set which has characters previously appeared.
///
/// - Time complexity: O(N)
/// - Space complexity: O(N)
pub fn is_unique_4(s: &str) -> bool {
    let mut set = HashSet::new();

    for c in s.chars() {
        if set.contains(&c) {
            return false;
        }
        
        set.insert(c);
    }

    true
}

#[cfg(test)]
mod tests {
    use super::*;

    fn gen_test_cases() -> [(&'static str, bool); 3] {
        return [
            ("hello", false), /* becuase 'l' is duplicate */
            ("world", true),
            ("a b c", false), /* because ' ' is duplicate */
        ];
    }

    #[test]
    fn test_is_unique_1() {
        let test_cases = gen_test_cases();

        for case in test_cases {
            assert_eq!(is_unique_1(case.0), case.1);
        }
    }

    #[test]
    fn test_is_unique_2() {
        let test_cases = gen_test_cases();

        for case in test_cases {
            assert_eq!(is_unique_2(case.0), case.1);
        }
    }

    #[test]
    fn test_is_unique_3() {
        let test_cases = gen_test_cases();

        for case in test_cases {
            assert_eq!(is_unique_3(case.0), case.1);
        }
    }

    #[test]
    fn test_is_unique_4() {
        let test_cases = gen_test_cases();

        for case in test_cases {
            assert_eq!(is_unique_4(case.0), case.1);
        }
    }
}
