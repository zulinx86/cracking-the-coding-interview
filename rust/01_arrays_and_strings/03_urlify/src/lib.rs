/// Converts " " to "%20" backward.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
/// - where N is the length of the given string
pub fn urlify(s: &mut String, last: usize) {
    let mut p = s.len();

    unsafe {
        let v = s.as_mut_vec();

        for i in (0..last).rev() {
            if v[i] == b' ' {
                p -= 3;
                v[p] = b'%';
                v[p + 1] = b'2';
                v[p + 2] = b'0';
            } else {
                p -= 1;
                v[p] = v[i];
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    struct Input {
        s: String,
        last: usize,
    }

    struct TestCase {
        input: Input,
        output: String,
    }

    fn gen_test_cases() -> [TestCase; 2] {
        [
            TestCase {
                input: Input {
                    s: String::from("Mr John Smith    "),
                    last: 13,
                },
                output: String::from("Mr%20John%20Smith"),
            },
            TestCase {
                input: Input {
                    s: String::from("Cracking the Coding Interview      "),
                    last: 29,
                },
                output: String::from("Cracking%20the%20Coding%20Interview"),
            },
        ]
    }

    #[test]
    fn test_urlify() {
        for mut c in gen_test_cases() {
            urlify(&mut c.input.s, c.input.last);
            assert_eq!(c.input.s, c.output);
        }
    }
}
