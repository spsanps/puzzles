#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int scenario(int change) 
{
    // run one game
    
    // select door with car
    int car = rand()%3;
    
    // contestant chooses
    int contestant = rand()%3;
    
    // monty opens a door
    // he cannot show the one with car nor the one contestant choose
    int monty;
    if (car != contestant) {
        monty = 3 - car - contestant;
    } else {
        monty = (car + rand()%2 + 1)%3;
    }
    
    // switch 
    if (change == 1) {
        contestant = 3 - contestant - monty; 
    }
    
    return contestant == car;
}

int main()
{
    int i;
    int samples = 5000;
    int wins = 0;
    
    srand(time(NULL));
    
    // run game without switching 'samples' times
    for(i = 0; i < samples; i++) {
        if (scenario(0)) wins += 1;
    }
    
    printf("Win ratio when not switching: %f \n", (double)wins/samples);
    
    
    // run game with switching 'samples' times
    wins = 0;
    for(i = 0; i < samples; i++) {
        if (scenario(1)) wins += 1;
    }
    
    printf("Win ratio when switching: %f \n", (double)wins/samples);
    

    return 0;
}
