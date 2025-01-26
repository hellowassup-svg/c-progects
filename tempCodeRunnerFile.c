#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int update_high_score(int score) {
    FILE *file;
    int high_score = 0;
    file = fopen("score.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &high_score);
        fclose(file);
    }

    if (score > high_score) {
        file = fopen("score.txt", "w");
        if (file == NULL) {
            printf("Error writing to the high score file.\n");
            return -1;
        }
        fprintf(file, "%d\n", score);
        fclose(file);
        return 1;
    }
    return high_score;
}

int generate_question(int min_b, int max_b, int min_c, int max_c, int time_limit) {
    char operators[] = {'+', '-', '*', '/'};
    int operator_index = rand() % 4;
    int b = min_b + rand() % (max_b - min_b + 1);
    int c = min_c + rand() % (max_c - min_c + 1);
    char operator = operators[operator_index];
    int correct_answer, user_answer;

    if (operator == '/') c = c == 0 ? 1 : c; // Prevent division by zero

    switch (operator) {
        case '+': correct_answer = b + c; break;
        case '-': correct_answer = b - c; break;
        case '*': correct_answer = b * c; break;
        case '/': correct_answer = b / c; break;
    }

    printf("%d %c %d = ", b, operator, c);
    time_t start = time(NULL);
    scanf("%d", &user_answer);
    time_t end = time(NULL);

    if (end - start > time_limit) {
        printf("Time out! Correct answer: %d\n", correct_answer);
        return 0;
    }

    if (user_answer == correct_answer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Wrong! Correct answer: %d\n", correct_answer);
        return 0;
    }
}

void play_round(int questions, int min_b, int max_b, int min_c, int max_c, int time_limit, int points_per_question, int *score) {
    for (int i = 0; i < questions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        if (generate_question(min_b, max_b, min_c, max_c, time_limit)) {
            *score += points_per_question;
        }
    }
}

int main() {
    srand(time(0));

    int choice, total_score;
    const int rounds = 3;
    const int questions_per_round = 5;
    const int min_b[] = {10, 20, 30};
    const int max_b[] = {35, 60, 90};
    const int min_c[] = {1, 1, 1};
    const int max_c[] = {10, 20, 30};
    const int time_limits[] = {4, 7, 9};
    const int points_per_question[] = {5, 10, 15};

    printf("\n** Welcome to the Math Game! **\n");
    printf("You will answer arithmetic problems across 3 rounds.\n");
    printf("Time limits and points per question increase each round.\n");

    while (1) {
        printf("\nPress 1 to start game or 2 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            total_score = 0;
            for (int round = 0; round < rounds; round++) {
                printf("\nROUND %d\n", round + 1);
                int round_score = 0;
                play_round(questions_per_round, min_b[round], max_b[round], min_c[round], max_c[round], time_limits[round], points_per_question[round], &round_score);
                printf("Score for Round %d: %d\n", round + 1, round_score);
                total_score += round_score;
            }

            int result = update_high_score(total_score);
            if (result == 1) {
                printf("\nNew high score! Your total score: %d\n", total_score);
            } else {
                printf("\nYour total score: %d\n", total_score);
                printf("High score: %d\n", result);
            }
        } else {
            printf("\nGoodbye!\n");
            exit(0);
        }
    }
}
