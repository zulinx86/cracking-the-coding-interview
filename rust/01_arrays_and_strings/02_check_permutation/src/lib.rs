//! Problem: Given two strings, write a method to decide if one is a permutation of the other.

use std::collections::HashMap;

/// Sorts given strings and compares them from the beginning.
///
/// - Time complexity: O(N log N + M log M)
/// - Space complexity: O(N + M)
/// - where
///     - N: the length of `s1`
///     - M: the length of `s2`
pub fn check_permutation_1(s1: &str, s2: &str) -> bool {
    if s1.len() != s2.len() {
        return false;
    }

    let mut s1: Vec<_> = s1.chars().collect();
    let mut s2: Vec<_> = s2.chars().collect();
    s1.sort_unstable();
    s2.sort_unstable();

    for i in 0..s1.len() {
        if s1[i] != s2[i] {
            return false;
        }
    }

    true
}

/// Counts how many times the character appears by using array.
///
/// Only ASCII characters are acceptible. If non-ASCII characters are given, it panics with ``.
///
/// - Time complexity: O(N + M)
/// - Space complexity: O(1)
/// - where
///     - N: the length of `s1`
///     - M: the length of `s2`
pub fn check_permutation_2(s1: &str, s2: &str) -> bool {
    if s1.len() != s2.len() {
        return false;
    }

    let mut cnt = [0; 128];

    for c in s1.chars() {
        cnt[c as usize] += 1;
    }

    for c in s2.chars() {
        if cnt[c as usize] == 0 {
            return false;
        }

        cnt[c as usize] -= 1;
    }

    true
}

/// Counts how many times the character appears by using HashMap.
///
/// - Time complexity: O(N + M)
/// - Space complexity: O(1)
/// - where
///     - N: the length of `s1`
///     - M: the length of `s2`
pub fn check_permutation_3(s1: &str, s2: &str) -> bool {
    if s1.len() != s2.len() {
        return false;
    }

    let mut cnt = HashMap::<char, u8>::new();

    for c in s1.chars() {
        match cnt.get_mut(&c) {
            Some(v) => {
                *v += 1;
            }
            None => {
                cnt.insert(c, 1);
            }
        }
    }

    for c in s2.chars() {
        match cnt.get_mut(&c) {
            Some(v) => {
                if *v == 0 {
                    return false;
                }
                *v -= 1;
            }
            None => {
                return false;
            }
        }
    }

    true
}

#[cfg(test)]
mod tests {
    use super::*;

    struct Input {
        s1: &'static str,
        s2: &'static str,
    }

    struct TestCase {
        input: Input,
        output: bool,
    }

    fn gen_test_cases() -> [TestCase; 3] {
        return [
            TestCase {
                input: Input {
                    s1: "hello",
                    s2: "lohel",
                },
                output: true,
            },
            TestCase {
                input: Input {
                    s1: "hello",
                    s2: "loheo",
                },
                output: false,
            },
            TestCase {
                input: Input {
                    s1: "hello world",
                    s2: "dlo orehlwl",
                },
                output: true,
            },
        ];
    }

    #[test]
    fn test_check_permutation_1() {
        let test_cases = gen_test_cases();

        for c in test_cases {
            assert_eq!(check_permutation_1(c.input.s1, c.input.s2), c.output);
        }
    }

    #[test]
    fn test_check_permutation_2() {
        let test_cases = gen_test_cases();

        for c in test_cases {
            assert_eq!(check_permutation_2(c.input.s1, c.input.s2), c.output);
        }
    }

    #[test]
    fn test_check_permutation_3() {
        let test_cases = gen_test_cases();

        for c in test_cases {
            assert_eq!(check_permutation_3(c.input.s1, c.input.s2), c.output);
        }
    }
}
