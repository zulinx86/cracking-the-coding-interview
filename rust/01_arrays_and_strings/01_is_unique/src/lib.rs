use std::collections::HashSet;

/// Brute force algorithm.
///
/// - Time complexity: O(N^2)
/// - Space complexity: O(1)
/// - where N is the length of the given string
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
/// - where N is the length of the given string
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
/// - where N is the length of the given string
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
/// - where N is the length of the given string
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

/// Sorts a given string and compares adjacent characters.
///
/// - Time complexity: O(N log N)
/// - Space complexity: O(N)
/// - where N is the length of the given string
pub fn is_unique_5(s: &str) -> bool {
    let mut s: Vec<_> = s.chars().collect();
    s.sort();

    for i in 0..s.len() - 1 {
        if s[i] == s[i + 1] {
            return false;
        }
    }

    true
}

#[cfg(test)]
mod tests {
    use super::*;

    struct TestCase {
        input: &'static str,
        output: bool,
    }

    fn gen_test_cases() -> [TestCase; 3] {
        [
            TestCase { input: "hello", output: false }, /* becuase 'l' is duplicate */
            TestCase { input: "world", output: true },
            TestCase { input: "a b c", output: false }, /* because ' ' is duplicate */
        ]
    }

    fn test_is_unique(f: fn(&str) -> bool) {
        for c in gen_test_cases() {
            assert_eq!(f(c.input), c.output);
        }
    }

    #[test]
    fn test_is_unique_1() {
        test_is_unique(is_unique_1);
    }

    #[test]
    fn test_is_unique_2() {
        test_is_unique(is_unique_2);
    }

    #[test]
    fn test_is_unique_3() {
        test_is_unique(is_unique_3);
    }

    #[test]
    fn test_is_unique_4() {
        test_is_unique(is_unique_4);
    }

    #[test]
    fn test_is_unique_5() {
        test_is_unique(is_unique_5);
    }
}
