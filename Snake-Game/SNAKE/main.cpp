#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
#include <Windows.h>
#include <string>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
bool difficulty = NULL;
int FPS = NULL;
const int scale = 25;

void typewritting(std::string s, int speed) {
	for (int i = 0; i < s.length(); i++) {
		std::cout << s.at(i); Sleep(speed);
	}
	std::cout << std::endl;
}

int SelectDifficulty() {
	std::cout << "Select Difficulty and Press Enter" << std::endl << "1 = Easy" << std::endl << "2 = Hard" << std::endl;
	int diff;
	std::cout << std::endl << "Selection = "; std::cin >> diff;

	if (diff == 1) {

		std::cout << std::endl << "Difficulty = Easy" << std::endl << std::endl;

		difficulty = true;
		FPS = 20;

		typewritting("Collect the red food to grow your snake.", 30);
		typewritting("Avoid eating your own tail or hitting the wall.", 30);
		typewritting("You have 3 lives, you lose 1 life for every section of your tail you bite and everytime you hit the wall.", 30);
		typewritting("You will bounce backwards everytime you hit the wall, so be careful as this will cause you to bite your tail.", 30);
		typewritting("Every 10 seconds a green life will spawn at a random location for a brief period of time.", 30);
		typewritting("Eating this will add 1 life and reset the location of the next spawn.", 30);
		typewritting("Grow your snake as long as you can.", 30);
		std::cout << std::endl;
		system("pause");
		std::cout << std::endl;
		return 1;
	}
	else if (diff == 2) {

		std::cout << "Difficulty = Hard" << std::endl << std::endl;

		difficulty = false;
		FPS = 30;

		typewritting("Collect the red food to grow your snake.", 30);
		typewritting("Avoid eating your own tail or hitting the wall", 30);
		typewritting("You only have 1 life.", 30);
		typewritting("Grow your snake as long as you can", 30);
		std::cout << std::endl;
		system("pause");
		std::cout << std::endl << std::endl;
		return 1;
	}
	else {
		std::cout << "Invalid" << std::endl << std::endl;
		system("pause");
		return 0;
	}
}

void InitializeSDL() {
	//initializes subsystems
	SDL_Init(SDL_INIT_EVERYTHING);
}

class Sprite {
private:
	SDL_Surface * box = NULL;
	SDL_Rect rect;
	int width = 25;
	int height = 25;

public:
	int xpos = NULL;
	int ypos = NULL;
	Sprite(Uint32 colour, double x, double y) {
		box = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
		SDL_FillRect(box, NULL, colour);

		xpos = x;
		ypos = y;

		rect = box->clip_rect;
		rect.x = xpos;
		rect.y = ypos;
	}

	~Sprite() {
		SDL_FreeSurface(box);
	}


	void draw(SDL_Surface *destination) {
		SDL_BlitSurface(box, NULL, destination, &rect);
	}
};

int runGame() {
	//allocate window to memory (pointer)
	SDL_Window *window = NULL;
	//creates window
	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);

	//create surface to colour screen
	SDL_Surface *surface = NULL;
	surface = SDL_GetWindowSurface(window);

	//colours the screen black
	Uint32 black = SDL_MapRGB(surface->format, 0, 0, 0);
	SDL_FillRect(surface, NULL, black);

	Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
	Uint32 red = SDL_MapRGB(surface->format, 255, 0, 0);
	Uint32 green = SDL_MapRGB(surface->format, 0, 255, 0);

	int initialtime = time(0);

	std::srand(std::time(0)); //set a random number so the rand() function works, doesn't make much sense
	int foodx = (rand() % 31) * 25;
	int foody = (rand() % 31) * 25;

	int lifex = (rand() % 31) * 25;
	int lifey = (rand() % 31) * 25;

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	int lives = 3;
	int headx = 400;
	int heady = 400;
	int bodyNum = 1;
	double headxspeed = 0;
	double headyspeed = 0;

	Sprite * body[1023];

	if (difficulty == true) {
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << "Lives = " << lives << std::endl;
	}

	//game loop
	SDL_Event event;
	bool running = true;
	while (running) {

		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_w:
					headxspeed = 0;
					headyspeed = -1;
					break;

				case SDLK_s:
					headxspeed = 0;
					headyspeed = 1;
					break;

				case SDLK_a:
					headxspeed = -1;
					headyspeed = 0;
					break;

				case SDLK_d:
					headxspeed = 1;
					headyspeed = 0;
					break;
				}
			}
		}

		SDL_FillRect(surface, NULL, black);

		//body[0] = new Sprite(white, headx, heady);
		for (int i = bodyNum - 1; i > 0; i--) {
			body[i] = body[i - 1];
		}
		body[0] = new Sprite(white, headx, heady);

		for (int i = 0; i < bodyNum; i++) {
			body[i]->draw(surface);
		}

		Sprite food(red, foodx, foody);
		food.draw(surface);

		if (difficulty == true) {
			if ((time(0) - initialtime) % 10 == 0) {
				Sprite life(green, lifex, lifey);
				life.draw(surface);
				if (headx == lifex && heady == lifey) {
					lives++;
					lifex = (rand() % 31) * 25;
					lifey = (rand() % 31) * 25;
					if (lives == 3) {
						SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					}
					if (lives == 2) {
						SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					}
					else if (lives == 1) {
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					}
					std::cout << "Lives = " << lives << std::endl;
				}
			}


			for (int i = 1; i < bodyNum; i++) {
				if (lives > 1 && headx == body[i]->xpos && heady == body[i]->ypos) {
					lives--;
					if (lives == 2) {
						SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					}
					else if (lives == 1) {
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					}
					std::cout << "Lives = " << lives << std::endl;
				}

				else if (lives == 1 && headx == body[i]->xpos && heady == body[i]->ypos) {
					SDL_Delay(1000);
					return 0;
				}
			}

			if (lives > 1 && headx < 0) {
				headxspeed *= -1;
				lives--;
				if (lives == 2) {
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else if (lives == 1) {
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				std::cout << "Lives = " << lives << std::endl;
			}

			if (lives > 1 && headx > 775) {
				headxspeed *= -1;
				lives--;
				if (lives == 2) {
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else if (lives == 1) {
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				std::cout << "Lives = " << lives << std::endl;
			}

			if (lives > 1 && heady < 0) {
				headyspeed *= -1;
				lives--;
				if (lives == 2) {
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else if (lives == 1) {
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				std::cout << "Lives = " << lives << std::endl;
			}

			if (lives > 1 && heady > 775) {
				headyspeed *= -1;
				lives--;
				if (lives == 2) {
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else if (lives == 1) {
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				std::cout << "Lives = " << lives << std::endl;
			}

			else if (lives == 1 && (headx < 0 || headx > 775 || heady < 0 || heady > 775)) {
				SDL_Delay(1000);
				return 0;
			}
		}

		else if (difficulty == false) {
			for (int i = 1; i < bodyNum; i++) {
				if (headx == body[i]->xpos && heady == body[i]->ypos) {
					SDL_Delay(1000);
					return 0;
				}
			}

			if (headx < 0 || headx > 775 || heady < 0 || heady > 775) {
				SDL_Delay(1000);
				return 0;
			}
		}

		if (headx == foodx && heady == foody) {
			foodx = (rand() % 31) * 25;
			foody = (rand() % 31) * 25;
			Sprite food(red, (foodx), (foody));
			food.draw(surface);
			bodyNum += 1;
		}

		SDL_UpdateWindowSurface(window);

		headx += (headxspeed*scale);
		heady += (headyspeed*scale);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void QuitSDL() {
	SDL_Quit();
}


int main(int argc, char *argv[]) {
	int playGame = SelectDifficulty();
	if (playGame == 1) {
		InitializeSDL();
		runGame();
	}
	QuitSDL();
	return 0;
}