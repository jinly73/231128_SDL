#include "SDL.h" 
#include <iostream>

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main") 

// OS main() -> SDL_main

int SDL_main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING); // 초기화

	SDL_Window* MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 800, 600,
		SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	Uint64 DeltaSeconds = 0();
	Uint64 LastTime = 0();
	SDL_Event MyEvent;
	bool IsRunning = true;
	while (IsRunning) // 화면 계속 띄우게 하기
	{
		DeltaSeconds = SDL_GetTicks64() - LastTime;
		LastTime = SDL_GetTicks64();
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{

		case SDL_QUIT: // 창 닫기
			IsRunning = false;
			break;
		case SDL_KEYDOWN: // esc눌러서 창 닫기
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
		}
		//명령어 죄다 저장 Render = 붓
		SDL_SetRenderDrawColor(MyRenderer, 0x0b, 0x0b, 0x61, 0x00);
		SDL_RenderClear(MyRenderer);

		for (int i = 0; i < 100; ++i)
		{
			int X = rand() % 800;
			int Y = rand() % 600;
			int W = rand() % 200 + 10;
			int H = rand() % 200 + 10;
			SDL_Rect MyRect = { X, Y, W, H };
			SDL_SetRenderDrawColor(MyRenderer, 0xdf, 0x01, 0x01, 0x00); // 화면에 색상 나타내기
			SDL_RenderFillRect(MyRenderer, &MyRect); // 초기화
		}
		SDL_RenderPresent(MyRenderer); // 실행
		
	
	}
	SDL_Quit(); // 종료 (메모리 비우기)
	return 0;

}