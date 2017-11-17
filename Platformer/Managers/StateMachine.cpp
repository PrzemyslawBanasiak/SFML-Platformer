#include "StateMachine.hpp"
#include "../States/State.hpp"
#include "../States/SplashScreenState.hpp"

#include <memory>


StateMachine::StateMachine() {
}

StateMachine::~StateMachine() {
    
}

void StateMachine::AddState(StateRef state) {
    if (!_states.empty()) {
        _states.top()->Pause();
    }
    
    // store and init the new state
    _states.push(std::move(state));
    _states.top()->Init();
}

void StateMachine::ChangeState(StateRef state) {
    if (!_states.empty()) {
        _states.top()->Cleanup();
        _states.pop();
    }
    
    // store and init the new state
    _states.push(std::move(state));
    _states.top()->Init();
}

void StateMachine::PopState() {
    if (!_states.empty()) {
        _states.top()->Cleanup();
        _states.pop();
    }
    
    if (!_states.empty()) {
        _states.top()->Resume();
    }
}

StateRef& StateMachine::GetActiveState() {
    return _states.top();
}
