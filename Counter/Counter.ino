
int digit[10][7] = {   {1,1,1,1,1,1,0},  //0
              {0,1,1,0,0,0,0},  //1
              {1,1,0,1,1,0,1},  //2
              {1,1,1,1,0,0,1},  //3
              {0,1,1,0,0,1,1},  //4
              {1,0,1,1,0,1,1},  //5
              {1,0,1,1,1,1,1},  //6
              {1,1,1,0,0,0,0},  //7
              {1,1,1,1,1,1,1}, //8
              {1,1,1,1,0,1,1}  //9
};

int x,y,i;

void setup() {
  for(x=1;x<=7;x++) {
    pinMode(x,OUTPUT);
  }
}
void loop () {
    for(i=0;i<=9;i++) {
  for(y=0;y<7;y++) {
    digitalWrite(y+1,digit[i][y]);
}
    delay(65);
}
}
