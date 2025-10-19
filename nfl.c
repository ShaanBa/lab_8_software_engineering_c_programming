#include <stdio.h>

int main(void) {
    int nflscore;
    int c;

    printf("Enter the NFL score (Enter 1 to stop): ");
    while (scanf("%d", &nflscore) == 1) {
        /* consume rest of line */
        while ((c = getchar()) != '\n' && c != EOF) { }

        if (nflscore == 1) {
            break;
        }

        if (nflscore < 2) {
            printf("Invalid score: must be >= 2 (enter 1 to stop).\n");
            printf("Enter the NFL score (Enter 1 to stop): ");
            continue;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", nflscore);

        int found = 0;
        /* iterate in the order shown in the assignment: TD+2pt (8), TD+FG (7), TD (6), 3pt FG (3), Safety (2) */
        for (int td2 = 0; td2 <= nflscore / 8; td2++) {
            int rem1 = nflscore - td2 * 8;
            for (int td_fg = 0; td_fg <= rem1 / 7; td_fg++) {
                int rem2 = rem1 - td_fg * 7;
                for (int td = 0; td <= rem2 / 6; td++) {
                    int rem3 = rem2 - td * 6;
                    for (int fg = 0; fg <= rem3 / 3; fg++) {
                        int rem4 = rem3 - fg * 3;
                        if (rem4 < 0) break;
                        if (rem4 % 2 != 0) continue; /* leftover must be divisible by 2 (safeties) */
                        int safety = rem4 / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td2, td_fg, td, fg, safety);
                        found = 1;
                    }
                }
            }
        }

        if (!found) {
            printf("No combinations found for score %d.\n", nflscore);
        }

        printf("Enter the NFL score (Enter 1 to stop): ");
    }

    return 0;
}