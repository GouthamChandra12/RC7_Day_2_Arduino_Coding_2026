# Student handout: Arduino coding

Keep this open next to your laptop.

## Setup, once

1. Install **Arduino IDE 2** from arduino.cc/en/software.
2. Tools > Board > Boards Manager. Install **esp32 by Espressif Systems**.
3. Plug in the board with a USB-C cable that carries data.
4. Tools > Board > esp32 > **ESP32 Dev Module**.
5. Tools > Port > the one that appears when you plug in.
6. Tools > Serial Monitor. Set **115200 baud** and **Newline**.

## Every sketch has two parts

```cpp
void setup() {
  // runs once
}

void loop() {
  // runs forever
}
```

## The method

1. **Read it.** 2. **Type it.** 3. **Mod it.** Change one thing, break it, fix it.

## The buttons

- **Tick:** check the code.
- **Arrow:** upload to the board.
- **Magnifying glass:** the Serial Monitor.
- **Black panel:** read the red errors. They name the line.

## The five fixes

1. **No port:** change the USB cable.
2. **Upload hangs on Connecting...:** hold **BOOT** until it starts.
3. **Nothing printed:** press **EN** with the Serial Monitor open.
4. **Rubbish text:** set 115200 baud.
5. **No reply to typing:** set the line ending to Newline.

## Commands you will use

| Idea | Looks like |
|---|---|
| Variable | `int lives = 3;` |
| Print | `Serial.println(x);` |
| Wait | `delay(500);` |
| Loop | `for (int i = 0; i < 5; i++) { }` |
| Decision | `if (x > 3) { } else { }` |
| Function | `void shout(String w) { }` |
| Array | `String a[] = {"x", "y"};` |
| Button | `digitalRead(0) == LOW` |
| Time | `millis()` |
| Touch | `touchRead(4)` |

The whole course is in README.md in this repository.
