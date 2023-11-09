/// If the lower distance matrix values are not provided but a vector of nodes,
/// then node needs to implement distance trait.
pub trait Distance {
    fn calc_shortest_dist(&self, other: &Self) -> u32;
}

#[derive(Debug, PartialEq, Eq)]
pub struct LowerDistanceMatrix {
    pub num_nodes: u32,
    pub values: Vec<u32>,
}

impl LowerDistanceMatrix {
    #[must_use]
    pub fn new(num_points: u32, values: Vec<u32>) -> Self {
        Self {
            num_nodes: num_points,
            values,
        }
    }

    /// # Examples
    /// ```
    /// use concorde_rs::LowerDistanceMatrix;
    ///
    /// let dist_mat = LowerDistanceMatrix::new(4, vec![0, 3, 0, 4, 4, 0, 2, 6, 5, 0]);
    /// assert_eq!(dist_mat.dist(3, 2), 5);
    /// assert_eq!(dist_mat.dist(2, 3), 5);
    /// ```
    #[must_use]
    pub fn dist(&self, from_node: usize, to_node: usize) -> u32 {
        self.values[Self::get_node(from_node, to_node)]
    }

    /// # Examples
    /// ```
    /// use concorde_rs::LowerDistanceMatrix;
    ///
    /// let mut dist_mat = LowerDistanceMatrix::new(4, vec![0, 3, 0, 4, 4, 0, 2, 6, 5, 0]);
    /// *dist_mat.dist_mut(3, 2) = 10;
    /// assert_eq!(dist_mat.dist(2, 3), 10);
    /// ```
    #[must_use]
    pub fn dist_mut(&mut self, from_node: usize, to_node: usize) -> &mut u32 {
        &mut self.values[Self::get_node(from_node, to_node)]
    }

    #[must_use]
    fn get_node(from_node: usize, to_node: usize) -> usize {
        let (i, j) = if from_node >= to_node {
            (from_node, to_node)
        } else {
            (to_node, from_node)
        };
        i * (i + 1) / 2 + j
    }
}

impl<T: Distance> From<&[T]> for LowerDistanceMatrix {
    /// # Examples
    /// ```
    /// use concorde_rs::{solver, Distance, LowerDistanceMatrix};
    ///
    /// struct Node(i32, i32);
    ///
    /// impl Distance for Node {
    ///     fn calc_shortest_dist(&self, other: &Self) -> u32 {
    ///         self.0.abs_diff(other.0) + self.1.abs_diff(other.1)
    ///     }
    /// }
    /// let nodes: Vec<Node> = vec![Node(0, 0), Node(0, 3), Node(5, 6), Node(9, 1)];
    /// assert_eq!(
    ///     LowerDistanceMatrix::from(nodes.as_ref()),
    ///     LowerDistanceMatrix::new(4, vec![0, 3, 0, 11, 8, 0, 10, 11, 9, 0])
    /// );
    /// ```
    fn from(nodes: &[T]) -> Self {
        let values: Vec<u32> = nodes
            .iter()
            .enumerate()
            .flat_map(|(i, node_i)| {
                nodes[..=i]
                    .iter()
                    .map(|node_j| node_i.calc_shortest_dist(node_j))
            })
            .collect();
        Self::new(nodes.len() as u32, values)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_node() {
        assert_eq!(LowerDistanceMatrix::get_node(0, 0), 0);
        assert_eq!(LowerDistanceMatrix::get_node(2, 3), 8);
        assert_eq!(LowerDistanceMatrix::get_node(3, 2), 8);
    }
}
