use std::io;

fn is_unique(s: &str) -> bool {
    if !s.is_ascii() {
        panic!("Non-ascii character exists.");
    }

    let mut bit_for_check: u128 = 0;
    for c in s.chars() {
        if (bit_for_check & (1 << c as u32)) != 0 {
            return false
        }

        bit_for_check |= 1 << c as u32;
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
