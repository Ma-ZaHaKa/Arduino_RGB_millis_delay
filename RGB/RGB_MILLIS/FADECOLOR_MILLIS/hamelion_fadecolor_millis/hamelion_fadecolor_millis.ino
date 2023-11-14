const int bluePin = 5;    // Пин для красного цвета
const int greenPin = 6; // Пин для зеленого цвета
const int redPin = 11;  // Пин для синего цвета


class RGBFullAnimation
{
  public:
    RGBFullAnimation() {}

    void InitAnimation(int _RPin, int _GPin, int _BPin, int _DelayAnim, int _DelayColor, int _Brightness)
    {
        StopAnimation();
        RPin = _RPin;
        GPin = _GPin;
        BPin = _BPin;
        DelayAnim = _DelayAnim;
        DelayColor = _DelayColor;
        Brightness = _Brightness;
        CurrDelay = _DelayAnim; // for init start anim
    }

    void OnAnimation()
    {
        unsigned long currentMillis = millis();
        if (currentMillis - last_millis >= CurrDelay)
        {
          last_millis = currentMillis;
          switch (mode)
          {
              case 0: // BLUE
                  if (CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
                  analogWrite(RPin, colorStep);
                  analogWrite(GPin, Brightness - colorStep);
                  analogWrite(BPin, Brightness);
                  if(!start) { start = true; CurrDelay = DelayColor; } // залокать первый цвет
                  colorStep++;
                  if (colorStep > Brightness)
                  {
                    colorStep = 0;
                    ++mode;
                    CurrDelay = DelayColor;
                  }
                  break;

              case 1: // PURPLE
                  if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
                  analogWrite(GPin, colorStep);
                  analogWrite(BPin, Brightness - colorStep);
                  analogWrite(RPin, Brightness);
                  colorStep++;
                  if (colorStep > Brightness)
                  {
                    colorStep = 0;
                    ++mode;
                    CurrDelay = DelayColor;
                  }
                  break;

              case 2: // YELLOW
                  if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
                  analogWrite(BPin, colorStep);
                  analogWrite(RPin, Brightness - colorStep);
                  analogWrite(GPin, Brightness);
                  colorStep++;
                  if (colorStep > Brightness)
                  {
                    colorStep = 0;
                    mode = 0;
                    CurrDelay = DelayColor;
                  }
                  break;
          }
        }
    }


    void StopAnimation()
    {
      last_millis = 0;
      mode = 0;
      colorStep = 0;
      digitalWrite(RPin, LOW);
      digitalWrite(GPin, LOW);
      digitalWrite(BPin, LOW);
    }



  //private:
    unsigned long last_millis = 0;
    int RPin = 0;
    int GPin = 0;
    int BPin = 0;
    int DelayAnim = 0;
    int DelayColor = 0;
    int CurrDelay = 0;
    int Brightness = 0;
    int mode = 0; // 0 start(red), 1 yellow loop, 2 green loop, 3 blue loop, 4 blue loop, 5 purple loop, 6 red loop
    int colorStep = 0;
    bool start = false;
};


RGBFullAnimation rgbanim;


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //analogWrite(3, 255);
  rgbanim.InitAnimation(redPin, greenPin, bluePin, 10, 3000, 255);
}

void loop()
{
  //Animation1(redPin, greenPin, bluePin, 20, 1000, 255);
  rgbanim.OnAnimation();
}


/*void _loop(){  
  // Вызываем функцию установки цвета и в качестве параметров передаем номер пина. 
  // Используем вызов 3 раза со сменой пинов, для перетекания из одного цвета в другой.
  setFadeColor(redPin,greenPin,bluePin);
  setFadeColor(greenPin,bluePin,redPin);
  setFadeColor(bluePin,redPin,greenPin);
}
 
// Функция, которая устанавливает для каждого пина(RGB канала) 
// свой алгоритм изменения цвета
void setFadeColor(int cPin1,int cPin2,int cPin3){
  for(int i=0;i<=255;i++){
    analogWrite(cPin1, i);
    analogWrite(cPin2, 255-i);
    analogWrite(cPin3, 255);
    delay(5);
  }
}*/
