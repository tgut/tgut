#ifndef  __STATE_H__
#define  __STATE_H__
class Context{
        
    public:
        State* state=nullptr;

        Context(State* state){
            this->state = state;
        };
        void SetState(State* state){
            this->state = state;
        }
        State* GetState(){
            return this->state;
        }

        void Request(){
            state->Handle(this);
        }
};

#endif