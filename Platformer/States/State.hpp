#pragma once
#include "../GameEngine.hpp"

class State{
public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;
    
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    
    virtual void HandleEvents(Managers& managers) = 0;
    virtual void Update(Managers& managers) = 0;
    virtual void Draw(Managers& managers) = 0;
    
    void ChangeState(Managers& managers, StateRef state);
    
protected:
    State() {}
};
