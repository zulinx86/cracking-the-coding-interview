#[derive(Debug,PartialEq)]
pub struct Mat<T: Copy> {
    data: Vec<Vec<T>>,
    dim: usize,
}

impl<T: Copy> Mat<T> {
    pub fn from(data: Vec<Vec<T>>) -> Mat<T> {
        let dim = data.len();
        for i in &data {
            if i.len() != dim {
                panic!(
                    "rows and cols should be same: rows={}, cols={}",
                    dim,
                    i.len()
                );
            }
        }

        Mat { data, dim }
    }
}

/// Rotate 2D matrix by 90 degrees.
///
/// - Time complexity: O(N)
/// - Space complexity: O(1)
/// - where N is the number of elements in the given matrix
pub fn rotate_matrix<T: Copy>(m: &mut Mat<T>) {
    let mut tmp;
    for i in 0..m.dim / 2 {
        for j in i..m.dim - 1 - i {
            tmp = m.data[i][j];
            m.data[i][j] = m.data[m.dim - 1 - j][i];
            m.data[m.dim - 1 - j][i] = m.data[m.dim - 1 - i][m.dim - 1 - j];
            m.data[m.dim - 1 - i][m.dim - 1 - j] = m.data[j][m.dim - 1 - i];
            m.data[j][m.dim - 1 - i] = tmp;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    struct TestCase {
        input: Mat<u32>,
        output: Mat<u32>,
    }

    fn gen_test_cases() -> [TestCase; 2] {
        [
            TestCase {
                input: Mat::from(vec![
                    vec![1, 2, 3],
                    vec![4, 5, 6],
                    vec![7, 8, 9],
                ]),
                output: Mat::from(vec![
                    vec![7, 4, 1],
                    vec![8, 5, 2],
                    vec![9, 6, 3],
                ]),
            },
            TestCase {
                input: Mat::from(vec![
                    vec![01, 02, 03, 04],
                    vec![05, 06, 07, 08],
                    vec![09, 10, 11, 12],
                    vec![13, 14, 15, 16],
                ]),
                output: Mat::from(vec![
                    vec![13, 09, 05, 01],
                    vec![14, 10, 06, 02],
                    vec![15, 11, 07, 03],
                    vec![16, 12, 08, 04],
                ]),
            },
        ]
    }

    #[test]
    fn test_rotate_matrix() {
        for ref mut c in gen_test_cases() {
            rotate_matrix(&mut c.input);
            assert_eq!(c.input, c.output);
        }
    }
}
