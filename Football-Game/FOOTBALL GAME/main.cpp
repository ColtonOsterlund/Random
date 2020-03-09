#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <Windows.h>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
const int FPS = 60;
const int ScreenResolutionX = GetSystemMetrics(SM_CXSCREEN);
const int ScreenResolutionY = GetSystemMetrics(SM_CYSCREEN);
int GameState = 0; //Changes game state beween MAIN MENU(0), HAIL MARY MODE (1), KICK RETURN MODE(2), EXIT(3)

void MainMenu();
void GameMode1(int downCounter);

class Sprite {
public:
	SDL_Surface * box = NULL;
	SDL_Rect rect;
};

class MenuBlock : public Sprite {
public:
	MenuBlock(Uint32 colour, double w, double h, double x, double y) {
		box = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
		SDL_FillRect(box, NULL, colour);

		rect = box->clip_rect;
		rect.x = x;
		rect.y = y;
	}

	~MenuBlock() {
		SDL_FreeSurface(box);
	}

	void draw(SDL_Surface *destination) {
		SDL_BlitSurface(box, NULL, destination, &rect);
	}
};

void InitializeSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

void GameMode1Restart(int downCounter) {
	downCounter++;
	GameMode1(downCounter);
}

void GameInstructions() {
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "OFFENCE:" << std::endl << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	std::cout << "Use the W & A keys to move your Quarterback up and down to find the right passing lane." << std::endl
		<< "Do not step out of bounds while you are holding the football." << std::endl
		<< "Use the SPACE bar to throw the ball." << std::endl
		<< "If you throw it at one of the defenders, they will intercept it." << std::endl
		<< "After 5 seconds, the defensive lineman will start to rush the Quarterback." << std::endl
		<< "Avoid being sacked while you are holding the ball." << std::endl
		<< "You have 4 downs to throw the ball to your receiver and score a touchdown." << std::endl << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "DEFENSE:" << std::endl << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		/////////////////////////////////////////////////////////////////////// PUT IN DEFENSIVE INSTRUCTIONS
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "KICKOFF:" << std::endl << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		//////////////////////////////////////////////////////////////////////// PUT IN KICKOFF INSTRUCTIONS
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << "KICK RETURN:" << std::endl << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		////////////////////////////////////////////////////////////////////////// PUT IN KICK RETURN INSTRUCTIONS
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	system("Pause");
	system("CLS");
}

void GameMode1(int downCounter) {
	SDL_Window *Gamewindow = SDL_CreateWindow("Main Menu Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenResolutionX, ScreenResolutionY, 0);
	SDL_Renderer * Gamerenderer = SDL_CreateRenderer(Gamewindow, -1, 0);

	SDL_Surface *Gamesurface = SDL_GetWindowSurface(Gamewindow);
	SDL_Surface *FootballFieldBackground = SDL_LoadBMP("Football_Field.bmp");


	SDL_Surface *QuarterbackSurface = SDL_LoadBMP("quarterback_image2.bmp");
	SDL_Rect QuarterbackRect;
	QuarterbackRect.x = ScreenResolutionX / 4;
	QuarterbackRect.h = ScreenResolutionY / 10;
	QuarterbackRect.w = ScreenResolutionX / 15;
	QuarterbackRect.y = ScreenResolutionY / 2;

	SDL_Surface *FootballSurface = SDL_LoadBMP("football_image.bmp");
	SDL_Rect FootballRect;
	FootballRect.x = ScreenResolutionX / 3.8;
	FootballRect.h = ScreenResolutionY / 40;
	FootballRect.w = ScreenResolutionX / 60;
	FootballRect.y = ScreenResolutionY / 1.94;

	SDL_Surface *RunningReceiverSurface = SDL_LoadBMP("running_receiver.bmp");
	SDL_Rect ReceiverRect;
	ReceiverRect.x = ScreenResolutionX / 1.125;
	ReceiverRect.h = ScreenResolutionY / 10;
	ReceiverRect.w = ScreenResolutionX / 15;
	ReceiverRect.y = ScreenResolutionY / 1.95;

	SDL_Surface *CatchingReceiverSurface = SDL_LoadBMP("catching_receiver.bmp");
	SDL_Rect ReceiverRect2;
	ReceiverRect2.x = ScreenResolutionX / 1.1;
	ReceiverRect2.h = ScreenResolutionY / 14;
	ReceiverRect2.w = ScreenResolutionX / 21;

	SDL_Surface *Defender1Surface = SDL_LoadBMP("defensive_back.bmp");
	SDL_Rect Defender1Rect;
	Defender1Rect.x = (ScreenResolutionX / 8) * 4;
	Defender1Rect.y = (ScreenResolutionY / 5) * 2;
	Defender1Rect.h = ScreenResolutionY / 10;
	Defender1Rect.w = ScreenResolutionX / 15;

	SDL_Surface *Defender2Surface = SDL_LoadBMP("defensive_back.bmp");
	SDL_Rect Defender2Rect;
	Defender2Rect.x = (ScreenResolutionX / 8) * 5;
	Defender2Rect.y = (ScreenResolutionY / 5) * 3;
	Defender2Rect.h = ScreenResolutionY / 10;
	Defender2Rect.w = ScreenResolutionX / 15;

	SDL_Surface *Defender3Surface = SDL_LoadBMP("defensive_back.bmp");
	SDL_Rect Defender3Rect;
	Defender3Rect.x = (ScreenResolutionX / 8) * 6;
	Defender3Rect.y = (ScreenResolutionY / 5) * 4;
	Defender3Rect.h = ScreenResolutionY / 10;
	Defender3Rect.w = ScreenResolutionX / 15;

	SDL_Surface *Defender4Surface = SDL_LoadBMP("defensive_back.bmp");
	SDL_Rect Defender4Rect;
	Defender4Rect.x = (ScreenResolutionX / 8) * 3;
	Defender4Rect.y = ScreenResolutionY / 2;
	Defender4Rect.h = ScreenResolutionY / 10;
	Defender4Rect.w = ScreenResolutionX / 15;

	SDL_Surface *InterceptionSurface = SDL_LoadBMP("interception_image.bmp");
	SDL_Rect InterceptionRect;
	InterceptionRect.h = ScreenResolutionY / 6;
	InterceptionRect.w = ScreenResolutionX / 9;

	SDL_Surface *TackleSurface = SDL_LoadBMP("quarterback_tackle.bmp");
	SDL_Rect TackleRect;
	TackleRect.h = ScreenResolutionY / 10;
	TackleRect.w = ScreenResolutionX / 15;

	SDL_Color sdl_Red = { 255, 0, 0 };
	SDL_Color sdl_Blue = { 0, 0, 255 };

	TTF_Font *font1 = TTF_OpenFont("SF_Collegiate.ttf", 50);
	SDL_Surface *outofbounds = TTF_RenderText_Solid(font1, "OUT OF BOUNDS", sdl_Red);
	SDL_Rect textRect1;
	textRect1.x = ScreenResolutionX * 0.1;
	textRect1.y = ScreenResolutionY * 0.3;
	textRect1.w = ScreenResolutionX * 0.8;
	textRect1.h = ScreenResolutionY * 0.4;

	SDL_Surface *firstdown = TTF_RenderText_Solid(font1, "1ST DOWN", sdl_Red);
	SDL_Rect downRect;
	downRect.x = ScreenResolutionX * 0.015;
	downRect.y = ScreenResolutionY * 0.01;
	downRect.w = ScreenResolutionX * 0.1;
	downRect.h = ScreenResolutionY * 0.075;
	
	SDL_Surface *seconddown = TTF_RenderText_Solid(font1, "2ND DOWN", sdl_Red);
	//uses downRect

	SDL_Surface *thirddown = TTF_RenderText_Solid(font1, "3RD DOWN", sdl_Red);
	//uses downRect

	SDL_Surface *fourthdown = TTF_RenderText_Solid(font1, "4TH DOWN", sdl_Red);
	//uses downRect

	SDL_Surface *incomplete = TTF_RenderText_Solid(font1, "INCOMPLETE", sdl_Red);
	//USES textRect1

	SDL_Surface *touchdown = TTF_RenderText_Solid(font1, "TOUCHDOWN", sdl_Blue);
	//USES textRect1

	SDL_Surface *sacked = TTF_RenderText_Solid(font1, "SACKED", sdl_Red);
	//USES textRect1

	SDL_Surface *interception = TTF_RenderText_Solid(font1, "INTERCEPTION", sdl_Red);
	//USES textRect1

	SDL_Surface *tod = TTF_RenderText_Solid(font1, "TURNOVER", sdl_Red);
	//USES textRect1

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	srand(SDL_GetTicks() * 1000);

	int QByMovement = 0;
	int RECEIVERyMovement = (rand() % (((ScreenResolutionY / 75) - (ScreenResolutionY / 125)) + 1) + (ScreenResolutionY / 125));

	int DefYMovement[3];
	int DefRusherMovementX = 0;
	int DefRusherMovementY = 0;
	bool rushing = false;
	double Xcorrection = ScreenResolutionX * 0.00001;
	double Ycorrection = ScreenResolutionY * 0.00001;
	int rushCountdown = SDL_GetTicks();

	for (int i = 0; i < 3; i++) {
		DefYMovement[i] = rand() % (2 * (ScreenResolutionY / 75)) + (-ScreenResolutionY / 75);
		SDL_Delay(1000);
	}

	bool ballthrown = false;
	int numberofballs = 1;
	int BALLyPOS = NULL;
	int footballXMovement = 0;

	bool running = true;
	SDL_Event event;

	while (running) {
		frameStart = SDL_GetTicks();

		SDL_Texture * Football_Field_Image_Texture = SDL_CreateTextureFromSurface(Gamerenderer, FootballFieldBackground);
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_w:
					QByMovement = -(ScreenResolutionY / 100);
					break;
				case SDLK_s:
					QByMovement = ScreenResolutionY / 100;
					break;
				case SDLK_SPACE:
					ballthrown = true;
					numberofballs--;
					if (numberofballs == 0) {
						BALLyPOS = QuarterbackRect.y;
					}
					footballXMovement = ScreenResolutionX / 100;
					break;
				}
			}
			if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_w:
					QByMovement = 0;
					break;
				case SDLK_s:
					QByMovement = 0;
					break;
				}
			}
		}

		ReceiverRect.y += RECEIVERyMovement;
		if (ReceiverRect.y < ScreenResolutionY * 0.06 || ReceiverRect.y > ScreenResolutionY * 0.825) {
			RECEIVERyMovement *= -1;
		}

		Defender1Rect.y += DefYMovement[0];
		Defender2Rect.y += DefYMovement[1];
		Defender3Rect.y += DefYMovement[2];

		if (Defender1Rect.y < ScreenResolutionY * 0.06 || Defender1Rect.y > ScreenResolutionY * 0.825) {
			DefYMovement[0] *= -1;
		}
		if (Defender2Rect.y < ScreenResolutionY * 0.06 || Defender2Rect.y > ScreenResolutionY * 0.825) {
			DefYMovement[1] *= -1;
		}
		if (Defender3Rect.y < ScreenResolutionY * 0.06 || Defender3Rect.y > ScreenResolutionY * 0.825) {
			DefYMovement[2] *= -1;
		}

		QuarterbackRect.y += QByMovement;

		SDL_Texture * QuarterbackTexture = SDL_CreateTextureFromSurface(Gamerenderer, QuarterbackSurface);

		SDL_Texture * ReceiverRunningTexture = SDL_CreateTextureFromSurface(Gamerenderer, RunningReceiverSurface);

		SDL_Texture *FootballTexture = SDL_CreateTextureFromSurface(Gamerenderer, FootballSurface);

		SDL_Texture *Defender1Texture = SDL_CreateTextureFromSurface(Gamerenderer, Defender1Surface);
		SDL_Texture *Defender2Texture = SDL_CreateTextureFromSurface(Gamerenderer, Defender2Surface);
		SDL_Texture *Defender3Texture = SDL_CreateTextureFromSurface(Gamerenderer, Defender3Surface);
		SDL_Texture *Defender4Texture = SDL_CreateTextureFromSurface(Gamerenderer, Defender4Surface);
		
		if (ballthrown == false) {
			FootballRect.y += QByMovement;
		}

		if (ballthrown == true) {
			FootballRect.y == BALLyPOS;
			FootballRect.x += footballXMovement;
		}

		if ((SDL_GetTicks() - rushCountdown) > 8000 && rushing == false) {
			DefRusherMovementX = (QuarterbackRect.x - Defender4Rect.x) * Xcorrection * 2;
			DefRusherMovementY = (QuarterbackRect.y - Defender4Rect.y) * Ycorrection * 2;
			rushing = true;
		}

		Defender4Rect.x += DefRusherMovementX;
		Defender4Rect.y += DefRusherMovementY;

		if (Defender4Rect.y < ScreenResolutionY * 0.08 || Defender4Rect.y > ScreenResolutionY * 0.82) {
			DefRusherMovementX = (QuarterbackRect.x - Defender4Rect.x) * Xcorrection * 2;
			DefRusherMovementY = (QuarterbackRect.y - Defender4Rect.y) * Ycorrection * 2;
		}
		if (Defender4Rect.x < ScreenResolutionX * 0.1 || Defender4Rect.x > ScreenResolutionX * 0.4) {
			DefRusherMovementX = (QuarterbackRect.x - Defender4Rect.x) * Xcorrection * 2;
			DefRusherMovementY = (QuarterbackRect.y - Defender4Rect.y) * Ycorrection * 2;
		}

		SDL_Texture *DownMarker_Texture = NULL;
		if (downCounter == 1) {
			DownMarker_Texture = SDL_CreateTextureFromSurface(Gamerenderer, firstdown);
		}
		if (downCounter == 2) {
			DownMarker_Texture = SDL_CreateTextureFromSurface(Gamerenderer, seconddown);
		}
		if (downCounter == 3) {
			DownMarker_Texture = SDL_CreateTextureFromSurface(Gamerenderer, thirddown);
		}
		if (downCounter == 4) {
			DownMarker_Texture = SDL_CreateTextureFromSurface(Gamerenderer, fourthdown);
		}

		if (ballthrown == false && (Defender4Rect.x  + (Defender4Rect.w / 2)) > QuarterbackRect.x && (Defender4Rect.x + (Defender4Rect.w / 2)) < (QuarterbackRect.x + QuarterbackRect.w)) {
			if ((Defender4Rect.y + (Defender4Rect.h / 2)) > QuarterbackRect.y && (Defender4Rect.y + (Defender4Rect.h / 2)) < (QuarterbackRect.y + QuarterbackRect.h)) {
				TackleRect.x = QuarterbackRect.x;
				TackleRect.y = QuarterbackRect.y;
				SDL_Texture *Tackle_Texture = SDL_CreateTextureFromSurface(Gamerenderer, TackleSurface);
				SDL_Texture *Sacked_Texture = SDL_CreateTextureFromSurface(Gamerenderer, sacked);
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
				SDL_RenderCopy(Gamerenderer, Tackle_Texture, NULL, &TackleRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(1000);

				SDL_RenderCopy(Gamerenderer, Sacked_Texture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);
				
				if (downCounter == 4) {
					SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
					SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
					SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
					SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
					SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
					SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
					SDL_RenderCopy(Gamerenderer, Defender4Texture, NULL, &Defender4Rect);
					SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
					SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
					SDL_Texture *TOD_Texture = SDL_CreateTextureFromSurface(Gamerenderer, tod);
					SDL_RenderCopy(Gamerenderer, TOD_Texture, NULL, &textRect1);
					SDL_RenderPresent(Gamerenderer);

					SDL_Delay(2000);

					SDL_DestroyTexture(TOD_Texture);
					GameState = 0;
				}

				SDL_DestroyTexture(Football_Field_Image_Texture);
				SDL_DestroyTexture(QuarterbackTexture);
				SDL_DestroyTexture(ReceiverRunningTexture);
				SDL_DestroyTexture(FootballTexture);
				SDL_DestroyTexture(Tackle_Texture);
				SDL_DestroyTexture(Defender1Texture);
				SDL_DestroyTexture(Defender2Texture);
				SDL_DestroyTexture(Defender3Texture);
				SDL_DestroyTexture(Defender4Texture);
				SDL_DestroyTexture(Sacked_Texture);
				SDL_DestroyTexture(DownMarker_Texture);
				if (downCounter < 4) {
					GameState = 1;
				}
				break;
			}
		}

		if ((FootballRect.x + (FootballRect.w / 2)) > ReceiverRect.x && (FootballRect.x + (FootballRect.w / 2)) < (ReceiverRect.x + ReceiverRect.w)) {
			if ((FootballRect.y + (FootballRect.h / 2)) > ReceiverRect.y && (FootballRect.y + (FootballRect.h / 2)) < (ReceiverRect.y + ReceiverRect.h)) {
				SDL_Texture * ReceiverCatchingTexture = SDL_CreateTextureFromSurface(Gamerenderer, CatchingReceiverSurface);
				SDL_Texture * TouchdownTexture = SDL_CreateTextureFromSurface(Gamerenderer, touchdown);
				ReceiverRect2.y = FootballRect.y;
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender4Rect);
				SDL_RenderCopy(Gamerenderer, ReceiverCatchingTexture, NULL, &ReceiverRect2);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(1000);

				SDL_RenderCopy(Gamerenderer, TouchdownTexture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(Football_Field_Image_Texture);
				SDL_DestroyTexture(QuarterbackTexture);
				SDL_DestroyTexture(ReceiverRunningTexture);
				SDL_DestroyTexture(ReceiverCatchingTexture);
				SDL_DestroyTexture(TouchdownTexture);
				SDL_DestroyTexture(Defender1Texture);
				SDL_DestroyTexture(Defender2Texture);
				SDL_DestroyTexture(Defender3Texture);
				SDL_DestroyTexture(Defender4Texture);
				SDL_DestroyTexture(DownMarker_Texture);
				GameState = 0;
				break;
			}
		}

		if ((FootballRect.x + (FootballRect.w / 2)) > Defender1Rect.x && (FootballRect.x + (FootballRect.w / 2)) < (Defender1Rect.x + Defender1Rect.w)) {
			if ((FootballRect.y + (FootballRect.h / 2)) > Defender1Rect.y && (FootballRect.y + (FootballRect.h / 2)) < (Defender1Rect.y + ReceiverRect.h)) {
				InterceptionRect.x = Defender1Rect.x;
				InterceptionRect.y = Defender1Rect.y;
				SDL_Texture * InterceptionTexture = SDL_CreateTextureFromSurface(Gamerenderer, InterceptionSurface);
				SDL_Texture * InterceptionTextTexture = SDL_CreateTextureFromSurface(Gamerenderer, interception);
				ReceiverRect2.y = FootballRect.y;
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender4Rect);
				SDL_RenderCopy(Gamerenderer, InterceptionTexture, NULL, &InterceptionRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(1000);

				SDL_RenderCopy(Gamerenderer, InterceptionTextTexture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(Football_Field_Image_Texture);
				SDL_DestroyTexture(QuarterbackTexture);
				SDL_DestroyTexture(ReceiverRunningTexture);
				SDL_DestroyTexture(InterceptionTexture);
				SDL_DestroyTexture(InterceptionTextTexture);
				SDL_DestroyTexture(Defender1Texture);
				SDL_DestroyTexture(Defender2Texture);
				SDL_DestroyTexture(Defender3Texture);
				SDL_DestroyTexture(Defender4Texture);
				SDL_DestroyTexture(DownMarker_Texture);
				GameState = 0;
				break;

			}
		}
		if ((FootballRect.x + (FootballRect.w / 2)) > Defender2Rect.x && (FootballRect.x + (FootballRect.w / 2)) < (Defender2Rect.x + Defender2Rect.w)) {
			if ((FootballRect.y + (FootballRect.h / 2)) > Defender2Rect.y && (FootballRect.y + (FootballRect.h / 2)) < (Defender2Rect.y + Defender2Rect.h)) {
				InterceptionRect.x = Defender2Rect.x;
				InterceptionRect.y = Defender2Rect.y;
				SDL_Texture * InterceptionTexture = SDL_CreateTextureFromSurface(Gamerenderer, InterceptionSurface);
				SDL_Texture * InterceptionTextTexture = SDL_CreateTextureFromSurface(Gamerenderer, interception);
				ReceiverRect2.y = FootballRect.y;
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender4Rect);
				SDL_RenderCopy(Gamerenderer, InterceptionTexture, NULL, &InterceptionRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(1000);

				SDL_RenderCopy(Gamerenderer, InterceptionTextTexture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(Football_Field_Image_Texture);
				SDL_DestroyTexture(QuarterbackTexture);
				SDL_DestroyTexture(ReceiverRunningTexture);
				SDL_DestroyTexture(InterceptionTexture);
				SDL_DestroyTexture(InterceptionTextTexture);
				SDL_DestroyTexture(Defender1Texture);
				SDL_DestroyTexture(Defender2Texture);
				SDL_DestroyTexture(Defender3Texture);
				SDL_DestroyTexture(Defender4Texture);
				SDL_DestroyTexture(DownMarker_Texture);
				GameState = 0;
				break;

			}
		}
		if ((FootballRect.x + (FootballRect.w / 2)) > Defender3Rect.x && (FootballRect.x + (FootballRect.w / 2)) < (Defender3Rect.x + Defender3Rect.w)) {
			if ((FootballRect.y + (FootballRect.h / 2)) > Defender3Rect.y && (FootballRect.y + (FootballRect.h / 2)) < (Defender3Rect.y + Defender3Rect.h)) {
				InterceptionRect.x = Defender3Rect.x;
				InterceptionRect.y = Defender3Rect.y;
				SDL_Texture * InterceptionTexture = SDL_CreateTextureFromSurface(Gamerenderer, InterceptionSurface);
				SDL_Texture * InterceptionTextTexture = SDL_CreateTextureFromSurface(Gamerenderer, interception);
				ReceiverRect2.y = FootballRect.y;
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender4Rect);
				SDL_RenderCopy(Gamerenderer, InterceptionTexture, NULL, &InterceptionRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(1000);

				SDL_RenderCopy(Gamerenderer, InterceptionTextTexture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(Football_Field_Image_Texture);
				SDL_DestroyTexture(QuarterbackTexture);
				SDL_DestroyTexture(ReceiverRunningTexture);
				SDL_DestroyTexture(InterceptionTexture);
				SDL_DestroyTexture(InterceptionTextTexture);
				SDL_DestroyTexture(Defender1Texture);
				SDL_DestroyTexture(Defender2Texture);
				SDL_DestroyTexture(Defender3Texture);
				SDL_DestroyTexture(Defender4Texture);
				SDL_DestroyTexture(DownMarker_Texture);
				GameState = 0;
				break;

			}
		}
		if (ballthrown == true && (FootballRect.x + (FootballRect.w / 2)) > Defender4Rect.x && (FootballRect.x + (FootballRect.w / 2)) < (Defender4Rect.x + Defender4Rect.w)) {
			if ((FootballRect.y + (FootballRect.h / 2)) > Defender4Rect.y && (FootballRect.y + (FootballRect.h / 2)) < (Defender4Rect.y + Defender4Rect.h)) {
				InterceptionRect.x = Defender4Rect.x;
				InterceptionRect.y = Defender4Rect.y;
				SDL_Texture * InterceptionTexture = SDL_CreateTextureFromSurface(Gamerenderer, InterceptionSurface);
				SDL_Texture * InterceptionTextTexture = SDL_CreateTextureFromSurface(Gamerenderer, interception);
				ReceiverRect2.y = FootballRect.y;
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, InterceptionTexture, NULL, &InterceptionRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(1000);

				SDL_RenderCopy(Gamerenderer, InterceptionTextTexture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(Football_Field_Image_Texture);
				SDL_DestroyTexture(QuarterbackTexture);
				SDL_DestroyTexture(ReceiverRunningTexture);
				SDL_DestroyTexture(InterceptionTexture);
				SDL_DestroyTexture(InterceptionTextTexture);
				SDL_DestroyTexture(Defender1Texture);
				SDL_DestroyTexture(Defender2Texture);
				SDL_DestroyTexture(Defender3Texture);
				SDL_DestroyTexture(Defender4Texture);
				SDL_DestroyTexture(DownMarker_Texture);
				GameState = 0;
				break;

			}
		}
		if (FootballRect.x > ScreenResolutionX * 0.95) {
			SDL_Texture *Incomplete_Texture = SDL_CreateTextureFromSurface(Gamerenderer, incomplete);
			SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
			SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
			SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
			SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
			SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
			SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
			SDL_RenderCopy(Gamerenderer, Defender4Texture, NULL, &Defender4Rect);
			SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
			SDL_RenderCopy(Gamerenderer, Incomplete_Texture, NULL, &textRect1);
			SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
			SDL_RenderPresent(Gamerenderer);

			SDL_Delay(2000);

			if (downCounter == 4) {
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, Defender4Texture, NULL, &Defender4Rect);
				SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_Texture *TOD_Texture = SDL_CreateTextureFromSurface(Gamerenderer, tod);
				SDL_RenderCopy(Gamerenderer, TOD_Texture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(TOD_Texture);
				GameState = 0;
			}

			SDL_DestroyTexture(Football_Field_Image_Texture);
			SDL_DestroyTexture(QuarterbackTexture);
			SDL_DestroyTexture(ReceiverRunningTexture);
			SDL_DestroyTexture(FootballTexture);
			SDL_DestroyTexture(Incomplete_Texture);
			SDL_DestroyTexture(Defender1Texture);
			SDL_DestroyTexture(Defender2Texture);
			SDL_DestroyTexture(Defender3Texture);
			SDL_DestroyTexture(Defender4Texture);
			SDL_DestroyTexture(DownMarker_Texture);
			if (downCounter < 4) {
				GameState = 1;
			}
			break;
		}

		if ((QuarterbackRect.y < ScreenResolutionY * 0.007 || QuarterbackRect.y > ScreenResolutionY * 0.82) && ballthrown == false) {
			SDL_Texture *Out_Of_Bounds_Texture = SDL_CreateTextureFromSurface(Gamerenderer, outofbounds);
			SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
			SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
			SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
			SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
			SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
			SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
			SDL_RenderCopy(Gamerenderer, Defender4Texture, NULL, &Defender4Rect);
			SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
			SDL_RenderCopy(Gamerenderer, Out_Of_Bounds_Texture, NULL, &textRect1);
			SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
			SDL_RenderPresent(Gamerenderer);

			SDL_Delay(2000);

			if (downCounter == 4) {
				SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
				SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
				SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
				SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
				SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
				SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
				SDL_RenderCopy(Gamerenderer, Defender4Texture, NULL, &Defender4Rect);
				SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
				SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
				SDL_Texture *TOD_Texture = SDL_CreateTextureFromSurface(Gamerenderer, tod);
				SDL_RenderCopy(Gamerenderer, TOD_Texture, NULL, &textRect1);
				SDL_RenderPresent(Gamerenderer);

				SDL_Delay(2000);

				SDL_DestroyTexture(TOD_Texture);
				GameState = 0;
			}

			SDL_DestroyTexture(Football_Field_Image_Texture);
			SDL_DestroyTexture(QuarterbackTexture);
			SDL_DestroyTexture(ReceiverRunningTexture);
			SDL_DestroyTexture(FootballTexture);
			SDL_DestroyTexture(Out_Of_Bounds_Texture);
			SDL_DestroyTexture(Defender1Texture);
			SDL_DestroyTexture(Defender2Texture);
			SDL_DestroyTexture(Defender3Texture);
			SDL_DestroyTexture(Defender4Texture);
			SDL_DestroyTexture(DownMarker_Texture);
			if (downCounter < 4) {
				GameState = 1;
			}
			break;
		}

		SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);
		SDL_RenderCopy(Gamerenderer, QuarterbackTexture, NULL, &QuarterbackRect);
		SDL_RenderCopy(Gamerenderer, Defender1Texture, NULL, &Defender1Rect);
		SDL_RenderCopy(Gamerenderer, Defender2Texture, NULL, &Defender2Rect);
		SDL_RenderCopy(Gamerenderer, Defender3Texture, NULL, &Defender3Rect);
		SDL_RenderCopy(Gamerenderer, Defender4Texture, NULL, &Defender4Rect);
		SDL_RenderCopy(Gamerenderer, ReceiverRunningTexture, NULL, &ReceiverRect);
		SDL_RenderCopy(Gamerenderer, FootballTexture, NULL, &FootballRect);
		SDL_RenderCopy(Gamerenderer, DownMarker_Texture, NULL, &downRect);
		SDL_RenderPresent(Gamerenderer);

		SDL_DestroyTexture(Football_Field_Image_Texture);
		SDL_DestroyTexture(QuarterbackTexture);
		SDL_DestroyTexture(ReceiverRunningTexture);
		SDL_DestroyTexture(FootballTexture);
		SDL_DestroyTexture(Defender1Texture);
		SDL_DestroyTexture(Defender2Texture);
		SDL_DestroyTexture(Defender3Texture);
		SDL_DestroyTexture(Defender4Texture);
		SDL_DestroyTexture(DownMarker_Texture);
		SDL_RenderClear(Gamerenderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	TTF_CloseFont(font1);
	SDL_FreeSurface(Gamesurface);
	SDL_FreeSurface(FootballFieldBackground);
	SDL_FreeSurface(QuarterbackSurface);
	SDL_FreeSurface(RunningReceiverSurface);
	SDL_FreeSurface(CatchingReceiverSurface);
	SDL_FreeSurface(outofbounds);
	SDL_FreeSurface(incomplete);
	SDL_FreeSurface(touchdown);
	SDL_FreeSurface(Defender1Surface);
	SDL_FreeSurface(Defender2Surface);
	SDL_FreeSurface(Defender3Surface);
	SDL_FreeSurface(Defender4Surface);
	SDL_FreeSurface(InterceptionSurface);
	SDL_FreeSurface(TackleSurface);
	SDL_FreeSurface(sacked);
	SDL_FreeSurface(interception);
	SDL_FreeSurface(firstdown);
	SDL_FreeSurface(seconddown);
	SDL_FreeSurface(thirddown);
	SDL_FreeSurface(fourthdown);
	SDL_FreeSurface(tod);
	SDL_DestroyWindow(Gamewindow);

	if (GameState == 0) {
		MainMenu();
	}
	else if (GameState == 1) {
		GameMode1Restart(downCounter);
	}
}

void GameMode2(int downCounter) {
	SDL_Window *Gamewindow = SDL_CreateWindow("Main Menu Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenResolutionX, ScreenResolutionY, 0);
	SDL_Surface *Gamesurface = SDL_GetWindowSurface(Gamewindow);
	SDL_Surface *FootballFieldBackground = SDL_LoadBMP("Football_Field.bmp");

	SDL_Renderer * Gamerenderer = SDL_CreateRenderer(Gamewindow, -1, 0);
	SDL_Texture * Football_Field_Image_Texture = SDL_CreateTextureFromSurface(Gamerenderer, FootballFieldBackground);
	SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	SDL_Color sdl_Red = { 255, 0, 0 };

	TTF_Font *font1 = TTF_OpenFont("SF_Collegiate.ttf", 50);
	SDL_Surface *comingsoon = TTF_RenderText_Solid(font1, "COMING SOON", sdl_Red);
	SDL_Rect textRect;
	textRect.x = ScreenResolutionX * 0.1;
	textRect.y = ScreenResolutionY * 0.3;
	textRect.w = ScreenResolutionX * 0.8;
	textRect.h = ScreenResolutionY * 0.4;

	SDL_Texture *comingsoonTexture = SDL_CreateTextureFromSurface(Gamerenderer, comingsoon);
	SDL_RenderCopy(Gamerenderer, comingsoonTexture, NULL, &textRect);
	SDL_RenderPresent(Gamerenderer);

	bool running = true;
	SDL_Event event;

	while (running) {
		frameStart = SDL_GetTicks();

		SDL_Texture * Football_Field_Image_Texture = SDL_CreateTextureFromSurface(Gamerenderer, FootballFieldBackground);

		while (SDL_PollEvent(&event)) {
			//EVENT HANDLING HERE
		}


		//DYNAMIC GAME CODE HERE



		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyTexture(Football_Field_Image_Texture);
	SDL_DestroyTexture(comingsoonTexture);
	SDL_DestroyRenderer(Gamerenderer);
	SDL_FreeSurface(Gamesurface);
	SDL_FreeSurface(FootballFieldBackground);
	SDL_FreeSurface(comingsoon);
	TTF_CloseFont(font1);
	SDL_DestroyWindow(Gamewindow);
}

void GameMode3(int downCounter) {
	SDL_Window *Gamewindow = SDL_CreateWindow("Main Menu Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenResolutionX, ScreenResolutionY, 0);
	SDL_Surface *Gamesurface = SDL_GetWindowSurface(Gamewindow);
	SDL_Surface *FootballFieldBackground = SDL_LoadBMP("Football_Field.bmp");

	SDL_Renderer * Gamerenderer = SDL_CreateRenderer(Gamewindow, -1, 0);
	SDL_Texture * Football_Field_Image_Texture = SDL_CreateTextureFromSurface(Gamerenderer, FootballFieldBackground);
	SDL_RenderCopy(Gamerenderer, Football_Field_Image_Texture, NULL, NULL);

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	SDL_Color sdl_Red = { 255, 0, 0 };

	TTF_Font *font1 = TTF_OpenFont("SF_Collegiate.ttf", 50);
	SDL_Surface *comingsoon = TTF_RenderText_Solid(font1, "COMING SOON", sdl_Red);
	SDL_Rect textRect;
	textRect.x = ScreenResolutionX * 0.1;
	textRect.y = ScreenResolutionY * 0.3;
	textRect.w = ScreenResolutionX * 0.8;
	textRect.h = ScreenResolutionY * 0.4;

	SDL_Texture *comingsoonTexture = SDL_CreateTextureFromSurface(Gamerenderer, comingsoon);
	SDL_RenderCopy(Gamerenderer, comingsoonTexture, NULL, &textRect);

	SDL_RenderPresent(Gamerenderer);

	bool running = true;
	SDL_Event event;

	while (running) {
		frameStart = SDL_GetTicks();

		SDL_Texture * Football_Field_Image_Texture = SDL_CreateTextureFromSurface(Gamerenderer, FootballFieldBackground);

		while (SDL_PollEvent(&event)) {
			//EVENT HANDLING HERE
		}


		//DYNAMIC GAME CODE HERE



		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyTexture(Football_Field_Image_Texture);
	SDL_DestroyRenderer(Gamerenderer);
	SDL_FreeSurface(Gamesurface);
	SDL_FreeSurface(FootballFieldBackground);
	SDL_FreeSurface(comingsoon);
	TTF_CloseFont(font1);
	SDL_DestroyWindow(Gamewindow);
}

void MainMenuRestart() {
	MainMenu();
}

void MainMenu() {
	SDL_Window *window = SDL_CreateWindow("Main Menu Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenResolutionX, ScreenResolutionY, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	SDL_Surface *imageSurfaceBackground = SDL_LoadBMP("main_menu_background.bmp");

	Uint32 black = SDL_MapRGB(imageSurfaceBackground->format, 0, 0, 0);
	Uint32 white = SDL_MapRGB(imageSurfaceBackground->format, 255, 255, 255);
	Uint32 red = SDL_MapRGB(imageSurfaceBackground->format, 255, 0, 0);
	Uint32 green = SDL_MapRGB(imageSurfaceBackground->format, 0, 255, 0);

	SDL_Color sdl_Black = { 0, 0, 0 }; //USED FOR TRUE TYPE FONT TEXT RENDERER
	SDL_Color sdl_White = { 255, 255, 255 }; //USED FOR TRUE TYPE FONT TEXT RENDERER

	TTF_Font *font2 = TTF_OpenFont("SF_Collegiate.ttf", 50);
	SDL_Surface *fontSurface2 = TTF_RenderText_Solid(font2, "KICK-OFF", sdl_White);
	SDL_Rect textRect2;
	textRect2.x = ScreenResolutionX * 0.12;
	textRect2.y = ScreenResolutionY * 0.48;
	textRect2.w = ScreenResolutionX * 0.26;
	textRect2.h = ScreenResolutionY * 0.06;

	TTF_Font *font1 = TTF_OpenFont("SF_Collegiate.ttf", 50);
	SDL_Surface *fontSurface1 = TTF_RenderText_Solid(font2, "CONTROLS", sdl_White);
	SDL_Rect textRect3;
	textRect3.x = ScreenResolutionX * 0.12;
	textRect3.y = ScreenResolutionY * 0.63;
	textRect3.w = ScreenResolutionX * 0.26;
	textRect3.h = ScreenResolutionY * 0.06;

	TTF_Font *font4 = TTF_OpenFont("SF_Collegiate.ttf", 50);
	SDL_Surface *fontSurface4 = TTF_RenderText_Solid(font4, "EXIT", sdl_White);
	SDL_Rect textRect4;
	textRect4.x = ScreenResolutionX * 0.86;
	textRect4.y = ScreenResolutionY * 0.86;
	textRect4.w = ScreenResolutionX * 0.08;
	textRect4.h = ScreenResolutionY * 0.03;

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Uint32 block_colour1 = red;
	Uint32 block_colour2 = red;
	Uint32 block_colour4 = red;

	int mouseX;
	int mouseY;

	bool running = true;
	SDL_Event event;

	while (running) {
		frameStart = SDL_GetTicks();
	
		SDL_Texture * background_image_texture = SDL_CreateTextureFromSurface(renderer, imageSurfaceBackground);
		SDL_RenderCopy(renderer, background_image_texture, NULL, NULL);

		SDL_GetMouseState(&mouseX, &mouseY);

		if (mouseX > (ScreenResolutionX * 0.1) && mouseX < (ScreenResolutionX * 0.4)) {
			if (mouseY > (ScreenResolutionY * 0.45) && mouseY < (ScreenResolutionY * 0.55)) {
				block_colour1 = red;
				block_colour2 = green;
				block_colour4 = red;
			}
			if (mouseY >(ScreenResolutionY * 0.6) && mouseY < (ScreenResolutionY * 0.7)) {
				block_colour1 = green;
				block_colour2 = red;
				block_colour4 = red;
			}
		}
		else if (mouseX > ScreenResolutionX * 0.85 && mouseX < ScreenResolutionX * 0.95) {
			if (mouseY > (ScreenResolutionY * 0.85) && mouseY < (ScreenResolutionY * 0.9)) {
				block_colour1 = red;
				block_colour2 = red;
				block_colour4 = green;
			}
		}
		else {
			block_colour1 = red;
			block_colour2 = red;
			block_colour4 = red;
		}

		MenuBlock MenuBlock_Instructions(block_colour1, ScreenResolutionX * 0.3, ScreenResolutionY * 0.1, ScreenResolutionX * 0.1, ScreenResolutionY * 0.6);
		MenuBlock MenuBlock_GameMode2(block_colour2, ScreenResolutionX * 0.3, ScreenResolutionY * 0.1, ScreenResolutionX * 0.1, ScreenResolutionY * 0.45);
		MenuBlock MenuBlock_Exit(block_colour4, ScreenResolutionX * 0.1, ScreenResolutionY * 0.05, ScreenResolutionX * 0.85, ScreenResolutionY * 0.85);

		SDL_Texture * MenuBlock_Instructions_Texture = SDL_CreateTextureFromSurface(renderer, MenuBlock_Instructions.box);
		SDL_Texture * MenuBlock_GameMode2_Texture = SDL_CreateTextureFromSurface(renderer, MenuBlock_GameMode2.box);
		SDL_Texture * MenuBlock_Exit_Texture = SDL_CreateTextureFromSurface(renderer, MenuBlock_Exit.box);

		SDL_RenderCopy(renderer, MenuBlock_Instructions_Texture, NULL, &MenuBlock_Instructions.rect);
		SDL_RenderCopy(renderer, MenuBlock_GameMode2_Texture, NULL, &MenuBlock_GameMode2.rect);
		SDL_RenderCopy(renderer, MenuBlock_Exit_Texture, NULL, &MenuBlock_Exit.rect);

		SDL_Texture *Font_Texture1 = SDL_CreateTextureFromSurface(renderer, fontSurface1);
		SDL_RenderCopy(renderer, Font_Texture1, NULL, &textRect3);

		SDL_Texture *Font_Texture2 = SDL_CreateTextureFromSurface(renderer, fontSurface2);
		SDL_RenderCopy(renderer, Font_Texture2, NULL, &textRect2);

		SDL_Texture *Font_Texture4 = SDL_CreateTextureFromSurface(renderer, fontSurface4);
		SDL_RenderCopy(renderer, Font_Texture4, NULL, &textRect4);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					if (event.button.x > (ScreenResolutionX * 0.1) && event.button.x < (ScreenResolutionX * 0.4)) {
						if (event.button.y > (ScreenResolutionY * 0.45) && event.button.y < (ScreenResolutionY * 0.55)) {
							GameState = 1;
							running = false;
						}
						else if (event.button.y >(ScreenResolutionY * 0.6) && event.button.y < (ScreenResolutionY * 0.7)) {
							GameState = 5;
							running = false;
						}
					}
					else if (event.button.x > ScreenResolutionX * 0.85 && event.button.x < ScreenResolutionX * 0.95) {
						if (event.button.y > (ScreenResolutionY * 0.85) && event.button.y < (ScreenResolutionY * 0.9)) {
							GameState = 4;
							running = false;
						}
					}
				}
			}
		}
		SDL_RenderPresent(renderer);

		SDL_DestroyTexture(background_image_texture);
		SDL_DestroyTexture(Font_Texture1);
		SDL_DestroyTexture(Font_Texture2);
		SDL_DestroyTexture(Font_Texture4);
		SDL_DestroyTexture(MenuBlock_Instructions_Texture);
		SDL_DestroyTexture(MenuBlock_GameMode2_Texture);
		SDL_DestroyTexture(MenuBlock_Exit_Texture);
		SDL_RenderClear(renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

		TTF_CloseFont(font1);
		TTF_CloseFont(font2);
		TTF_CloseFont(font4);
		SDL_FreeSurface(surface);
		SDL_FreeSurface(fontSurface1);
		SDL_FreeSurface(fontSurface2);
		SDL_FreeSurface(fontSurface4);
		SDL_FreeSurface(imageSurfaceBackground);
		SDL_DestroyWindow(window);

		if (GameState == 1) {
			GameMode1(1);
		}

		if (GameState == 4) {
			SDL_Quit;
		}
		if (GameState == 5) {
			GameInstructions();
			GameState = 0;
			MainMenuRestart();
		}
}

int main(int argc, char *argv[]) {
	InitializeSDL();
	if (GameState == 0) {
		MainMenu();
	}

	return 0;
}