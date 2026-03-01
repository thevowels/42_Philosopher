# Philosopher Project - Change Log

## Version 3 - philo_v3

### [Unreleased] - 2026-03-02

#### Fixed
- **Critical Logic Error**: Fixed program execution when `number_of_times_each_philosopher_must_eat` is set to 0
  - **Issue**: Program would run the full dining simulation even when no meals were required (max_meals = 0)
  - **Expected Behavior**: Program should immediately exit with success status when max_meals = 0
  - **Root Cause**: Missing validation check in argument parsing logic
  - **Files Modified**: 
    - `src/parser.c` - Added early exit condition for max_meals = 0
  - **Impact**: Fixes incorrect behavior and improves performance for edge case where no eating is required

---

## Previous Versions

### Version 2 - philo_v2
- Incomplete implementation (development version)

### Version 1 - philo_v1  
- Initial working implementation with basic philosopher dining simulation
- Had correct handling of max_meals = 0 case in validation logic