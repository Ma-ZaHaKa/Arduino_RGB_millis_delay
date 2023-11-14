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
        CurrDelay = DelayColor;
    }

    void OnAnimation()
    {
      unsigned long currentMillis = millis();

      /*if (mode == 0) { 
        analogWrite(RPin, Brightness); 
        CurrDelay = DelayAnim;
        ++mode; 
      }*/

      if (currentMillis - last_millis >= CurrDelay)
      {
        last_millis = currentMillis;
        switch (mode)
        {
          case 0:
            analogWrite(RPin, Brightness); 
            colorStep = 0;
            mode++;
            CurrDelay = DelayColor;
            break;


          case 1: // YELLOW
            if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
            analogWrite(GPin, colorStep);
            colorStep++;
            if (colorStep > Brightness) {
              colorStep = 0;
              mode++;
              CurrDelay = DelayColor;
            }
            break;


          case 2: // GREEN
            if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
            analogWrite(RPin, Brightness - colorStep);
            colorStep++;
            if (colorStep > Brightness) {
              colorStep = 0;
              mode++;
              CurrDelay = DelayColor;
            }
            break;


          case 3: // BLUE (LIGHT)
            if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
            analogWrite(BPin, colorStep);
            colorStep++;
            if (colorStep > Brightness) {
              colorStep = 0;
              mode++;
              CurrDelay = DelayColor;
            }
            break;


          case 4: // BLUE (DARK)
            if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
            analogWrite(GPin, Brightness - colorStep);
            colorStep++;
            if (colorStep > Brightness) {
              colorStep = 0;
              mode++;
              CurrDelay = DelayColor;
            }
            break;


          case 5: // PURPLE
            if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
            analogWrite(RPin, colorStep);
            colorStep++;
            if (colorStep > Brightness) {
              colorStep = 0;
              mode++;
              CurrDelay = DelayColor;
            }
            break;


          case 6: // RED
            if(CurrDelay != DelayAnim) { CurrDelay = DelayAnim; }
            analogWrite(BPin, Brightness - colorStep);
            colorStep++;
            if (colorStep > Brightness) {
              colorStep = 0;
              mode = 0; // Restart animation
              //CurrDelay = DelayColor;
            }
            break;

        }
      }
    }

    void StopAnimation()
    {
      CurrDelay = 0;
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
    int Brightness = 0;
    int CurrDelay = 0;
    int mode = 0; // 0 start(red), 1 yellow loop, 2 green loop, 3 blue loop, 4 blue loop, 5 purple loop, 6 red loop
    int colorStep = 0;
};


RGBFullAnimation rgbanim;


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //analogWrite(3, 255);
  rgbanim.InitAnimation(redPin, greenPin, bluePin, 10, 2000, 255);
}

void loop()
{
  //Animation1(redPin, greenPin, bluePin, 20, 1000, 255);
  rgbanim.OnAnimation();
}



void Animation1(int R, int G, int B, int _delay1, int delay2, int yarkost)
{
    // RED
    analogWrite(R, yarkost);
    analogWrite(G, 0);
    analogWrite(B, 0);

    // YELLOW
    for (int i = 0; i <= yarkost; i++) { analogWrite(G, i); delay(_delay1); }
    delay(delay2);

    // GREEN
    for (int i = yarkost; i >= 0; i--) { analogWrite(R, i); delay(_delay1); }
    delay(delay2);

    // BULE (LIGHT)
    for (int i = 0; i <= yarkost; i++) { analogWrite(B, i); delay(_delay1); }
    delay(delay2);

    // BLUE (DARK)
    for (int i = yarkost; i >= 0; i--) { analogWrite(G, i); delay(_delay1); }
    delay(delay2);

    // PURPLE
    for (int i = 0; i <= yarkost; i++) { analogWrite(R, i); delay(_delay1); }
    delay(delay2);

    // RED
    for (int i = yarkost; i >= 0; i--) { analogWrite(B, i); delay(_delay1); }
    delay(delay2);
}