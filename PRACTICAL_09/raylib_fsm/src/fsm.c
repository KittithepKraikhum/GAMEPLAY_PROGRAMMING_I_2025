#include "fsm.h"
#include "gameobject.h"   // For GameObject struct

// ---------------------------------------------------------
// Setup allowed transitions for one state
// ---------------------------------------------------------
void StateTransitions(StateConfig *stateConfig, State *transitions, int count)
{
    stateConfig->nextStates = transitions;
    stateConfig->nextStatesCount = count;
}

// ---------------------------------------------------------
// Can this state transition happen?
// ---------------------------------------------------------
bool CanEnterState(GameObject *obj, State newState)
{
    StateConfig *cfg = &obj->stateConfigs[obj->currentState];

    for (int i = 0; i < cfg->nextStatesCount; i++)
    {
        if (cfg->nextStates[i] == newState)
            return true;
    }

    return false;
}

// ---------------------------------------------------------
// Change to new state
// ---------------------------------------------------------
bool ChangeState(GameObject *obj, State newState, float deltaTime)
{
    if (!CanEnterState(obj, newState))
        return false;

    // EXIT current state
    if (obj->stateConfigs[obj->currentState].Exit)
        obj->stateConfigs[obj->currentState].Exit(obj, deltaTime);

    obj->previousState = obj->currentState;
    obj->currentState = newState;

    // ENTER new state
    if (obj->stateConfigs[newState].Entry)
        obj->stateConfigs[newState].Entry(obj, deltaTime);

    return true;
}

// ---------------------------------------------------------
// Handle an event from current state
// ---------------------------------------------------------
void HandleEvent(GameObject *obj, Event event, float deltaTime)
{
    StateConfig *cfg = &obj->stateConfigs[obj->currentState];

    if (cfg->HandleEvent)
        cfg->HandleEvent(obj, event, deltaTime);
}

// ---------------------------------------------------------
// Update the current state
// ---------------------------------------------------------
void UpdateState(GameObject *obj, float deltaTime)
{
    StateConfig *cfg = &obj->stateConfigs[obj->currentState];

    if (cfg->Update)
        cfg->Update(obj, deltaTime);
}

// ----------------------------------------------------------
// Debug print (optional)
// ----------------------------------------------------------
void PrintStateConfigs(StateConfig *stateConfigs, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("State %d: %s\n", i, stateConfigs[i].name);
    }
}
