int n;
int i;

void setup () {
   for(i=0;i<10;i=i+1) {
    pinMode(i,OUTPUT);
   }
}

void loop () {



  for(n=0;n<10;n=n+1) {
    digitalWrite(n,HIGH); 
    delay(100);
    digitalWrite(n,LOW);
    delay(0);
  }

  }
