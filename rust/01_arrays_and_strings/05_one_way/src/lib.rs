/// Checks whether the given two str are one edit (or zero edit) away.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
/// - where N is the length of the given strings
pub fn one_away(s1: &str, s2: &str) -> bool {
    // check if replace a character
    if s1.len() == s2.len() {
        let mut cnt = 0;
        for (c1, c2) in s1.chars().zip(s2.chars()) {
            if c1 != c2 {
                cnt += 1;
            }
        }

        if cnt <= 1 {
            return true;
        }
    }

    // `s1` is long one and `s2` is short one.
    let (s1, s2) = if s1.len() > s2.len() {
        (s1, s2)
    } else {
        (s2, s1)
    };

    // check if insert / remove a character
    if s1.len() - s2.len() == 1 {
        let (mut long, mut short) = (s1.chars(), s2.chars());
        let mut diff = false;
        loop {
            let (mut c1, c2) = (long.next(), short.next());
            if c1 == None || c2 == None {
                break;
            }

            while c1 != c2 {
                if diff {
                    return false;
                }

                diff = true;
                c1 = long.next();
            }
        }

        return true;
    }

    false
}

#[cfg(test)]
mod tests {
    use super::*;

    #[derive(Debug)]
    struct Input {
        s1: &'static str,
        s2: &'static str,
    }

    #[derive(Debug)]
    struct TestCase {
        input: Input,
        output: bool,
    }

    fn gen_test_cases() -> [TestCase; 5] {
        [
            TestCase {
                input: Input { s1: "pale", s2: "ple" },
                output: true,
            },
            TestCase {
                input: Input { s1: "pales", s2: "pale" },
                output: true,
            },
            TestCase {
                input: Input { s1: "pale", s2: "bale" },
                output: true,
            },
            TestCase {
                input: Input { s1: "pale", s2: "bake" },
                output: false,
            },
            TestCase {
                input: Input { s1: "pale", s2: "bales" },
                output: false,
            },
        ]
    }

    #[test]
    fn test_one_way() {
        for c in gen_test_cases() {
            assert_eq!(one_away(c.input.s1, c.input.s2), c.output);
        }
    }
}
