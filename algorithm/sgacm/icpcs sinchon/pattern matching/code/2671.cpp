#include <stdio.h>

#define MAX_STATE_NUM 		10
#define MAX_STRING_SIZE 	160

#define START_STATE 		0
#define SINK_STATE 			(MAX_STATE_NUM-1)


char 	input_string[MAX_STRING_SIZE];
int 	cur_state = START_STATE;
int 	transition_table[MAX_STATE_NUM][2] = {
	{6, 1},
	{2, SINK_STATE}, 
	{3, SINK_STATE},
	{3, 4},
	{6, 5},
	{8, 5},
	{SINK_STATE, 7},
	{6, 1},
	{3, 7},
};

int main(){
	transition_table[SINK_STATE][0] = transition_table[SINK_STATE][1] = SINK_STATE;

	scanf("%s", input_string);

	for(int i = 0; input_string[i] != '\0'; i++){
		cur_state = transition_table[cur_state][input_string[i]-'0'];
	}

	if(cur_state == 4 || cur_state == 5 || cur_state == 7){
		puts("SUBMARINE");
	}
	else{
		puts("NOISE");
	}
}