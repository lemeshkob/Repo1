// ^ ^
//(-_-)

#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "unistd.h"

int run(int moves[], int movesLen, int res[], int resLen);

enum operations { Pop, Push, Break, Repeat, Continue, pustota };

struct Move
{
	enum operations left;//operation
	int right;//state
};
int run(int moves[], int movesLen, int res[], int resLen)
{
    struct Move var;

    var.left = Push;

	int currentState = 0;
	int currentMove;
	int k = 0;
	int i = 0;
	int JhonCena;// cheking break
	int resNumbers = 0;
	struct Move automata[4][4];

	automata[0][0].left = 5;
	automata[0][0].right = 0;
	automata[1][1].left = Pop;
	automata[1][1].right = 2;
	automata[2][2].left = pustota;
	automata[2][2].right = pustota;
	automata[3][3].left = Break;
	automata[3][3].right = Break;
	automata[0][1].left = Pop;
	automata[0][1].right = 1;
	automata[1][0].left = pustota;
	automata[1][0].right = pustota;
	automata[0][2].left = pustota;
	automata[0][2].right = pustota;
	automata[2][0].left = Continue;
	automata[2][0].right = 3;
	automata[0][3].left = 551;
	automata[0][3].right = 1;
	automata[3][0].left = pustota;
	automata[3][0].right = pustota;
	automata[1][2].left = 552;
	automata[1][2].right = 1;
	automata[2][1].left = 555;
	automata[2][1].right = 3;
	automata[1][3].left = Repeat;
	automata[1][3].right = 2;
	automata[3][1].left = pustota;
	automata[3][1].right = pustota;
	automata[2][3].left = pustota;
	automata[2][3].right = pustota;
	automata[3][2].left = 100;
	automata[3][2].right = 0;


	while (1)
	{
		switch (moves[k])
		{
		case 6:
			currentMove = 0;
			break;
		case 18:
			currentMove = 1;
			break;
		case 33:
			currentMove = 2;
			break;
		case 303:
			currentMove = 3;
			break;
		default:
			JhonCena = 1;
			break;
		}
		if (JhonCena == 1)
		{
			break;
		}

		switch (automata[currentState][currentMove].left)
		{
		case Break:
			JhonCena = 1;
			break;
		case Pop:
			if (i>0)
			{
				res[i - 1] = 0;
				i--;
				k++;
				currentState = automata[currentState][currentMove].right;
				break;
			}
			else
			{
				JhonCena = 1;
				break;
			}
		case Repeat:
			currentState = automata[currentState][currentMove].right;
			break;
		case Continue:
			k++;
			currentState = automata[currentState][currentMove].right;
			break;
		default:	//here we have
			res[i] = automata[currentState][currentMove].right;
			i++;
			k++;
			currentState = automata[currentState][currentMove].right;
			break;
		}

		if (JhonCena == 1)
			break;
	}
	for (i = 0; i<resLen; i++)
	{
		if (res[i] != 0)
			resNumbers++;
	}

	return resNumbers;
}

int main(void)
{
	int movesl, resl, i;
	int moves[] = { 6,18,6,33,303 };

	movesl = sizeof(moves) / sizeof(int);
	resl = sizeof(moves) / sizeof(int);

	int res[resl];

	for (i = 0; i < movesl; ++i)
	{
		printf("%d ", moves[i]);
		//sleep ( 4 );
	}

	printf("\n");
	printf("%d ", run(moves, movesl, res, resl));
//	sleep(4);
	printf("\n");
	return 0;

}


