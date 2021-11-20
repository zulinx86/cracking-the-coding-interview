//! Problem: Given a string, write a function to check if it is a permutation of a palindrome. A
//! palindrome is a word or phrase that is the same forwards and backwards. A permutation is a
//! rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

use std::collections::HashMap;

/// Checks if the number of characters that appear an odd number of times is one or less by using
/// array.
///
/// Non-alphabetic characters are ignored.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
/// - where N is the length of the given string
pub fn palindrome_permutation_1(s: &str) -> bool {
    let mut cnt: [bool; 26] = [false; 26];
    for c in s.chars() {
        if c.is_ascii_alphabetic() {
            let i = c.to_ascii_lowercase() as usize - 97;
            cnt[i] = !cnt[i];
        }
    }

    let mut res = 0;
    for odd in cnt {
        if odd {
            res += 1;
        }
    }
    res <= 1
}

/// Checks if the number characters that appear that an odd number of times is one or less by
/// HashMap.
///
/// Non-alphanetic characters are ignored.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
/// - where N is the length of the given string
pub fn palindrome_permutation_2(s: &str) -> bool {
    let mut cnt = HashMap::<char, bool>::new();
    for c in s.chars() {
        if c.is_ascii_alphabetic() {
            let c = c.to_ascii_lowercase();
            match cnt.get_mut(&c) {
                Some(n) => { *n = !*n; }
                None => { cnt.insert(c, true); }
            }
        }
    }

    let mut res = 0;
    for (_, odd) in cnt {
        if odd {
            res += 1;
        }
    }
    res <= 1
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
            TestCase { input: "Tact Coa", output: true },
            TestCase { input: "aATctCo", output: true },
            TestCase { input: "aBtctDo", output: false},
        ]
    }

    fn test_palindrome_permutation(f: fn(&str) -> bool) {
        for c in gen_test_cases() {
            assert_eq!(f(c.input), c.output);
        }
    }

    #[test]
    fn test_palindrome_permutation_1() {
        test_palindrome_permutation(palindrome_permutation_1);
    }

    #[test]
    fn test_palindrome_permutation_2() {
        test_palindrome_permutation(palindrome_permutation_2);
    }
}
