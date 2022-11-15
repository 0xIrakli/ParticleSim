#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "particle.h"

using namespace std;

int WIDTH = 1000;
int HEIGHT = 1000;

const int particleCount = 80000;

int main(int, char**) {
    InitWindow(WIDTH, HEIGHT, "Particles");
    vector<Particle> particleArray = vector<Particle>();

    for (int i = 0; i < particleCount; i++) {
        particleArray.push_back(Particle(rand()%WIDTH, rand()%HEIGHT));
    }

    SetTargetFPS(80);
    
    int L = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();

            DrawFPS(5, 5);
            ClearBackground(Color{41, 41, 41, 255});
            for (int i = 0; i < particleCount; i++){
                if (IsMouseButtonDown(0)) {
                    particleArray[i].ApplyGravityForce({(float)GetMouseX(), (float)GetMouseY()}, 1000);
                }
                particleArray[i].Update();
                particleArray[i].Draw();
            }
            if (IsKeyPressed(KEY_A)) {
                TakeScreenshot((to_string(L)+".png").c_str());
                L++;
            }
        
        EndDrawing();
    }
}