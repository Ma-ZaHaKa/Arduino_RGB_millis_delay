const int bluePin = 5;    // Пин для красного цвета
const int greenPin = 6; // Пин для зеленого цвета
const int redPin = 11;  // Пин для синего цвета

int delayTime = 10;      // Время задержки между шагами изменения цвета

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //analogWrite(3, 255);
}

void loop()
{
  Animation1(redPin, greenPin, bluePin, 20, 1000, 255);
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