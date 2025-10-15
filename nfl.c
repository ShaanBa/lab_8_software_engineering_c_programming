#include <stdio.h>

int main() {
    int nflscore;
    printf("Enter the NFL score (Enter 1 to stop): \n");
    scanf("%d", &nflscore);

    while (nflscore != 1) {
        for (int td_count = 0; td_count <= nflscore/6; td_count++) {
            for (int td_with_fg_count = 0; td_with_fg_count <= nflscore/7; td_with_fg_count++) {
                for (int td_with_2_pt = 0; td_with_2_pt <= nflscore/8; td_with_2_pt++) {
                    for (int three_pt_fg = 0; three_pt_fg <= nflscore/3; three_pt_fg++) {
                        for (int safety = 0; safety <= nflscore/2; safety++) {
                            int total_score = (td_count * 6) + (td_with_fg_count * 7) + (td_with_2_pt * 8) + (three_pt_fg * 3) + (safety * 2);
                            if (total_score == nflscore) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_with_2_pt, td_with_fg_count, td_count, three_pt_fg, safety);
                            }
                        }
                    }
                }
            }
        }

        printf("Enter the NFL score (Enter 1 to stop): \n");
        scanf("%d", &nflscore);
    }
    return 0;
}