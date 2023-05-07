#pragma once
#include "context.hpp"

class State{
    public:
        virtual void Handle(Context* context){};
};