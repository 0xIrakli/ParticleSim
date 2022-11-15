#include "raylib.h"

class Particle{   
public:
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;

    float m;

    Particle(int x, int y);

    Particle();

    void ApplyGravityForce(Vector2 force, int mass);

    void Update();

    void Draw();
};