use std::io;

fn is_unique(s: &str) -> bool {
    if !s.is_ascii() {
        panic!("Non-ascii character exists.");
    }

    let mut cnt: [u32; 128] = [0; 128];

    for c in s.chars() {
        let n = c as usize;

        if cnt[n] != 0 {
            return false;
        }

        cnt[n] += 1;
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
