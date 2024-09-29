#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NTRIALS 100000
#define STEPLIMIT 100
#define POSITION_LIMIT 20

int main() {
    srand(time(NULL));

    for (int starting_position = 1; starting_position < 10; starting_position++) {
        int nhalted = 0;
        printf("starting position: %d\n", starting_position);

        for (int trial = 0; trial < NTRIALS; trial++) {
            int position = starting_position;
            int steps = 0;

            while (steps < STEPLIMIT) {
                if (rand() % 2 == 0) {
                    position += 2;
                } else {
                    position -= 1;
                }

                if (position == 0) {
                    nhalted++;
                    break;
                }
                if (position >= POSITION_LIMIT) {
                    break;
                }
                steps++;
            }
        }

        printf("%d / %d halted\n", nhalted, NTRIALS);

        double phi = (1 + sqrt(5)) / 2;
        printf("%.2f predicted\n\n", NTRIALS / pow(phi, starting_position));
    }

    return 0;
}
