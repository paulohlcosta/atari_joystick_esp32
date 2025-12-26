/* JOYSTICK COMO TECLADO
TESTADO
APROVADO NO ANDROID
RE-PROVADO NO WINDOWS  

CHANGELOG

	v2		alterado input method para keyboard no lugar de gamepad
	v2.1	ajustado delay para funcionar no windows. NOTA: no windows as setas funcionaram com bleKeyboard.write(KEY_UP_ARROW)
*/

#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Atari BLE Keyboard", "Paulo ESP32 Lite", 100);

#define BUTTON_UP 12 // GPIO12
#define BUTTON_DOWN 13 // GPIO13
#define BUTTON_LEFT 27
#define BUTTON_RIGHT 14
#define BUTTON_FIRE 26

enum ButtonState { IDLE, PRESSED, RELEASED };

ButtonState buttonUpState = IDLE;
ButtonState buttonDownState = IDLE;
ButtonState buttonLeftState = IDLE;
ButtonState buttonRightState = IDLE;
ButtonState buttonFireState = IDLE;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, LOW);
  //Serial.begin(115200);
  //Serial.println("Sketch filename: " __FILE__);

  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_FIRE, INPUT_PULLUP);

  bleKeyboard.begin();

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    handleButton(BUTTON_UP, KEY_UP_ARROW, buttonUpState, "UP");
    handleButton(BUTTON_DOWN, KEY_DOWN_ARROW, buttonDownState, "DOWN");
    handleButton(BUTTON_LEFT, KEY_LEFT_ARROW, buttonLeftState, "LEFT");
    handleButton(BUTTON_RIGHT, KEY_RIGHT_ARROW, buttonRightState, "RIGHT");
    handleButton(BUTTON_FIRE, KEY_RIGHT_CTRL, buttonFireState, "CTRL");
  }

  delay(30); // Small delay to avoid excessive reading
}

void handleButton(int buttonPin, uint8_t key, ButtonState &state, const char* keyName) {
  switch (state) {
    case IDLE:
      if (digitalRead(buttonPin) == LOW) {
        bleKeyboard.press(key);  // alterar estado de IDLE para PRESSED
        state = PRESSED;
      }
      break;
    case PRESSED:
      if (digitalRead(buttonPin) == HIGH) {
        bleKeyboard.release(key);
        state = RELEASED;
      }
      break;
    case RELEASED:
      if (digitalRead(buttonPin) == LOW) {
        state = PRESSED;
      } else {
        state = IDLE;  // alterar estado de RELEASED para IDLE
      }
      break;
  }
}
