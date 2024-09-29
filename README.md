# Random Walk Simulation
(Special thanks to codocoder for telling me about this on discord!)
This project simulates a special type of random walk to demonstrate the relationship between the golden ratio and the probability of returning to the origin in certain random walk scenarios.

## Overview

This simulation explores a fascinating connection between random walks and the golden ratio (φ). In this particular random walk:

- At each step, the walker has two options:
  1. Move 2 steps away from the origin (with 50% probability)
  2. Move 1 step towards the origin (with 50% probability)
- The walk starts at a specified distance d from the origin
- The walk "halts" if it reaches the origin (position 0)

The key mathematical insight is that for a walk starting d steps away from the origin, the probability of eventually returning to the origin is 1/φ^d, where φ is the golden ratio (approximately 1.618033988749895).

## The Simulation

The program runs a Monte Carlo simulation to empirically verify this theoretical relationship:

- It tests starting positions from 1 to 9 steps away from the origin
- For each starting position, it runs 100,000 trial walks
- Each walk is limited to a maximum of 100 steps
- It counts how many walks return to the origin ("halt") for each starting position
- It compares the empirical results with the theoretical prediction

## Optimization

The simulation includes an optimization to improve performance:

- A `POSITION_LIMIT` constant (set to 20 by default) is introduced
- If a walk reaches or exceeds this limit, it's considered extremely unlikely to return to the origin
- Such walks are terminated early, saving computational time
- This allows for more trials to be run, increasing overall accuracy

This optimization trades off some accuracy for walks that might return from beyond the position limit, but it allows for a much larger number of trials in the same computational time, generally improving the overall accuracy of the results.

## Running the Simulation

### Prerequisites

- A C compiler (e.g., gcc)
- The math library (usually included with the C standard library)

### Compilation

Compile the program using the following command:

```
gcc -o phi phi.c -lm
```

The `-lm` flag is necessary to link the math library.

### Execution

Run the compiled program:

```
./phi
```

## Output Interpretation

For each starting position, the program outputs:
1. The starting position
2. The number of walks that halted (returned to origin) out of 10,000 trials
3. The theoretically predicted number of halted walks

You can compare the empirical results with the theoretical predictions to see how closely they align.

## Mathematical Background

The relationship between this random walk and the golden ratio stems from the recursive nature of the walk's probabilities. The probability of returning to the origin from position n can be expressed in terms of the probabilities from positions n+1 and n+2, forming a recurrence relation that involves the golden ratio.

This connection showcases how fundamental mathematical constants like φ can emerge in various probabilistic and combinatorial contexts.

## Further Exploration

You can modify the `NTRIALS`, `STEPLIMIT`, and `POSITION_LIMIT` constants in the code to experiment with different simulation parameters:

- Increasing `NTRIALS` will give more accurate results but will take longer to run.
- Adjusting `STEPLIMIT` can help you explore how the walk behaves over different time scales.
- Changing `POSITION_LIMIT` allows you to fine-tune the trade-off between speed and accuracy. A lower limit will run faster but may miss some rare events where a walk returns from far away. A higher limit will be more accurate but slower.

Try different values for these parameters and observe how they affect the accuracy of the results compared to the theoretical prediction.
