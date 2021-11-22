//! Problem: Implement a method to perform basic string compression using the counts of repeated
//! characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed"
//! string would not become smaller than the original string, your method should return the
//! original string. You can assume the string has only uppercase and lowercase letters (a-z).

#[derive(Debug)]
struct Pair {
    c: char,
    n: usize,
}

/// Returns the run length like compressed string only it is shorter than the original string.
pub fn string_compression(s: &str) -> String {
    // Calculate the length of the compressed string.
    // If the length of the compressed string is longer than or equal to that of the original one,
    // return the original one.
    let mut comp_len = 0;
    let mut pair: Option<Pair> = None;
    for c in s.chars() {
        match pair {
            None => {
                pair = Some(Pair { c: c, n: 1 });
            },
            Some(ref mut v) => {
                if v.c != c {
                    comp_len += 1 + get_num_digits(v.n);
                    *v = Pair{ c: c, n: 1 };
                } else {
                    v.n += 1;
                }
            },
        }
    }
    if let Some(v) = pair {
        comp_len += 1 + get_num_digits(v.n);
    }

    if comp_len >= s.len() {
        return s.to_string();
    }

    // create the compressed string because its length is shorter than the original one.
    let mut comp = String::with_capacity(comp_len);
    pair = None;
    for c in s.chars() {
        match pair {
            None => {
                pair = Some(Pair { c: c, n: 1 });
            },
            Some(ref mut v) => {
                if v.c != c {
                    comp.push(v.c);
                    comp.push_str(&v.n.to_string());
                    *v = Pair { c: c, n: 1 };
                } else {
                    v.n += 1;
                }
            },
        }
    }
    if let Some(v) = pair {
        comp.push(v.c);
        comp.push_str(&v.n.to_string());
    }

    comp
}

/// Gets the number of digits of the given number.
fn get_num_digits(mut x: usize) -> usize {
    let mut n = 0;

    while x != 0 {
        n += 1;
        x /= 10;
    }

    n
}


#[cfg(test)]
mod tests {
    use super::*;

    struct TestCase {
        input: &'static str,
        output: &'static str,
    }

    fn gen_test_cases() -> [TestCase; 4] {
        [
            TestCase {
                input: "apple",
                output: "apple",
            },
            TestCase {
                input: "aaappllle",
                output: "a3p2l3e1",
            },
            TestCase {
                input: "aaaaaaaaaapleaplea",
                output: "aaaaaaaaaapleaplea",
            },
            TestCase {
                input: "aaaaaaaaaaaapleaplea",
                output: "a12p1l1e1a1p1l1e1a1",
            },
        ]
    }


    #[test]
    fn test_string_compression() {
        for c in gen_test_cases() {
            assert_eq!(&string_compression(c.input), c.output);
        }
    }
}
