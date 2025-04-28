//#已知自车的速度，加速度，根据时间预测自车的状态（位置，速度），只考虑前进直行情况
// v;
// ; acc;
// ; v=acc*t
// ; v(t) = v0 + a*t  s(t) = v0*t + 0.5 *a *t ^2
//horizon robot interview 1
struct intput{
    float v();
    float acc();
}
struct output{
    float position();
    float velosity();
}

struct output calculate(struct input data ,float t){
    struct output temp{};
    float t0;
    if(data.acc >= 0.0){
        temp.velosity = data.v + data.acc*t;
        temp.position = (data.v * t + data.acc*square(t)/2);
    }
    else
    {

        temp.velosity = (data.v + data.acc*t)<0?0:(data.v + data.acc*t);
        t0 = (data.v/ data.acc)*(-1);
        if(t > t0){
            temp.position = (data.v * t0 + data.acc*square(t0)/2)
        }
        else{
            temp.position = (data.v * t + data.acc*square(t)/2)
        }
        
    }
    return temp;
}


