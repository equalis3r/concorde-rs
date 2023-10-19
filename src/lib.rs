//! A Rust binding to [Concorde TSP Solver](https://www.math.uwaterloo.ca/tsp/concorde.html) that allows for directly calling the solver instead of communicating the problem via TSP.lib file.
//! At the moment, this package only supports the call to two routines of the Concorde TSP Solver:
//! 1. Heldkarp: an exact solver based on dynamic programming
//! 2. Lin-Kernighan: a heuristic solver
//!
//! # Example
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
//! let solution = solver::tsp_hk(&dist_mat);
//!
//! assert_eq!(solution.length, 30);
//! ```
pub mod distance;
pub mod solver;

pub use distance::{Distance, LowerDistanceMatrix};
pub use solver::Solution;
