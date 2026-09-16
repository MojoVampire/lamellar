// Two common enums in rust are Option and Result
// Option is used to represent the possibility of a value being present or absent
// Result is used to represent the possibility of an operation failing
//
// enum Option<T> { Some(T), None }
// enum Result<T, E> { Ok(T), Err(E) }

#[derive(Debug, Clone, Copy)]
struct Complex {
    re: f64,
    im: f64,
}

impl std::ops::Add for Complex {
    type Output = Self;
    fn add(self, other: Self) -> Self::Output {
        Complex {
            re: self.re + other.re,
            im: self.im + other.im,
        }
    }
}

fn max_real(nums: &[Complex]) -> Option<&Complex> {
    if nums.is_empty() {
        return None;
    }
    let mut max = &nums[0];
    for num in nums.iter() {
        if num.re > max.re {
            max = num;
        }
    }
    Some(max)
}

fn sum_if_all_negative(nums: &[Complex]) -> Result<Complex, &'static str> {
    for num in nums.iter() {
        if num.re > 0.0 || num.im > 0.0 {
            return Err("All numbers must be negative");
        }
    }
    let mut sum = Complex { re: 0.0, im: 0.0 };
    for num in nums.iter() {
        sum = sum + *num;
    }
    Ok(sum)
}

fn process_nums_unwrap(nums: &[Complex]) {
    if let Some(max) = max_real(nums) {
        println!("Max real: {max:?}");
    } else {
        println!("nums is empty, has no maximum");
    }
    if let Ok(sum) = sum_if_all_negative(nums) {
        println!("Sum: {sum:?}");
    } else {
        println!("nums contained positive values");
    }
}

fn main() {
    let nums_0 = vec![
        Complex { re: 1.0, im: 2.0 },
        Complex { re: 3.0, im: 4.0 },
    ];
    let nums_1 = vec![
        Complex { re: -5.0, im: -6.0 },
        Complex { re: -7.0, im: -8.0},
    ];
    let nums_2: Vec<Complex> = vec![];

    println!("For >0 positive values:");
    process_nums_unwrap(&nums_0);
    println!("\nFor >0 purely negative values:");
    process_nums_unwrap(&nums_1);
    println!("\nFor empty:");
    process_nums_unwrap(&nums_2);
}
