#pragma once
struct Managers;

class State{
public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;
    
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    
    virtual void HandleInput() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw(float dt) = 0;
    
protected:
    State() {}
};
