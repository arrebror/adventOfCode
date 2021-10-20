#include<iostream>

void star1() {

	  int my_number = { 325489 };

	int innre = { 1 };
	int	layer = { 0 };

		while (innre <= my_number) {
				layer += 1;
				innre += 8 * layer;
				if (innre >= my_number) {
					break;
				};

		};


	std::cout << "Layer   = " << layer << std::endl;
	std::cout << "max value layer   = " << innre << std::endl;

	int count = { 1 };
	int corner_before = { innre };

	while (corner_before >= my_number) {
		corner_before -= 2 * layer;
	}

	std::cout << "corner_before   = " << corner_before << std::endl;
	std::cout << "middle point   = " << corner_before+layer << std::endl;

	std::cout << " Amount of steps  = " << abs(my_number - (corner_before+layer)) + layer  << std::endl;

}

int create_matrix(int** gridp, const int ARR_SIZE) {

	for (int k = 0; k < ARR_SIZE; k++)
	{
		gridp[k] = new int[ARR_SIZE];
	}

	for (int i = 0; i < ARR_SIZE; i++)
	{
		for (int j = 0; j < ARR_SIZE; j++) {
			gridp[i][j] = 0;
		}
	}
	return 0;
}

void star2() {

	const int ARR_SIZE = 400;
	int** gridp = new int*[ARR_SIZE]; 

	create_matrix(gridp, ARR_SIZE);

	int sidey = 1;
	int sidex = 1;
	int sign = 1;
	int x = 100;
	int y = 100;
    int myNumb = 325489;

	gridp[x][y] = { 1 };

	while (gridp[x][y] < myNumb) {

		for (int i = 1; i <= sidex; i++) {
			x += sign;
			gridp[x][y] = gridp[x + 1][y] + gridp[x - 1][y] + gridp[x + 1][y + 1] + gridp[x - 1][y - 1] + gridp[x][y + 1] + gridp[x][y - 1] + gridp[x - 1][y+1] + gridp[x + 1][y - 1];

			if (gridp[x][y] >= myNumb) {
				break;
			}

		}
		if (gridp[x][y] >= myNumb) {
			break;
		}

		for (int j = 1; j <= sidey; j++) {
			y += sign;
			gridp[x][y] = gridp[x + 1][y] + gridp[x - 1][y] + gridp[x + 1][y + 1] + gridp[x - 1][y - 1] + gridp[x][y + 1] + gridp[x][y - 1] + gridp[x - 1][y + 1] + gridp[x + 1][y - 1];

			if (gridp[x][y] > myNumb) {
				break; }
		}

	sidey += 1;
	sidex += 1;
	sign = sign * -1;

	}
	std::cout << " Value = " << gridp[x][y] << std::endl;
	delete[] gridp;
}


int main() {
	// star1();
	star2();
}
