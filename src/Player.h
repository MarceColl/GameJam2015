
class Player {
public:
    Player();
    ~Player();
    void moveTo(float x, void (*callback)());
    void draw();
};