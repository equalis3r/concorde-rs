//! The interface for all available solvers.
use super::errors::SolverError;
use super::LowerDistanceMatrix;
use std::ffi::c_int;
use std::ffi::c_uint;
use std::fmt;

/// Held-Karp dynamic programming.
/// # Errors
///
/// If the solver cannot solve the TSP, the return length from Concorde TSP is -1.0.
/// Thus, the solver will return SolverError.
pub fn tsp_hk(dist_mat: &LowerDistanceMatrix) -> Result<Solution, SolverError> {
    let mut tour = vec![0u32; dist_mat.num_nodes as usize];
    let length = unsafe {
        CCtsp_hk(
            dist_mat.values.as_ptr(),
            tour.as_mut_ptr(),
            dist_mat.num_nodes,
        )
    };
    match u32::try_from(length) {
        Ok(val) => Ok(Solution { length: val, tour }),
        Err(_) => Err(SolverError::SolverFailed(String::from("Held-Karp"))),
    }
}

/// Lin-Kernighan heuristic.
/// # Errors
///
/// If the solver cannot solve the TSP, the return length from Concorde TSP is -1.0.
/// Thus, the solver will return SolverError.
pub fn tsp_lk(dist_mat: &LowerDistanceMatrix) -> Result<Solution, SolverError> {
    let stall_count = i32::pow(10, 6);
    let mut tour = vec![0u32; dist_mat.num_nodes as usize];
    let length = unsafe {
        CCtsp_lk(
            dist_mat.values.as_ptr(),
            tour.as_mut_ptr(),
            dist_mat.num_nodes,
            stall_count,
        )
    };
    match u32::try_from(length) {
        Ok(val) => Ok(Solution { length: val, tour }),
        Err(_) => Err(SolverError::SolverFailed(String::from("Lin-Kernighan"))),
    }
}

extern "C" {
    fn CCtsp_hk(dist_mat: *const c_uint, tour: *mut c_uint, ncount: c_uint) -> i32;
    fn CCtsp_lk(
        dist_mat: *const c_uint,
        tour: *mut c_uint,
        ncount: c_uint,
        stall_count: c_int,
    ) -> i32;
}

/// A solution consists of the tour and the length of that tour.
///
/// * `tour`:
/// * `length`:
#[derive(Clone, Debug)]
pub struct Solution {
    pub tour: Vec<u32>,
    pub length: u32,
}

impl PartialEq for Solution {
    fn eq(&self, other: &Self) -> bool {
        self.length == other.length
    }
}

impl Solution {
    /// # Examples
    /// ```
    /// use concorde_rs::{LowerDistanceMatrix, Solution};
    ///
    /// let dist_mat =
    ///     LowerDistanceMatrix::new(5, vec![0, 3, 0, 4, 4, 0, 2, 6, 5, 0, 7, 3, 8, 6, 0]);
    /// let tour: Vec<u32> = vec![0, 2, 1, 4, 3];
    /// assert_eq!(Solution::calc_length_from_tour(&tour, &dist_mat), 19);
    /// ```
    pub fn calc_length_from_tour(tour: &[u32], dist_mat: &LowerDistanceMatrix) -> u32 {
        let num_nodes = tour.len();
        tour[..num_nodes - 1]
            .iter()
            .zip(tour[1..num_nodes].iter())
            .map(|(&p1, &p2)| dist_mat.dist(p1 as usize, p2 as usize))
            .sum::<u32>()
            + dist_mat.dist(tour[num_nodes - 1] as usize, 0)
    }
}

impl fmt::Display for Solution {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        writeln!(f, "Distance: {}", self.length)?;
        write!(f, "Tour: ")?;
        for node in &self.tour {
            write!(f, "{node} -> ")?;
        }
        write!(f, "{}", self.tour[0])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_5_cities_instance() {
        let dist_mat =
            LowerDistanceMatrix::new(5, vec![0, 3, 0, 4, 4, 0, 2, 6, 5, 0, 7, 3, 8, 6, 0]);
        let sol = tsp_hk(&dist_mat).unwrap();
        assert_eq!(sol.length, 19);
        assert_eq!(Solution::calc_length_from_tour(&sol.tour, &dist_mat), 19);
    }

    #[test]
    fn test_10_cities_instance() {
        let dist_mat = LowerDistanceMatrix::new(
            10,
            vec![
                0, 633, 0, 257, 390, 0, 91, 661, 228, 0, 412, 227, 169, 383, 0, 150, 488, 112, 120,
                267, 0, 80, 572, 196, 77, 351, 63, 0, 134, 530, 154, 105, 309, 34, 29, 0, 259, 555,
                372, 175, 338, 264, 232, 249, 0, 505, 289, 262, 476, 196, 360, 444, 402, 495, 0,
            ],
        );
        let sol = tsp_hk(&dist_mat).unwrap();
        assert_eq!(sol.length, 1637);
        assert_eq!(Solution::calc_length_from_tour(&sol.tour, &dist_mat), 1637);
    }

    #[test]
    fn test_14_cities_instance() {
        let dist_mat = LowerDistanceMatrix::new(
            14,
            vec![
                0, 32, 0, 25, 7, 0, 2, 30, 23, 0, 21, 35, 28, 19, 0, 20, 30, 37, 22, 41, 0, 26, 40,
                33, 24, 9, 46, 0, 23, 37, 30, 21, 26, 43, 21, 0, 38, 12, 19, 40, 47, 18, 52, 49, 0,
                60, 46, 49, 60, 65, 40, 70, 67, 34, 0, 39, 11, 18, 41, 46, 19, 51, 48, 1, 35, 0,
                70, 64, 57, 68, 73, 90, 68, 57, 76, 54, 75, 0, 24, 38, 31, 22, 27, 44, 22, 1, 50,
                68, 49, 56, 0, 51, 45, 38, 49, 54, 71, 55, 52, 57, 35, 56, 39, 53, 0,
            ],
        );
        let sol = tsp_hk(&dist_mat).unwrap();
        assert_eq!(sol.length, 284);
        assert_eq!(Solution::calc_length_from_tour(&sol.tour, &dist_mat), 284);
    }

    #[test]
    fn test_17_cities_instance() {
        let dist_mat = LowerDistanceMatrix::new(
            17,
            vec![
                0, 633, 0, 257, 390, 0, 91, 661, 228, 0, 412, 227, 169, 383, 0, 150, 488, 112, 120,
                267, 0, 80, 572, 196, 77, 351, 63, 0, 134, 530, 154, 105, 309, 34, 29, 0, 259, 555,
                372, 175, 338, 264, 232, 249, 0, 505, 289, 262, 476, 196, 360, 444, 402, 495, 0,
                353, 282, 110, 324, 61, 208, 292, 250, 352, 154, 0, 324, 638, 437, 240, 421, 329,
                297, 314, 95, 578, 435, 0, 70, 567, 191, 27, 346, 83, 47, 68, 189, 439, 287, 254,
                0, 211, 466, 74, 182, 243, 105, 150, 108, 326, 336, 184, 391, 145, 0, 268, 420, 53,
                239, 199, 123, 207, 165, 383, 240, 140, 448, 202, 57, 0, 246, 745, 472, 237, 528,
                364, 332, 349, 202, 685, 542, 157, 289, 426, 483, 0, 121, 518, 142, 84, 297, 35,
                29, 36, 236, 390, 238, 301, 55, 96, 153, 336, 0,
            ],
        );
        let sol = tsp_lk(&dist_mat).unwrap();
        assert_eq!(sol.length, 2085);
        assert_eq!(Solution::calc_length_from_tour(&sol.tour, &dist_mat), 2085);
    }

    #[test]
    fn test_26_cities_instance() {
        let dist_mat = LowerDistanceMatrix::new(
            26,
            vec![
                0, 83, 0, 93, 40, 0, 129, 53, 42, 0, 133, 62, 42, 11, 0, 139, 64, 49, 11, 9, 0,
                151, 91, 59, 46, 35, 39, 0, 169, 116, 81, 72, 61, 65, 26, 0, 135, 93, 54, 65, 55,
                63, 34, 37, 0, 114, 84, 44, 70, 62, 71, 52, 59, 22, 0, 110, 95, 58, 88, 82, 90, 71,
                75, 39, 20, 0, 98, 98, 64, 100, 95, 103, 88, 92, 56, 36, 18, 0, 99, 89, 54, 89, 84,
                92, 77, 83, 47, 26, 11, 11, 0, 95, 68, 31, 66, 62, 71, 63, 76, 40, 20, 27, 34, 23,
                0, 81, 67, 36, 76, 74, 82, 78, 91, 55, 34, 32, 31, 24, 15, 0, 152, 127, 86, 102,
                93, 100, 66, 54, 37, 43, 42, 56, 53, 62, 73, 0, 159, 156, 117, 142, 133, 141, 110,
                98, 78, 74, 61, 63, 68, 87, 92, 44, 0, 181, 175, 135, 156, 146, 153, 119, 103, 91,
                91, 80, 85, 89, 106, 112, 54, 22, 0, 172, 152, 112, 127, 117, 124, 88, 70, 62, 68,
                64, 75, 74, 87, 96, 26, 34, 33, 0, 185, 165, 125, 139, 128, 135, 98, 78, 74, 82,
                77, 87, 87, 100, 109, 39, 38, 29, 13, 0, 147, 160, 124, 155, 148, 156, 130, 122,
                96, 86, 68, 62, 71, 93, 93, 68, 30, 46, 63, 68, 0, 157, 180, 147, 180, 173, 181,
                156, 148, 122, 111, 92, 83, 93, 116, 113, 94, 53, 64, 87, 90, 26, 0, 185, 223, 193,
                228, 222, 230, 206, 198, 172, 160, 140, 129, 140, 163, 158, 144, 102, 107, 135,
                136, 77, 50, 0, 220, 268, 241, 278, 272, 280, 257, 250, 223, 210, 190, 178, 189,
                212, 205, 196, 154, 157, 186, 186, 128, 102, 51, 0, 127, 179, 157, 197, 194, 202,
                188, 188, 155, 136, 116, 100, 111, 132, 122, 139, 109, 125, 141, 148, 80, 65, 64,
                93, 0, 181, 197, 161, 190, 182, 190, 160, 148, 128, 121, 103, 99, 107, 130, 130,
                95, 51, 51, 81, 79, 37, 27, 58, 107, 90, 0,
            ],
        );
        let sol = tsp_lk(&dist_mat).unwrap();
        assert_eq!(sol.length, 937);
        assert_eq!(Solution::calc_length_from_tour(&sol.tour, &dist_mat), 937);
    }

    #[test]
    fn test_34_cities_instance() {
        let dist_mat = LowerDistanceMatrix::new(
            34,
            vec![
                0, 96, 0, 16, 112, 0, 49, 145, 33, 0, 82, 14, 98, 131, 0, 46, 142, 30, 3, 128, 0,
                62, 98, 46, 63, 84, 60, 0, 47, 123, 31, 48, 109, 45, 41, 0, 106, 10, 122, 155, 24,
                152, 108, 133, 0, 56, 40, 72, 105, 26, 102, 78, 83, 50, 0, 72, 128, 56, 49, 114,
                52, 36, 31, 138, 88, 0, 63, 59, 79, 92, 45, 89, 125, 110, 69, 47, 135, 0, 58, 72,
                48, 73, 58, 70, 26, 51, 82, 52, 56, 99, 0, 56, 80, 40, 65, 66, 62, 18, 43, 90, 60,
                48, 107, 8, 0, 53, 43, 69, 102, 29, 99, 75, 80, 53, 3, 85, 50, 49, 57, 0, 42, 138,
                26, 7, 124, 4, 56, 41, 148, 98, 56, 85, 66, 58, 95, 0, 60, 116, 44, 61, 102, 58,
                34, 39, 126, 76, 12, 123, 44, 36, 73, 54, 0, 49, 47, 65, 98, 33, 95, 51, 76, 57,
                35, 81, 74, 25, 33, 32, 91, 69, 0, 58, 134, 42, 43, 120, 46, 50, 11, 144, 94, 20,
                121, 62, 54, 91, 50, 32, 87, 0, 85, 11, 101, 134, 3, 131, 87, 112, 21, 29, 117, 48,
                61, 69, 32, 127, 105, 36, 123, 0, 77, 49, 93, 126, 59, 123, 139, 124, 39, 61, 149,
                40, 113, 121, 64, 119, 137, 88, 135, 60, 0, 76, 70, 92, 105, 58, 102, 138, 123, 60,
                60, 148, 13, 112, 120, 63, 98, 136, 87, 134, 61, 29, 0, 109, 13, 125, 158, 27, 155,
                111, 136, 3, 53, 141, 70, 85, 93, 56, 151, 129, 60, 147, 24, 36, 57, 0, 8, 104, 8,
                41, 90, 38, 54, 39, 114, 64, 64, 71, 56, 48, 61, 34, 52, 57, 50, 93, 85, 84, 117,
                0, 82, 64, 98, 111, 64, 108, 144, 129, 54, 66, 154, 19, 118, 126, 69, 104, 142, 93,
                140, 67, 23, 6, 51, 90, 0, 79, 47, 95, 128, 61, 125, 141, 126, 37, 63, 151, 40,
                115, 123, 66, 121, 139, 90, 137, 58, 2, 27, 34, 87, 21, 0, 7, 103, 9, 42, 89, 39,
                55, 40, 113, 63, 65, 70, 57, 49, 60, 35, 53, 56, 51, 92, 84, 83, 116, 1, 89, 86, 0,
                63, 119, 47, 58, 105, 61, 37, 40, 129, 79, 9, 126, 47, 39, 76, 57, 3, 72, 29, 108,
                140, 139, 132, 55, 145, 142, 56, 0, 31, 125, 15, 20, 111, 17, 53, 38, 135, 85, 63,
                72, 55, 47, 82, 13, 51, 78, 49, 114, 106, 85, 138, 23, 91, 108, 24, 54, 0, 54, 130,
                38, 47, 116, 50, 48, 7, 140, 90, 24, 117, 58, 50, 87, 48, 36, 83, 4, 119, 131, 130,
                143, 46, 136, 133, 47, 33, 45, 0, 59, 95, 43, 60, 81, 57, 3, 38, 105, 75, 39, 122,
                23, 15, 72, 53, 31, 48, 49, 84, 136, 135, 108, 51, 141, 138, 52, 34, 50, 45, 0, 88,
                58, 104, 117, 70, 114, 150, 135, 48, 72, 160, 25, 124, 132, 75, 110, 148, 99, 146,
                69, 17, 12, 45, 96, 6, 15, 95, 151, 97, 142, 147, 0, 56, 112, 40, 57, 98, 54, 30,
                35, 122, 72, 16, 119, 40, 32, 69, 50, 4, 65, 36, 101, 133, 132, 125, 48, 138, 135,
                49, 7, 47, 40, 27, 144, 0, 33, 103, 49, 62, 89, 59, 95, 80, 113, 63, 105, 50, 69,
                77, 60, 55, 93, 56, 91, 92, 84, 63, 116, 41, 69, 86, 40, 96, 42, 87, 92, 75, 89, 0,
            ],
        );
        let sol = tsp_lk(&dist_mat).unwrap();
        assert_eq!(sol.length, 476);
        assert_eq!(Solution::calc_length_from_tour(&sol.tour, &dist_mat), 476);
    }
}
