use std::env;
use std::process::Command;

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();

    Command::new("make")
        .env("OUT_DIR", &out_dir)
        .args(["-C", "src/concorde"])
        .output()
        .expect("Failed to make");

    println!("cargo:rustc-link-search=native={}", out_dir);
    println!("cargo:rustc-link-lib=static=concorde");
    println!("cargo:rerun-if-changed=src/concorde/*");
}
