//horizon interview ii
//给定一个box, 通过中心点坐标（x, y), box朝向（theta) 以及长宽表征(length, width), 编程实现计算任意点(px, py)到box的距离
float distance(px, py){
    float dx = px - x;
    float dy = py - y;
    float xe =  dx * cos(theta) + dy * sin(theta);
    float ye = -dx * sin(theta) + dy * cos(theta);
    // #px,py 在非角的位置计算(l/2,d/2),(l/2,-d/2),(-l/2,d/2),(-l/2,-d/2)
    if(abs(xe) >l/2 && abs(ye) > d/2 ){
        float lenghth_min = min(xe - l/2, xe + l/2);
        float width_min =min(ye -d/2, ye + d/2);
        return min(lenghth_min, lenghth_min)
    }else{    // #角区域计算
         if(xe > l/2){
            if(ye > d/2){
                return sqrt(pow(xe - l/2, 2) + pow(ye - d/2, 2));
            }else{
                return sqrt(pow(xe - l/2, 2) + pow(ye + d/2, 2));
            }
         }else if(xe < -l/2){
            if(ye > d/2){
                return sqrt(pow(xe + l/2, 2) + pow(ye - d/2, 2));
            }else{
                return sqrt(pow(xe + l/2, 2) + pow(ye + d/2, 2));
            }
        }
    }
}