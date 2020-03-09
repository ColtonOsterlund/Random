#include <SDL.h>
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <Windows.h>
const int FPS = 60;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void typewritting(std::string s, int speed) {
	for (int i = 0; i < s.length(); i++) {
		std::cout << s.at(i); Sleep(speed);
	}
	std::cout << std::endl;
}

class Sprite {
private:
	SDL_Surface * box = NULL;
	SDL_Rect rect;

public:
	Sprite(Uint32 colour, double x, double y, int w, int h) {
		box = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
		SDL_FillRect(box, NULL, colour);

		rect = box->clip_rect;
		rect.x = x;
		rect.y = y;
	}

	~Sprite() {
		SDL_FreeSurface(box);
	}

	void draw(SDL_Surface *destination) {
		SDL_BlitSurface(box, NULL, destination, &rect);
	}
};

void InitializeSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);
}

int runGame() {
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 500, NULL);
	SDL_Surface *surface = NULL;
	SDL_Surface *imageSurfaceA = NULL;
	SDL_Surface *imageSurfaceB = NULL;
	SDL_Surface *imageSurfaceJump = NULL;
	SDL_Surface *imageSurfaceFallenHorse = NULL;
	surface = SDL_GetWindowSurface(window);

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	srand(SDL_GetTicks() * 10000);

	double horseSpeed = 10;
	int PerspectiveCorrectionFactor = horseSpeed / 2;
	int jumptime;
	int jumpscleared = 0;

	int cloudxpositions[] = { 150, 165, 180, 650, 680, 700 };
	int fencexpos[] = { 100, 300, 500, 700, 900 };
	int jumpxpos[10];
	jumpxpos[0] = 1000;
	for (int i = 1; i < 10; i++) {
		jumpxpos[i] = jumpxpos[i - 1] + (rand() % 500 + 500);
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {
			SDL_Delay(300);
		}
		else if (i == 2 || i == 4 || i == 6 || i == 8) {
			SDL_Delay(200);
		}
	}

	//COLOURS
	Uint32 blue = SDL_MapRGB(surface->format, 0, 239, 255);
	Uint32 brown = SDL_MapRGB(surface->format, 100, 50, 0);
	Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
	Uint32 green = SDL_MapRGB(surface->format, 6, 131, 72);
	Uint32 darkBrown = SDL_MapRGB(surface->format, 81, 10, 2);
	Uint32 red = SDL_MapRGB(surface->format, 255, 0, 0);
	Uint32 orange = SDL_MapRGB(surface->format, 255, 155, 0);
	Uint32 yellow = SDL_MapRGB(surface->format, 255, 255, 0);
	Uint32 indigo = SDL_MapRGB(surface->format, 110, 0, 255);
	Uint32 violet = SDL_MapRGB(surface->format, 205, 0, 255);

	Uint32 jumpcolourarray[] = { brown, red, orange, yellow, green, blue, indigo, violet, white };

	Uint32 jumpcolour1 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour2 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour3 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour4 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour5 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour6 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour7 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour8 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour9 = jumpcolourarray[rand() % 8 + 1];
	Uint32 jumpcolour10 = jumpcolourarray[rand() % 8 + 1];

	imageSurfaceA = SDL_LoadBMP("HORSE1.bmp");
	imageSurfaceB = SDL_LoadBMP("HORSE2.bmp");
	imageSurfaceJump = SDL_LoadBMP("HORSEJUMP.bmp");
	imageSurfaceFallenHorse = SDL_LoadBMP("FALLENHORSE.bmp");
	SDL_Rect imagelocation;
	imagelocation.x = 0;
	imagelocation.y = 190;
	SDL_Rect imagejumplocation;
	imagejumplocation.x = 20;
	imagejumplocation.y = 120;
	SDL_Rect FallenHorseLocation;
	FallenHorseLocation.x = 30;
	FallenHorseLocation.y = 250;
	bool imageA = true;
	bool imageB = false;
	bool horsejump = false;
	int imagecounter = 0;

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
				case SDLK_SPACE:
					imageA = false;
					imageB = false;
					horsejump = true;
					jumptime = SDL_GetTicks();
					break;
				}
			}
		}

		//PUT ALL DYNAMIC GAME CODE HERE

		//-----------------------------------------SPRITE DRAWING---------------------------------------------------
		SDL_FillRect(surface, NULL, blue);
		Sprite grass(green, 0, 350, 1000, 150);
		grass.draw(surface);
		Sprite ground(brown, 0, 375, 1000, 100);
		ground.draw(surface);

		Sprite fence[] = {
			*new Sprite(darkBrown, fencexpos[0], 260, 10, 100),
			*new Sprite(darkBrown, fencexpos[1], 260, 10, 100),
			*new Sprite(darkBrown, fencexpos[2], 260, 10, 100),
			*new Sprite(darkBrown, fencexpos[3], 260, 10, 100),
			*new Sprite(darkBrown, fencexpos[4], 260, 10, 100),
			*new Sprite(darkBrown, 0, 260, 1000, 10),
			*new Sprite(darkBrown, 0, 310, 1000, 10)
		};

		Sprite cloud1[] = {
			*new Sprite(white, cloudxpositions[0], 100, 60, 10),
			*new Sprite(white, cloudxpositions[1], 90, 40, 10),
			*new Sprite(white, cloudxpositions[2], 80, 10, 10)
		};

		Sprite cloud2[] = {
			*new Sprite(white, cloudxpositions[3], 200, 120, 30),
			*new Sprite(white, cloudxpositions[4], 170, 60, 30),
			*new Sprite(white, cloudxpositions[5], 150, 20, 20)
		};


		//-------------------------------------------------SPRITE MOVEMENT ------------------------------------------------------
		for (int i = 0; i < 7; i++) {
			fence[i].draw(surface);
		}

		for (int i = 0; i < 5; i++) {
			fencexpos[i] -= horseSpeed;
			if (fencexpos[i] < 0) {
				fencexpos[i] = 1000;
			}
		}

		for (int i = 0; i < 3; i++) {
			cloud1[i].draw(surface);
			cloud2[i].draw(surface);
		}

		for (int i = 0; i < 6; i++) {
			cloudxpositions[i] -= (horseSpeed - PerspectiveCorrectionFactor);
			if (cloudxpositions[i] < 0) {
				cloudxpositions[i] = 1000;
			}
		}

		if (imagecounter % 15 == 0) {
			if (imageA == true && imageB == false && horsejump == false) {
				imageB = true;
				imageA = false;
				horsejump = false;
			}
			else if (imageA == false && imageB == true && horsejump == false) {
				imageA = true;
				imageB = false;
				horsejump = false;
			}
		}
		if (horsejump == true && (SDL_GetTicks() - jumptime) > 450) {
			imageA = true;
			imageB = false;
			horsejump = false;
		}

		if (horsejump == true) {
			SDL_BlitSurface(imageSurfaceJump, NULL, surface, &imagejumplocation);
		}
		else if (imageA == true) {
			SDL_BlitSurface(imageSurfaceA, NULL, surface, &imagelocation);
		}
		else if (imageB == true) {
			SDL_BlitSurface(imageSurfaceB, NULL, surface, &imagelocation);
		}

		imagecounter++;

		Sprite jump[] = {
			*new Sprite(jumpcolour1, jumpxpos[0], 300, 20, 140),
			*new Sprite(jumpcolour2, jumpxpos[1], 300, 20, 140),
			*new Sprite(jumpcolour3, jumpxpos[2], 300, 20, 140),
			*new Sprite(jumpcolour4, jumpxpos[3], 300, 20, 140),
			*new Sprite(jumpcolour5, jumpxpos[4], 300, 20, 140),
			*new Sprite(jumpcolour6, jumpxpos[5], 300, 20, 140),
			*new Sprite(jumpcolour7, jumpxpos[6], 300, 20, 140),
			*new Sprite(jumpcolour8, jumpxpos[7], 300, 20, 140),
			*new Sprite(jumpcolour9, jumpxpos[8], 300, 20, 140),
			*new Sprite(jumpcolour10, jumpxpos[9], 300, 20, 140),
		};

		for (int i = 0; i < 10; i++) {
			jump[i].draw(surface);
			jumpxpos[i] -= horseSpeed;

			if (jumpxpos[i] < 0) {
				jumpxpos[i] = 10000;
				jumpscleared++;
				horseSpeed += 0.1;
			}

			if (jumpxpos[i] <= 250 && jumpxpos[i] >= 30 && horsejump == false) {
				imageA == false;
				imageB == false;
				SDL_FillRect(surface, NULL, blue);
				grass.draw(surface);
				ground.draw(surface);
				for (int i = 0; i < 7; i++) {
					fence[i].draw(surface);
				}
				for (int i = 0; i < 3; i++) {
					cloud1[i].draw(surface);
					cloud2[i].draw(surface);
				}
				for (int i = 0; i < 10; i++) {
					jump[i].draw(surface);
				}
				SDL_BlitSurface(imageSurfaceFallenHorse, NULL, surface, &FallenHorseLocation);
				SDL_UpdateWindowSurface(window);
				SDL_Delay(1500);
				running = false;
			}

			
		}

		SDL_UpdateWindowSurface(window);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}
	return jumpscleared;
}

void quitSDL(int jumpscleared) {
	SDL_Quit();
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	typewritting("Jump hit, you lose", 30);
	std::cout << "You cleared " << jumpscleared << " jumps" << std::endl;
	system("Pause");
}

int main(int argc, char *argv[]) {
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	typewritting("Tap SPACE bar right as horse reaches base of the jump", 30);
	typewritting("If you tap too late, you will run into the jump", 30);
	typewritting("If you tap too early, you will land on top of the jump", 30);
	typewritting("Your horse will speed up after every jump", 30);
	typewritting("Clear as many jumps as possible", 30);
	typewritting("Good Luck", 30);
	system("Pause");
	InitializeSDL();
	int jumpscleared = runGame();
	quitSDL(jumpscleared);

	return 0;
}