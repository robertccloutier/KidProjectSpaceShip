class Bullet {
    public:
    int speed;
    unsigned int x;
    unsigned int y;
    unsigned int size;
    unsigned int groupID;
};

/*class SpaceShip {
    public:
        unsigned int x;
        unsigned int y;
        int sizeX; //small, medium, large
        int sizeY;
        int maxSpeedX;
        int maxSpeedY;
        unsigned int pv;
        int speedX;
        int speedY;
        unsigned int groupID;
        unsigned int weight;
        unsigned int shootingSpeed;
        Bullet type;
};*/

enum GameType {
    GameCoop = 0,
    Game1vs1 = 1
};

struct ScreenParts {
    int x1; int y1; int x2; int y2;
};

class MainScreen {
    public:
        ScreenParts playerAZone;
        ScreenParts playerBZone;
        ScreenParts enemiZone;
        ScreenParts menu;
};
/*
class GameDraft {
    public:
    GameType     type;
    Player       players[2];
    SpaceShip*   enemis;
    unsigned int enemisCount;
    Bullet*      bullets;
};*/

/*class Player {
    public:
    SpaceShip ship;
    unsigned int score;
    unsigned int pv;
};*/
