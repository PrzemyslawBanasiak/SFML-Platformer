#pragma once
#include <stack>
#include <memory>

class State;

typedef std::unique_ptr<State> StateRef;

class StateMachine{
public:
    StateMachine();
    ~StateMachine();
    
    void AddState(StateRef state);
    void ChangeState(StateRef state);
    void PopState();
    
    StateRef& GetActiveState();
private:
    std::stack<StateRef> _states;
};
