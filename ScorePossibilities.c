#include <stdio.h>

void findCombinations(int score) {
    printf("possible combinations of scoring plays:\n");

    const int TD_6 = 6;  
    const int TD_7 = 7;  
    const int TD_8 = 8;  
    const int FG = 3;    
    const int SAFETY = 2; 

    for (int td_8 = 0; td_8 <= score / TD_8; ++td_8) {
        for (int td_7 = 0; td_7 <= score / TD_7; ++td_7) {
            for (int td_6 = 0; td_6 <= score / TD_6; ++td_6) {
                for (int fg = 0; fg <= score / FG; ++fg) {
                    for (int safety = 0; safety <= score / SAFETY; ++safety) {
                        if (td_8 * TD_8 + td_7 * TD_7 + td_6 * TD_6 + fg * FG + safety * SAFETY == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_8, td_7, td_6, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    do {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score > 1) {
            findCombinations(score);
        }
    } while (score > 1);

    return 0;
}
