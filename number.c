#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int score(int);
int question1();
int question2();
int question3();
int score(int ss) {
    FILE *file;
    int high_score = 0;
    file = fopen("score.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &high_score); 
        fclose(file); 
    } else {
        high_score = 0;
    }

    if (ss > high_score) {
        file = fopen("score.txt", "w");
        if (file == NULL) {
            printf("Error writing to the high score file.\n");
            return -1; 
        }
        fprintf(file, "%d\n", ss); 
        fclose(file); 
        return 1; 
    }

    return high_score; 
}

int question1()
{
    char sign[2]={'+','-'};
    int a=(rand() % 2);
    time_t t1,t2;
    t1=time(NULL);
    char operator = sign[a];
    int b=10+rand()%35,c=10+rand()%35;
    int ans,rans;
    if(operator=='-'){
        if(c>b)
        {
            while(c>b){
                b+=15;
            }
        }
    }
    printf("%d %c %d = ",b,operator,c);
    scanf("%d",&ans);
    t2=time(NULL);
    if(operator=='+'){
       rans=b+c;
    }
    else{
        rans=b-c;
    }
    if(t2-t1>4){
        printf("Time out \nThe answer is %d\n",rans);
        return 0;
    }
    else if(ans==rans){
        printf("Correct answer\n");
        return 1;
        }
    else{
        printf("Wrong answer \nThe correct answer is %d\n",rans);
        return 0;
    }
}
int question2()
{
    char sign[4]={'+','-','*'};
    int a=(rand() % 3);
    time_t t1,t2;
    t1=time(NULL);
    char operator = sign[a];
    int b=35+rand()%70,c=15+rand()%30;
    int ans,rans;
    if(operator=='*'){
       b=4+rand()%14;
        c=2+rand()%9;}
    printf("%d %c %d = ",b,operator,c);
    scanf("%d",&ans);
    t2=time(NULL);
    if(operator=='+'){
       rans=b+c;
    }
    else if(operator=='-'){
        rans=b-c;
        }
    else{
        rans=b*c;
        }
   if(t2-t1>7){
          printf("Time out \nThe answer is %d\n",rans);
        return 0;
    }
        else if(ans==rans){
        printf("Correct answer\n");
        return 1;
        }
    else{
        printf("Wrong answer \nThe correct answer is %d\n",rans);
        return 0;
    }
}
int question3()
{
    char sign[3]={'-','*','/'};
    time_t t1,t2;
    t1=time(NULL);
    int a=(rand() % 3);
    char operator = sign[a];
    int b=20+rand()%60,c=20+rand()%30;
    int ans,rans;
    if(operator=='-'){
        if(c>b)
        {
            while(c>b){
                c+=5;
            }
        }
    }
    if(operator=='*'){
         b=4+rand()%14;
         c=2+rand()%9;}
    if(operator=='/'){
            c=3+rand()%10;
            b=c*(1+rand()%9);
    }
    
    printf("%d %c %d = ",b,operator,c);
    scanf("%d",&ans);
    t2=time(NULL);
    // if(operator=='+'){
    //    rans=b+c;
    // }
     if(operator=='-'){
        rans=b-c;
        }
    else if(operator=='*'){
        rans=b*c;
        }
    else{
        rans=b/c;
        }
    if(t2-t1>9){
       printf("Time out \nThe answer is %d\n",rans);
        return 0;
    }
        else if(ans==rans){
        printf("Correct answer\n");
        return 1;
        }
    else{
        printf("Wrong answer \nThe correct answer is %d\n",rans);
        return 0;
    }
}
int main()
{
    srand(time(0));
    int choice,i,j,s1=0,s2=0,s3=0,total_score=0;
    printf("\n                                          **Guide**   "
    " \n You will be asked some random arithmetic mathematical problems and there will 3 rounds \n where the questions will get slightly harder every round."
    "\n *Questions from round 1 are of 5 points.\n *Questions from round 2 are of 10 points.\n *Questions from round 3 are of 15 points. \n "
    "You will have 4sec for round 1 , 7s for round 2 and 9 for round 3.If you take longer than the limit \n then the point of that question won't be added."
    " After completing all the rounds your total score will\n be calculated based on your correct answers.\n"
     "                                         **Enjoy**");
    while (1) {
        printf("\nPress:\n1 to start game\n2 to end game\n");
        scanf("%d", &choice);

        if (choice == 1) {
            s1 = s2 = s3 = 0; // Reset scores for a new game

            printf("\n..........ROUND 1.........\n");
            for (i = 1; i <= 6; i++) {
                printf("\nQuestion %d:\n", i);
                if (question1()) {
                    s1 += 5;
                }
            }
            printf("\nYour score for Round 1: %d/25\n", s1);

            printf("\n..........ROUND 2.........\n");
            for (i = 1; i <= 7; i++) {
                printf("\nQuestion %d:\n", i);
                if (question2()) {
                    s2 += 10;
                }
            }
            printf("\nYour score for Round 2: %d/70\n", s2);

            printf("\n..........ROUND 3.........\n");
            for (i = 1; i <= 10; i++) {
                printf("\nQuestion %d:\n", i);
                if (question3()) {
                    s3 += 15;
                }
            }
            printf("\nYour score for Round 3: %d/150\n", s3);
            printf("\nYou completed all rounds!\n");
            total_score = s1 + s2 + s3;
            int z=score(total_score);
            if(z==1){
                printf("..........Congratulation you scored new high score.......\n");
                printf("Your new record: %d\n",total_score);
            }
            else{
            printf("Your total score: %d/250\n", total_score);
            printf("Your highscore: %d\n",z);
            }
            printf("Thanks for playing!\n");

        } else {
            printf("\nThanks for playing! Goodbye!\n");
            exit(0);
        }
    }
}

              

                

            
            