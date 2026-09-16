fn main(){
    let str1 = String::from("hello");
    let str2 = &str1; // str1's ownership moves into str2
    println!("{str1}");
    println!("{str2}");
}
