use std::error;
use std::fmt;

#[derive(Debug)]
pub enum SolverError {
    SolverFailed(String),
}

impl error::Error for SolverError {
    fn source(&self) -> Option<&(dyn error::Error + 'static)> {
        match *self {
            SolverError::SolverFailed(_) => None,
        }
    }
}

impl fmt::Display for SolverError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            SolverError::SolverFailed(func_name) => {
                write!(f, "{func_name} failed to solve the problem.")
            }
        }
    }
}
