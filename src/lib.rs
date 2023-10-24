//! A Rust binding to [Concorde TSP Solver](https://www.math.uwaterloo.ca/tsp/concorde.html) that allows for directly calling the solver instead of communicating the problem via TSP.lib file.
//! At the moment, this package only supports the call to two routines of the Concorde TSP Solver:
//! 1. [`solver::tsp_hk`]: Held-Karp dynamic programming algorithm
//! 2. [`solver::tsp_lk`]: Lin-Kernighan heuristic
//!
//! # Examples
//!
//! If values for lower distance matrix are provided:
//! ```
//! use concorde_rs::{solver, LowerDistanceMatrix};
//!
//! let dist_mat =
//!     LowerDistanceMatrix::new(5, vec![0, 3, 0, 4, 4, 0, 2, 6, 5, 0, 7, 3, 8, 6, 0]);
//! assert_eq!(solver::tsp_hk(&dist_mat).unwrap().length, 19);
//! ```
//!
//! If values for lower distance matrix are **not** provided:
//! ```
//! use concorde_rs::{solver, Distance, LowerDistanceMatrix};
//!
//! struct Node(i32, i32);
//!
//! impl Distance for Node {
//!     fn calc_shortest_dist(&self, other: &Self) -> u32 {
//!         self.0.abs_diff(other.0) + self.1.abs_diff(other.1)
//!     }
//! }
//!
//! let nodes: Vec<Node> = vec![Node(0, 0), Node(0, 3), Node(5, 6), Node(9, 1)];
//! let dist_mat = LowerDistanceMatrix::from(nodes.as_ref());
//! let solution = solver::tsp_hk(&dist_mat).unwrap();
//!
//! assert_eq!(solution.length, 30);
//! ```
pub mod distance;
pub mod solver;

mod errors;

pub use distance::{Distance, LowerDistanceMatrix};
pub use solver::Solution;
