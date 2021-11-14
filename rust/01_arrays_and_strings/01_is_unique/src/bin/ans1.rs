use std::io;

fn is_unique(s: &str) -> bool {
    if !s.is_ascii() {
        panic!("Non-ascii character exists.");
    }

    let n = s.len();
    let s = s.as_bytes();

    for i in 0..n {
        for j in i+1..n {
            if s[i] == s[j] {
                return false;
            }
        }
    }

    true
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    if is_unique(&s) {
        println!("Characters are unique.");
    } else {
        println!("Characters are not unique.");
    }
}
