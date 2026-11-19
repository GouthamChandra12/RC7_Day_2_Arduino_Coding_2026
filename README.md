# Arduino coding: RC7 skills module

Learn the Arduino language by playing small games on an ESP32. You need one board, a USB-C cable and a laptop. The Wi-Fi levels also use your phone.

RC7, Architectural Design M.Arch, The Bartlett School of Architecture, UCL.

This one page is the whole course. The sketches are in the [`sketches`](sketches) folder. A one-page summary is in [HANDOUT.md](HANDOUT.md).

## Contents

- [How this course works](#how-this-course-works)
- [Setup](#setup)
- [Intro: the Arduino IDE and the language](#intro-the-arduino-ide-and-the-language)
- **Levels**
  - [Level 0: Hello board](#level-0-hello-board)
  - [Level 1: Variables (name tag)](#level-1-variables-name-tag)
  - [Level 2: Loops (rocket countdown)](#level-2-loops-rocket-countdown)
  - [Level 3: Functions (shout machine)](#level-3-functions-shout-machine)
  - [Level 4: Decisions (dice)](#level-4-decisions-dice)
  - [Level 5: Arrays (magic 8-ball)](#level-5-arrays-magic-8-ball)
  - [Level 6: Talking back (greeter)](#level-6-talking-back-greeter)
  - [Level 7: Number guessing game](#level-7-number-guessing-game)
  - [Level 8: Time (reaction timer)](#level-8-time-reaction-timer)
  - [Level 9: Touch](#level-9-touch)
  - [Level 10: Libraries](#level-10-libraries)
  - [Level 11: Wi-Fi scanner](#level-11-wi-fi-scanner)
  - [Level 12: Your board has a website](#level-12-your-board-has-a-website)
  - [Level 13: Finale](#level-13-finale)
- [Extras: show them if there is time](#extras-show-them-if-there-is-time)
  - [Extra 1: Design brief generator](#extra-1-design-brief-generator)
  - [Extra 2: Rock paper scissors](#extra-2-rock-paper-scissors)
  - [Extra 3: Building tour (text adventure)](#extra-3-building-tour-text-adventure)
  - [Extra 4: Code breaker](#extra-4-code-breaker)
  - [Extra 5: Memory game](#extra-5-memory-game)
  - [Extra 6: Morse translator](#extra-6-morse-translator)
  - [Extra 7: Stopwatch](#extra-7-stopwatch)
  - [Extra 8: Multiplication table](#extra-8-multiplication-table)
  - [Extra 9: Board info](#extra-9-board-info)
  - [Extra 10: Deep sleep, wake by touch](#extra-10-deep-sleep-wake-by-touch)
  - [Extra 11: Weather](#extra-11-weather)
  - [Extra 12: Clock](#extra-12-clock)
  - [Extra 13: Wi-Fi data walk logger](#extra-13-wi-fi-data-walk-logger)
  - [Extra 14: ESP-NOW room chat](#extra-14-esp-now-room-chat)
  - [Extra 15: Bluetooth chat (Android only)](#extra-15-bluetooth-chat-android-only)
- [When it breaks](#when-it-breaks)
- [Cheat sheet](#cheat-sheet)
- [Credits](#credits)

## How this course works

Each level has the same parts:

1. **Read it.** One idea, a few minutes.
2. **Type it.** Type the code yourself. Typing mistakes teach you a lot.
3. **Mod it.** Change one thing. Break it on purpose. Fix it.

**About the sketches folder.** Arduino needs every sketch to live in a folder with the same name as the sketch. That is why `sketches` holds many small folders. Open the `.ino` file inside a folder and the IDE loads it.

Tested with the **esp32 by Espressif Systems** package, version 3.3.x, on an ESP32 Dev Module.

## Setup

1. **Install Arduino IDE 2** from [arduino.cc/en/software](https://www.arduino.cc/en/software).
2. **Add the ESP32 package.** Tools > Board > Boards Manager. Search for `esp32` and install **esp32 by Espressif Systems**. It is a big download. Start it early.
3. **Plug in the board** with a USB-C cable that carries data. If no port shows up, try another cable.
4. **Choose the board:** Tools > Board > esp32 > **ESP32 Dev Module**.
5. **Choose the port:** Tools > Port. Pick the one that appears when you plug the board in. If nothing appears, install the CP210x driver (some boards use CH340).
6. **Open the Serial Monitor:** Tools > Serial Monitor. Set **115200 baud** and **Newline** at the bottom.

### Three settings that matter

| Setting | Value | Why |
|---|---|---|
| Board | ESP32 Dev Module | Tells the IDE which chip to compile for |
| Port | The one that appears when you plug in | How the laptop talks to the board |
| Baud | 115200 | The sketch and the Serial Monitor must match |

## Intro: the Arduino IDE and the language

### What the IDE does

The Arduino IDE is a text editor with a few buttons. You write code in it, it turns that code into something the chip understands, and it sends it to the board over the USB-C cable.

The buttons you will use all day:

- **Tick (Verify):** checks your code for mistakes and compiles it. Nothing goes to the board.
- **Arrow (Upload):** compiles, then sends the program to the board.
- **Magnifying glass (Serial Monitor):** a window where the board can print text to your laptop.
- **Black panel at the bottom (Output):** shows errors in red. Read it. It usually tells you the line number.

A file in Arduino is called a **sketch**. It ends in `.ino`.

### The language

The language is C++. Arduino adds a set of ready-made commands on top of it, like `Serial.println()` and `delay()`, and hides some of the boring setup. What you learn here carries over to any C++ code.

Rules you meet straight away:

- Most lines end with a semicolon `;`. Forget one and the compiler complains.
- Curly braces `{ }` wrap a block of code.
- Capital letters matter. `Serial` works. `serial` does not.
- `//` starts a comment. The board ignores the rest of that line.
- `void` means "this function does a job and does not give anything back".

### setup() and loop()

Every Arduino sketch needs these two functions. A function is a named block of code.

- `setup()` runs **once**, when the board gets power or you press reset. Use it to prepare things.
- `loop()` runs **again and again, forever**, as fast as it can.

#### Why we always need them

A board has no screen, no keyboard and no operating system. It needs a rule for what to do when it wakes up. The rule is built into the ESP32 package. Somewhere inside it there is code that works roughly like this:

```cpp
// You never write this. It is hidden inside the board package.
void main() {
  setup();
  while (true) {
    loop();
  }
}
```

It calls your `setup()` once, then calls your `loop()` forever. If either function is missing, that hidden code has nothing to call and the sketch will not compile.

That is also why a board never finishes. A laptop program ends. A board program keeps looping until you cut the power.

### The smallest sketch

File > New Sketch gives you this. Click the tick. It compiles and does nothing, and that is correct.

```cpp
void setup() {
  // runs once
}

void loop() {
  // runs forever
}
```

Next: [Level 0, Hello board](#level-0-hello-board)

## Levels

## Level 0: Hello board

Your first sketch. The board says hello and then keeps telling you it is alive. If this works, your laptop, cable, port and board are all fine.

### New ideas

- `setup()` runs once. `loop()` runs forever.
- `Serial.begin(115200)` opens the line between the board and your laptop.
- `Serial.println("text")` sends a line of text to the Serial Monitor.
- `delay(1000)` waits one second. The number is in milliseconds.

### The code

Sketch file: [`sketches/00_hello_board/00_hello_board.ino`](sketches/00_hello_board/00_hello_board.ino)

```cpp
void setup() {
  Serial.begin(115200);   // open the line to the laptop
  delay(2000);            // wait 2 seconds so the Serial Monitor is ready
  Serial.println("Hello, board!");
}

void loop() {
  Serial.println("I am alive");
  delay(1000);            // wait 1 second
}
```

### How it works

- `setup()` runs when the board gets power or you press reset. It prints "Hello, board!" once.
- `loop()` starts after `setup()` and repeats. It prints "I am alive", waits a second, and does it again.
- The Serial Monitor must be set to **115200 baud** (bottom right). If the numbers do not match you see rubbish characters.

### Try it

1. Pick the board: Tools > Board > esp32 > ESP32 Dev Module.
2. Pick the port: Tools > Port.
3. Click the arrow (Upload). If it says "Connecting...", hold the BOOT button on the board until it starts.
4. Open the Serial Monitor (the magnifying glass) and set 115200 baud.

### Mod it

- Change `delay(1000)` to `delay(200)`. What changes?
- Delete the whole `loop()` function and click the tick. Read the red error. This is what a missing function looks like.
- Move `"I am alive"` into `setup()`. How many times does it print now?

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.
- Nothing in Tools > Port: use a different USB-C cable. Some cables only charge. You may also need the CP210x driver.
- Rubbish characters: set the Serial Monitor to 115200 baud.

---

## Level 1: Variables (name tag)

A variable is a labelled box that holds one value. You give it a type, a name and a value. Then you can use the name anywhere in your code.

### New ideas

- `int` holds whole numbers, like `2026`.
- `float` holds decimals, like `21.5`.
- `bool` holds `true` or `false`.
- `String` holds text, like `"Ada"`.
- Variables written above `setup()` can be used in every function.

### The code

Sketch file: [`sketches/01_variables/01_variables.ino`](sketches/01_variables/01_variables.ino)

```cpp
String name = "Ada";
int year = 2026;
float temp = 21.5;
bool awake = true;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Name: " + name);
  Serial.println("Year: " + String(year));
  Serial.println("Temp: " + String(temp));
  Serial.print("Awake: ");
  Serial.println(awake);
}

void loop() {}
```

### How it works

- Each line at the top makes one box and puts a value in it.
- `"Name: " + name` joins two pieces of text.
- `String(year)` turns a number into text so it can be joined.
- `Serial.println(awake)` prints `1` for true and `0` for false.

### Try it

1. Upload and open the Serial Monitor at 115200 baud.
2. You should see four lines, once.

### Mod it

- Put your own name in.
- Add `int lives = 3;` and print it.
- Change `int year = 2026;` to `int year = 2026.5;`. What gets stored? Why?
- Change `float temp` to `int temp`. What happens to the decimal?

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.

---

## Level 2: Loops (rocket countdown)

A loop repeats a block of code. A `for` loop is the one to use when you know how many times you want to repeat.

### New ideas

- `for (start; keep going while; change)`
- `i--` takes one off `i`. `i++` adds one.
- A block of code sits between `{` and `}`.

### The code

Sketch file: [`sketches/02_loops/02_loops.ino`](sketches/02_loops/02_loops.ino)

```cpp
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Launch in...");
  for (int i = 10; i > 0; i--) {
    Serial.println(i);
    delay(500);
  }
  Serial.println("LIFT OFF!");
}

void loop() {}
```

### How it works

- `int i = 10;` starts a counter at 10.
- `i > 0;` is the test. The loop keeps going while this is true.
- `i--` runs after each round and takes one off.
- Inside the loop the board prints `i` and waits half a second.
- When `i` reaches 0 the test fails, the loop ends, and the board prints "LIFT OFF!".
- The loop is inside `setup()`, so the rocket launches once. `loop()` is empty.

### Try it

1. Upload and open the Serial Monitor.
2. Press the **EN** button on the board to launch again.

### Mod it

- Count up from 1 to 10 instead.
- Start the countdown at 3.
- After lift off, add a second `for` loop that prints a row of `*`.
- Make the countdown faster near the end.

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.

---

## Level 3: Functions (shout machine)

A function is a command you invent. You give the steps a name once, then use the name as many times as you like.

### New ideas

- You write a function with a type, a name, brackets and a block.
- Things inside the brackets are what the function needs. They are called parameters.
- `void` means the function does a job and gives nothing back.
- `setup()` and `loop()` are functions too.

### The code

Sketch file: [`sketches/03_functions/03_functions.ino`](sketches/03_functions/03_functions.ino)

```cpp
void shout(String word, int times) {
  for (int i = 0; i < times; i++) {
    Serial.println(word + "!");
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  shout("hello", 3);
  shout("architecture", 2);
}

void loop() {}
```

### How it works

- `shout` takes a word and a number.
- It uses a `for` loop to print the word that many times, with an exclamation mark.
- `shout("hello", 3);` calls the function. The board runs the steps with those values.
- You can call it as many times as you want with different values.

### Try it

1. Upload and open the Serial Monitor.
2. You should see "hello!" three times, then "architecture!" twice.

### Mod it

- Add a third call with your own word.
- Put the rocket countdown from Level 2 into a function called `countdown(int from)`. Call it twice with different numbers.
- Make `shout` print the word in a different form on each round.

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.

---

## Level 4: Decisions (dice)

Press the BOOT button on the board and it rolls a six-sided dice. This is the first time the board reacts to you.

### New ideas

- `pinMode(0, INPUT_PULLUP)` sets pin 0 as an input.
- The BOOT button is on pin 0. With `INPUT_PULLUP` the pin reads `HIGH` normally and `LOW` while you press it.
- `digitalRead(0)` reads the pin.
- `if` runs its block only when the test is true.
- `==` compares two values. A single `=` puts a value in a variable.
- `random(1, 7)` gives 1 to 6. The top number is left out.

### The code

Sketch file: [`sketches/04_dice/04_dice.ino`](sketches/04_dice/04_dice.ino)

```cpp
void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  delay(2000);
  Serial.println("Press BOOT to roll the dice");
}

void loop() {
  if (digitalRead(0) == LOW) {
    Serial.print("You rolled: ");
    Serial.println(random(1, 7));
    delay(300);
    while (digitalRead(0) == LOW) {}
  }
}
```

### How it works

- `loop()` keeps checking the button.
- When the button is down, the pin reads `LOW`, so the `if` block runs.
- The board prints a random number.
- `delay(300)` and the empty `while` loop make the board wait until you let go. Without them it would roll many times for one press.

### Try it

1. Upload and open the Serial Monitor.
2. Press the BOOT button on the board.

### Mod it

- Make it a twenty-sided dice.
- Print "Critical!" when you roll the highest number.
- Roll two dice and print the total.

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.
- Nothing happens when you press BOOT: check the Serial Monitor is open at 115200 baud, and press the button firmly. Wait for "Done uploading" first.

---

## Level 5: Arrays (magic 8-ball)

Type a question in the Serial Monitor, press Enter, and the board gives you an answer.

### New ideas

- An array is a numbered row of boxes. Counting starts at zero.
- `answers[0]` is "Yes". `answers[6]` is "Make a model first".
- `Serial.available()` is true when something you typed has arrived.
- `Serial.readStringUntil('\n')` reads what you typed, up to the Enter key.
- `const int N = 7;` is a variable that cannot change.

### The code

Sketch file: [`sketches/05_magic_8ball/05_magic_8ball.ino`](sketches/05_magic_8ball/05_magic_8ball.ino)

```cpp
String answers[] = {
  "Yes", "No", "Ask again",
  "Definitely", "Very doubtful",
  "Build it", "Make a model first"
};
const int N = 7;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Ask a question, press Enter");
}

void loop() {
  if (Serial.available()) {
    Serial.readStringUntil('\n');
    Serial.println(answers[random(0, N)]);
  }
}
```

### How it works

- The array holds seven answers.
- `loop()` waits until you type something.
- It reads your question and throws it away. The board does not read the question. Any text gets an answer.
- `random(0, N)` picks a number from 0 to 6, and `answers[...]` gives the answer at that place.

### Try it

1. At the bottom of the Serial Monitor, set the line ending to **Newline**.
2. Type a question into the box at the top and press Enter.

### Mod it

- Add three answers of your own. Change `N` to match.
- Make `N` too big on purpose. What happens?
- Replace the answers with design critique comments.

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.
- No answer after you press Enter: check the line ending is **Newline** and the baud is 115200.

---

## Level 6: Talking back (greeter)

The board asks your name and answers using it. It reads text you type.

### New ideas

- `String name = ...` is a variable made inside the block. It only exists in there.
- `trim()` removes spaces and line endings from the ends of text.
- `name.length()` gives the number of letters.
- `Serial.print()` prints without starting a new line.

### The code

Sketch file: [`sketches/06_greeter/06_greeter.ino`](sketches/06_greeter/06_greeter.ino)

```cpp
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("What is your name?");
}

void loop() {
  if (Serial.available()) {
    String name = Serial.readStringUntil('\n');
    name.trim();
    Serial.println("Hello, " + name + "!");
    int n = name.length();
    Serial.print("Your name has ");
    Serial.print(n);
    Serial.println(" letters.");
  }
}
```

### How it works

- The board asks a question once in `setup()`.
- `loop()` waits for typing.
- It reads your whole line and cleans it with `trim()`.
- It builds a greeting by joining text and your name.
- It counts the letters and prints them in three pieces on one line.

### Try it

1. Set the line ending to **Newline** and the baud to 115200.
2. Type your name and press Enter.

### Mod it

- Greet one person differently. Use `if (name == "Ada")`.
- Print the name in a loop three times.
- Print "That is a long name!" when it has more than 8 letters.

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.

---

## Level 7: Number guessing game

The board picks a secret number from 1 to 100. You type guesses. It tells you if you are too low or too high.

### New ideas

- `else if` adds a second question after an `if`.
- Variables above `setup()` keep their value between loops. That is how the board remembers the secret and your number of tries.
- `Serial.parseInt()` reads digits you typed as a number.
- `tries++` adds one to `tries`.

### The code

Sketch file: [`sketches/07_guessing_game/07_guessing_game.ino`](sketches/07_guessing_game/07_guessing_game.ino)

```cpp
int secret;
int tries = 0;

void setup() {
  Serial.begin(115200);
  secret = random(1, 101);
  delay(2000);
  Serial.println("Guess my number, 1 to 100");
}

void loop() {
  if (Serial.available()) {
    int guess = Serial.parseInt();
    while (Serial.available()) Serial.read();
    tries++;
    if (guess < secret) Serial.println("Too low");
    else if (guess > secret) Serial.println("Too high");
    else {
      Serial.println("Got it in " + String(tries));
      secret = random(1, 101);
      tries = 0;
    }
  }
}
```

### How it works

- `setup()` picks the secret with `random(1, 101)`.
- `loop()` waits for a guess.
- `while (Serial.available()) Serial.read();` throws away anything left over, like the Enter key.
- The three-way test: too low? too high? Otherwise it is right.
- On a win it prints the number of tries and starts a new game.

### Try it

1. Set the line ending to **Newline** and the baud to 115200.
2. Type a number and press Enter. Keep guessing.

### Mod it

- Allow only 7 guesses. After that, show the number and start again.
- Print "Warmer" or "Colder" depending on how close the guess is.
- Let the player choose the top number at the start.

### If it does not work

- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. The `delay(2000)` gives you time. You can also press the **EN** button on the board with the Serial Monitor open.

---

## Level 8: Time (reaction timer)

The board waits a random time, says GO, and measures how long you take to press BOOT.

### New ideas

- `millis()` gives the number of milliseconds since the board started.
- To measure a time, save `millis()` at the start, read it again at the end, and subtract.
- `unsigned long` is a whole number that is never negative. It can hold very big numbers.
- `while (...) {}` with nothing inside waits until the test becomes false.

### The code

Sketch file: [`sketches/08_reaction_timer/08_reaction_timer.ino`](sketches/08_reaction_timer/08_reaction_timer.ino)

```cpp
void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  Serial.println("GO! Press BOOT");
  unsigned long start = millis();
  while (digitalRead(0) == HIGH) {}
  unsigned long t = millis() - start;
  Serial.print("Reaction time: ");
  Serial.print(t);
  Serial.println(" ms");
  delay(2000);
}
```

### How it works

- The board prints "Get ready...", then waits two to five seconds at random.
- It prints GO and saves the time in `start`.
- The empty `while` loop waits for the button.
- When you press, it subtracts `start` from `millis()` and prints the result.

### Try it

1. Upload and open the Serial Monitor.
2. Wait for GO. Press BOOT as fast as you can.

### Mod it

- Print "Too slow!" over 500 ms.
- Print "Too early!" if the button is already down at GO.
- Race a friend. Best of five.

---

## Level 9: Touch

The ESP32 can feel touch on some of its pins. No extra parts are needed. When your finger touches a touch pin, the reading **drops**. The sketches below use that drop to build small games.

### Before you start

- Use pin **4** (marked `4` or `D4` on the board). A fingertip on the metal pin works. A jumper wire, or a wire taped to a piece of foil, gives you a bigger pad.
- The numbers change from board to board and from finger to finger. For that reason the sketches measure the untouched value first. Keep your hands off the pin for the first two seconds after the board starts.
- Touch pins on the classic ESP32 are GPIO 0, 2, 4, 12, 13, 14, 15, 27, 32 and 33. We use 4, and 13 for a second player.

### New ideas

- `touchRead(pin)` gives a number. Touch makes it smaller.
- `baseline` is the average of 20 readings with nothing touching the pin. It is the board's "normal".
- `touchRead(4) < baseline * 0.7` means "the reading fell by more than 30 percent". That counts as a touch.
- `map(value, a, b, c, d)` scales a number from one range to another.
- `constrain(value, low, high)` keeps a number inside a range.
- A function can give back an answer. `bool touched()` answers true or false.
- To react once per touch, remember the last state in `wasTouched`. Without it, the board reacts hundreds of times while your finger stays on the pin.

### 9a: Touch plotter

Prints the touch reading. Open Tools > **Serial Plotter** at 115200 baud and touch pin 4. The line drops.

Sketch file: [`sketches/09a_touch_plotter/09a_touch_plotter.ino`](sketches/09a_touch_plotter/09a_touch_plotter.ino)

```cpp
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(touchRead(4));
  delay(50);
}
```

**Mod it**

- Write down the untouched number and the touched number.
- Touch with one finger, then two. Try a wet fingertip. What changes?

### 9b: Touch meter

Draws a bar of `#` characters that gets longer the harder you touch.

Sketch file: [`sketches/09b_touch_meter/09b_touch_meter.ino`](sketches/09b_touch_meter/09b_touch_meter.ino)

```cpp
int baseline;

void setup() {
  Serial.begin(115200);
  delay(2000);
  // measure the untouched value 20 times and take the average
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Untouched value: " + String(baseline));
}

void loop() {
  int drop = baseline - touchRead(4);
  drop = constrain(drop, 0, baseline);
  int length = map(drop, 0, baseline, 0, 40);
  String bar = "";
  for (int i = 0; i < length; i++) {
    bar += "#";
  }
  Serial.println(bar);
  delay(100);
}
```

**Mod it**

- Make the bar use `|` instead of `#`.
- Print the bar on the same line as the number.
- Change 40 to 60 to make a longer bar.

### 9c: Touch dice

The dice from Level 4, with a touch instead of the BOOT button.

Sketch file: [`sketches/09c_touch_dice/09c_touch_dice.ino`](sketches/09c_touch_dice/09c_touch_dice.ino)

```cpp
int baseline;
bool wasTouched = false;

bool touched() {
  return touchRead(4) < baseline * 0.7;
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Touch pin 4 to roll the dice");
}

void loop() {
  bool now = touched();
  if (now && !wasTouched) {
    Serial.println("You rolled: " + String(random(1, 7)));
  }
  wasTouched = now;
  delay(50);
}
```

**Mod it**

- Make a twenty-sided dice.
- Use a wire and foil to make a big touch pad.

### 9d: Secret knock

Tap three times on pin 4 with the right rhythm. The first gap is about half a second and the second gap about one and a half seconds. Get it right and the board says ACCESS GRANTED.

Sketch file: [`sketches/09d_secret_knock/09d_secret_knock.ino`](sketches/09d_secret_knock/09d_secret_knock.ino)

```cpp
int baseline;
unsigned long taps[3];
int count = 0;
bool wasTouched = false;

// The secret: 500 ms between tap 1 and 2, 1500 ms between tap 2 and 3
const int gap1 = 500;
const int gap2 = 1500;
const int slack = 300;   // how far off you are allowed to be

bool touched() {
  return touchRead(4) < baseline * 0.7;
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Knock the secret on pin 4");
}

void loop() {
  bool now = touched();
  if (now && !wasTouched) {
    taps[count] = millis();
    count++;
    if (count == 3) {
      long a = taps[1] - taps[0];
      long b = taps[2] - taps[1];
      if (abs(a - gap1) < slack && abs(b - gap2) < slack) {
        Serial.println("ACCESS GRANTED");
      } else {
        Serial.println("Wrong knock: " + String(a) + " ms, " + String(b) + " ms");
      }
      count = 0;
    }
  }
  if (count > 0 && millis() - taps[count - 1] > 3000) {
    Serial.println("Too slow. Start again.");
    count = 0;
  }
  wasTouched = now;
  delay(30);
}
```

Tip: if you fail, the board prints your two gaps. Use them to learn the rhythm.

**Mod it**

- Change `gap1` and `gap2` to make your own secret rhythm.
- Make `slack` smaller to make it harder.
- Add a fourth tap.

### 9e: Touch duel

Two players. Player A touches pin 4 and Player B touches pin 13. The board says GO after a random wait. The first to touch wins. Touch too early and it is a foul.

Sketch file: [`sketches/09e_touch_duel/09e_touch_duel.ino`](sketches/09e_touch_duel/09e_touch_duel.ino)

```cpp
int baseA;
int baseB;

int calibrate(int pin) {
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(pin);
    delay(20);
  }
  return sum / 20;
}

bool touchedA() { return touchRead(4) < baseA * 0.7; }
bool touchedB() { return touchRead(13) < baseB * 0.7; }

void setup() {
  Serial.begin(115200);
  delay(2000);
  baseA = calibrate(4);
  baseB = calibrate(13);
  Serial.println("Touch duel. Player A: pin 4. Player B: pin 13.");
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  if (touchedA() || touchedB()) {
    Serial.println("Foul! Someone touched too early.");
    delay(2000);
    return;
  }
  Serial.println("GO!");
  unsigned long start = millis();
  while (!touchedA() && !touchedB()) {}
  unsigned long t = millis() - start;
  if (touchedA() && touchedB()) {
    Serial.println("Draw!");
  } else if (touchedA()) {
    Serial.println("Player A wins in " + String(t) + " ms");
  } else {
    Serial.println("Player B wins in " + String(t) + " ms");
  }
  delay(2000);
}
```

**Mod it**

- Keep score over five rounds.
- Print the time difference between the players if you both touch.

### If it does not work

- Nothing happens when you touch: open the plotter (9a) and check the number really drops. If it barely moves, use a longer wire or foil.
- The board reacts without a touch: your hand was near the pin during the first two seconds. Press **EN** to restart.
- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. Press the **EN** button on the board with the Serial Monitor open.

---

## Level 10: Libraries

A library is code that somebody else wrote. You add one line to your sketch and you can use their commands. You have already used the built-in ones without knowing: `Serial` is part of Arduino itself.

### Two kinds of library

1. **Built in.** These come with the ESP32 package. You only need `#include`. Examples: `WiFi`, `WebServer`, `Preferences`.
2. **Installed.** You download these first, with the Library Manager. Example: `ArduinoJson`.

### New ideas

- `#include <Name.h>` pulls a library into your sketch. It goes at the very top.
- A library gives you new commands. Many come as an **object**, a named thing you make once and then use. `Preferences prefs;` makes one called `prefs`. After that you write `prefs.getULong(...)`. The dot means "ask this object to do something".
- `Preferences` saves small values inside the chip. They stay there when you reset or unplug the board.
- The Library Manager is under **Sketch > Include Library > Manage Libraries**. You search by name and click Install. It needs the internet on your laptop.

### 10a: Saved high score (built-in library)

The reaction timer, with a best time that survives a reset. Play a few rounds. Then press **EN**, or unplug the board and plug it in again. The best time is still there.

Sketch file: [`sketches/10a_saved_high_score/10a_saved_high_score.ino`](sketches/10a_saved_high_score/10a_saved_high_score.ino)

```cpp
#include <Preferences.h>

Preferences prefs;
unsigned long best;

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  prefs.begin("reaction", false);          // open a small saved area called "reaction"
  best = prefs.getULong("best", 99999);    // read the saved best time (99999 if none yet)
  delay(2000);
  Serial.println("Best time on record: " + String(best) + " ms");
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  Serial.println("GO!");
  unsigned long start = millis();
  while (digitalRead(0) == HIGH) {}
  unsigned long t = millis() - start;
  Serial.println(String(t) + " ms");
  if (t < best) {
    best = t;
    prefs.putULong("best", best);          // save it. It survives a reset.
    Serial.println("NEW HIGH SCORE! Saved.");
  }
  delay(2000);
}
```

**Mod it**

- Print the best time in seconds with two decimals.
- Add a way to wipe the score: if the board reads the letter `r` from the Serial Monitor, call `prefs.putULong("best", 99999);`.
- Save a second value: the number of rounds played.

### 10b: Install a library

We will install `ArduinoJson`. It reads JSON, a text format that websites use to send data. Later Wi-Fi sketches use it.

1. Open **Sketch > Include Library > Manage Libraries**.
2. Search for `ArduinoJson`.
3. Pick the one by **Benoit Blanchon** and click **Install**.
4. Wait for it to say Installed, then run the next sketch.

### 10c: Read JSON (installed library)

JSON is text with names and values. The sketch holds some JSON in a string and pulls the values out of it. It needs no Wi-Fi.

Sketch file: [`sketches/10c_json_reader/10c_json_reader.ino`](sketches/10c_json_reader/10c_json_reader.ino)

```cpp
#include <ArduinoJson.h>

void setup() {
  Serial.begin(115200);
  delay(2000);

  // some data written as JSON text
  String text = R"({"site":"Roof","floors":4,"height":13.5})";

  JsonDocument doc;
  deserializeJson(doc, text);

  String site = doc["site"];
  int floors = doc["floors"];
  float height = doc["height"];

  Serial.println("Site: " + site);
  Serial.println("Floors: " + String(floors));
  Serial.println("Height: " + String(height) + " m");
}

void loop() {}
```

**Reading it:** `R"( ... )"` is a way to write text that contains quote marks without escaping them. `doc["site"]` asks for the value called `site`.

**Mod it**

- Add a new field to the JSON, like `"material":"timber"`, and print it.
- Change `floors` to a decimal. What happens to the `int`?
- Write JSON that describes your own site.

### If it does not work

- `fatal error: ArduinoJson.h: No such file or directory`: the library is not installed yet. Do step 10b.
- `JsonDocument does not name a type`: you have an old version of ArduinoJson. Update it in the Library Manager. This course uses version 7.
- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. Press the **EN** button on the board with the Serial Monitor open.

---

## Level 11: Wi-Fi scanner

The ESP32 has a radio. Before it connects to anything, it can listen and list every Wi-Fi network around it, and how strong each one is. You can walk around the building with it and watch the signal change.

### New ideas

- `#include <WiFi.h>` adds the Wi-Fi commands.
- `WiFi.mode(WIFI_STA)` makes the board behave like a phone or laptop: it can look for networks.
- `WiFi.scanNetworks()` looks and returns how many it found. Then `WiFi.SSID(i)` gives the name and `WiFi.RSSI(i)` gives the strength of network number `i`.
- **RSSI** is signal strength in dBm. It is a negative number. Closer to zero is stronger: -40 is very strong, -70 is okay, -90 is almost gone.
- The ESP32 only hears **2.4 GHz** networks. Networks that only use 5 GHz will not show up.
- The `for` loop with `i` goes through the list one network at a time. Arrays again, but filled by the Wi-Fi library.

### The sketch

Scans every five seconds and prints each network with a bar that grows with the signal.

Sketch file: [`sketches/11_wifi_scanner/11_wifi_scanner.ino`](sketches/11_wifi_scanner/11_wifi_scanner.ino)

```cpp
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);
  Serial.println("Wi-Fi scanner");
}

void loop() {
  int found = WiFi.scanNetworks();
  Serial.println("Found " + String(found) + " networks");
  for (int i = 0; i < found; i++) {
    int strength = WiFi.RSSI(i);
    int bars = map(constrain(strength, -100, -30), -100, -30, 0, 20);
    String line = "";
    for (int b = 0; b < bars; b++) {
      line += "#";
    }
    Serial.println(WiFi.SSID(i) + "  " + String(strength) + " dBm  " + line);
  }
  Serial.println("-----");
  delay(5000);
}
```

**Mod it**

- Print the channel too: `WiFi.channel(i)`.
- Show only networks stronger than -80.
- Print "open" next to networks with no password: `WiFi.encryptionType(i) == WIFI_AUTH_OPEN`.

### Take it for a walk

Power the board from a laptop or a power bank. Walk through the room, the corridor and the stairwell. Watch one network. Where does it get strong? Where does it drop? Which walls or floors cut it?

There is a longer version in [Extra 13: Wi-Fi data walk logger](#extra-13-wi-fi-data-walk-logger). It writes the numbers in a form you can paste into a spreadsheet, so you can map the signal.

### If it does not work

- It finds 0 networks: wait a few seconds. The first scan can be slow.
- A name is blank: that is a hidden network.
- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. Press the **EN** button on the board with the Serial Monitor open.

---

## Level 12: Your board has a website

The board makes its own Wi-Fi network and runs a small web server. You join that network with your phone, open an address, and see a web page that comes from the chip. The page shows the live touch reading and has a button that rolls a dice on the board.

No router and no internet are needed.

### New ideas

- `WiFi.softAP("name")` makes the board an **access point**: a Wi-Fi network of its own.
- A **web server** waits for a browser to ask for a page, then answers. `WebServer server(80);` makes one on port 80, the normal web port.
- `server.on("/", handleRoot);` says: when someone asks for `/` (the home page), run `handleRoot`.
- `server.send(200, "text/html", page)` sends a web page back. The 200 means "all good".
- `server.handleClient()` in `loop()` checks if anyone is asking for something. Without it the page never loads.
- A web page is **HTML**, plain text with tags like `<h1>` for a heading and `<a href="/roll">` for a link. We keep it in a `String` and swap the words `%TOUCH%` and `%DICE%` for real values each time.
- The button is a link to `/roll`. When the phone opens it, the board runs `handleRoll`, picks a dice number, and sends the phone back to `/`.

### The sketch

Change `ssid` to your own name first, like `RC7-ada`. Every board in the room needs a different name.

Sketch file: [`sketches/12_board_website/12_board_website.ino`](sketches/12_board_website/12_board_website.ino)

```cpp
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "RC7-yourname";   // change this so every board has its own name
WebServer server(80);
int lastRoll = 0;

String makePage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta http-equiv="refresh" content="2">
  <style>
    body { font-family: sans-serif; text-align: center; margin-top: 40px; }
    .big { font-size: 72px; margin: 8px; }
    a { display: inline-block; padding: 16px 32px; background: #e63b2e;
        color: white; text-decoration: none; border-radius: 8px; font-size: 22px; }
  </style>
</head>
<body>
  <h1>My ESP32 board</h1>
  <p>Touch reading on pin 4</p>
  <p class="big">%TOUCH%</p>
  <p>Last dice roll</p>
  <p class="big">%DICE%</p>
  <a href="/roll">Roll the dice</a>
</body>
</html>
)rawliteral";
  page.replace("%TOUCH%", String(touchRead(4)));
  page.replace("%DICE%", lastRoll == 0 ? String("-") : String(lastRoll));
  return page;
}

void handleRoot() {
  server.send(200, "text/html", makePage());
}

void handleRoll() {
  lastRoll = random(1, 7);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid);
  server.on("/", handleRoot);
  server.on("/roll", handleRoll);
  server.begin();
  delay(2000);
  Serial.println("Network name: " + String(ssid));
  Serial.println("Join it on your phone, then open http://" + WiFi.softAPIP().toString());
}

void loop() {
  server.handleClient();
}
```

**Mod it**

- Change the colour of the button. It is in the `style` part.
- Add a second button that rolls a twenty-sided dice.
- Show the time the board has been running with `millis()`.
- Add a button that prints a message in the Serial Monitor.

### How to use it

1. Upload the sketch and open the Serial Monitor at 115200 baud.
2. On your phone, open Wi-Fi settings and join the network with your board's name.
3. The phone may say "no internet". Stay connected.
4. Open a browser and go to **http://192.168.4.1** (the address the board prints).
5. Touch pin 4 on the board. Watch the number change on the page. Press the button.

### If it does not work

- The network does not appear: it is 2.4 GHz, and some phones hide it in a long list. Check the name in the Serial Monitor.
- The browser says it cannot connect: make sure you typed `http://` and not `https://`.
- The phone jumps back to the old Wi-Fi: turn off "auto switch" for that network, or turn off mobile data for a minute.
- The first message is missing. The board prints it once at start, before the Serial Monitor is ready. Press the **EN** button on the board with the Serial Monitor open.

---

## Level 13: Finale

Everything together: variables, `if`, functions, `millis()`, touch, and a library to save the score.

### The reaction duel

Two players. **Player A** uses the BOOT button. **Player B** touches pin 4. The board waits a random time, then says GO. The first to react wins. If someone reacts before GO, it is a foul. The best time is saved, so it survives a reset.

### The sketch

Keep your hands off pin 4 for the first two seconds. The board measures its untouched value then.

Sketch file: [`sketches/13_reaction_duel/13_reaction_duel.ino`](sketches/13_reaction_duel/13_reaction_duel.ino)

```cpp
#include <Preferences.h>

Preferences prefs;
int baseline;
unsigned long bestTime;

bool touched() {
  return touchRead(4) < baseline * 0.7;
}

bool bootPressed() {
  return digitalRead(0) == LOW;
}

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  prefs.begin("duel", false);
  bestTime = prefs.getULong("best", 99999);
  delay(2000);
  // do not touch pin 4 during this part
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Reaction duel. Player A: BOOT button. Player B: touch pin 4.");
  Serial.println("Best time on record: " + String(bestTime) + " ms");
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  if (bootPressed() || touched()) {
    Serial.println("Foul! Someone pressed too early.");
    delay(2000);
    return;
  }
  Serial.println("GO!");
  unsigned long start = millis();
  while (!bootPressed() && !touched()) {}
  unsigned long t = millis() - start;
  if (bootPressed()) {
    Serial.println("Player A wins in " + String(t) + " ms");
  } else {
    Serial.println("Player B wins in " + String(t) + " ms");
  }
  if (t < bestTime) {
    bestTime = t;
    prefs.putULong("best", bestTime);
    Serial.println("NEW RECORD! Saved.");
  }
  delay(2000);
}
```

**Mod it**

- Count the wins for each player and print the score.
- Let the loser pick a new top speed: make the wait shorter after each round.
- Show the scores on the web page from Level 12.

### Or build your own

Pick one. You have the rest of the session.

- **Touch the web page.** Take the Level 12 website and make the dice roll when you touch pin 4, not only when someone presses the button.
- **Room chat.** Use the ESP-NOW sketch from the extras to message the board next to you.
- **Signal map.** Log the Wi-Fi strength at six places in the room and plot the numbers.
- **Your own game.** Use any idea from the cheat sheet. A rule, a score and a way to lose.

When time is up, show one neighbour what you made.

---

## Extras: show them if there is time

These are short demos and games. Pick the ones that fit the room and the time you have. Each takes 3 to 10 minutes to show. They use the same parts as the levels, with the board and the Serial Monitor.

| # | Extra | Time | Needs | Teaches |
|---|---|---|---|---|
| 1 | [Design brief generator](#extra-1-design-brief-generator) | 3 min | Nothing | Arrays, random, joining text |
| 2 | [Rock paper scissors](#extra-2-rock-paper-scissors) | 5 min | Nothing | if / else if, comparing text, the % trick |
| 3 | [Building tour (text adventure)](#extra-3-building-tour-text-adventure) | 8 min | Nothing | A variable that remembers where you are, if chains, functions |
| 4 | [Code breaker](#extra-4-code-breaker) | 6 min | Nothing | Arrays, loops, comparing characters |
| 5 | [Memory game](#extra-5-memory-game) | 6 min | Nothing | Strings, functions, a score that grows |
| 6 | [Morse translator](#extra-6-morse-translator) | 6 min | Nothing | Arrays side by side, strings, loops over characters |
| 7 | [Stopwatch](#extra-7-stopwatch) | 4 min | Nothing | A bool as a switch, millis() |
| 8 | [Multiplication table](#extra-8-multiplication-table) | 4 min | Nothing | for, parseInt, loops inside loops (in the mod) |
| 9 | [Board info](#extra-9-board-info) | 3 min | Nothing | Built-in functions, the chip is a computer |
| 10 | [Deep sleep, wake by touch](#extra-10-deep-sleep-wake-by-touch) | 6 min | Nothing. Experimental | Power saving, memory that survives sleep |
| 11 | [Weather](#extra-11-weather) | 8 min | Phone hotspot (2.4 GHz), ArduinoJson 7 | Joining Wi-Fi, getting data from the internet |
| 12 | [Clock](#extra-12-clock) | 5 min | Phone hotspot (2.4 GHz) | NTP, time zones |
| 13 | [Wi-Fi data walk logger](#extra-13-wi-fi-data-walk-logger) | 10 min plus the walk | A Wi-Fi network to measure | Data collection, functions that return a value |
| 14 | [ESP-NOW room chat](#extra-14-esp-now-room-chat) | 8 min | Two or more boards. Experimental | Boards talking directly |
| 15 | [Bluetooth chat (Android only)](#extra-15-bluetooth-chat-android-only) | 6 min | An Android phone. Experimental | Another way boards talk |

## Extra 1: Design brief generator

**Time:** 3 min   **Needs:** Nothing   **Teaches:** Arrays, random, joining text

*Show it when:* Good for a quick laugh before the break. Everyone can use it with no explaining.

### New ideas

- Three arrays hold three kinds of ideas: a site, a programme and a twist.
- `random(0, 5)` picks a number from 0 to 4, which is a place in the array.
- The `+` joins pieces of text into one sentence.
- `while (Serial.available()) Serial.read();` clears whatever was typed, so one press of Enter gives one brief.

### The code

Sketch file: [`sketches/extra_01_design_brief/extra_01_design_brief.ino`](sketches/extra_01_design_brief/extra_01_design_brief.ino)

```cpp
String sites[] = {"a car park", "a rooftop", "a canal bank", "a railway arch", "a school playground"};
String programmes[] = {"a library", "a public bath", "a weather station", "a market hall", "a night shelter"};
String ideas[] = {"made only of timber", "that works without electricity", "that changes with the seasons", "with no walls", "that you can carry"};

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Press Enter for a design brief");
}

void loop() {
  if (Serial.available()) {
    while (Serial.available()) Serial.read();
    Serial.println("Design " + programmes[random(0, 5)] + " on " + sites[random(0, 5)] + ", " + ideas[random(0, 5)] + ".");
  }
}
```

### How it works

- Each array holds five phrases.
- When you press Enter, the board throws away what you typed and builds one sentence from three random picks.
- Every press gives a new brief.

### Try it

1. Open the Serial Monitor. Set the line ending to **Newline**.
2. Press Enter a few times and read the briefs aloud.

### Mod it

- Add three more phrases to each array. Change the `5` to match.
- Add a fourth array, for example a client.
- Print three briefs at once and pick your favourite.

---

## Extra 2: Rock paper scissors

**Time:** 5 min   **Needs:** Nothing   **Teaches:** if / else if, comparing text, the % trick

*Show it when:* Quick, and it makes people argue about whether the board is fair.

### New ideas

- `input == "r"` compares two pieces of text.
- A number stands for each choice: 0 rock, 1 paper, 2 scissors.
- `%` gives the remainder after division. `(you + 1) % 3` is the choice that beats yours, wrapping round after 2 back to 0.
- `return` inside `loop()` stops this round early.

### The code

Sketch file: [`sketches/extra_02_rock_paper_scissors/extra_02_rock_paper_scissors.ino`](sketches/extra_02_rock_paper_scissors/extra_02_rock_paper_scissors.ino)

```cpp
String names[] = {"rock", "paper", "scissors"};

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type r, p or s and press Enter");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    int you = -1;
    if (input == "r") you = 0;
    else if (input == "p") you = 1;
    else if (input == "s") you = 2;
    if (you == -1) {
      Serial.println("Type r, p or s");
      return;
    }
    int board = random(0, 3);
    Serial.println("You: " + names[you] + "   Board: " + names[board]);
    if (you == board) {
      Serial.println("Draw");
    } else if ((you + 1) % 3 == board) {
      Serial.println("Board wins");
    } else {
      Serial.println("You win");
    }
  }
}
```

### How it works

- It reads what you type and turns r, p or s into 0, 1 or 2.
- If it is anything else, it asks again.
- The board picks a random number from 0 to 2.
- Same number is a draw. If the board picked the choice that beats yours, the board wins. Otherwise you win.

### Try it

1. Set the line ending to **Newline**.
2. Type r, p or s and press Enter. Play ten rounds.

### Mod it

- Keep score for you and the board.
- Make the board cheat: let it win 40 percent of the time.
- Add lizard and spock.

---

## Extra 3: Building tour (text adventure)

**Time:** 8 min   **Needs:** Nothing   **Teaches:** A variable that remembers where you are, if chains, functions

*Show it when:* People love it, because it is a building they can explore with words. Let the class suggest rooms.

### New ideas

- `room` is a number that says where you are. This is called **state**.
- A function, `describe()`, prints the text for the current room. We call it every time you move.
- A chain of `else if` checks the room and the command together.
- `next` holds where you would go. If it did not change, the move was not allowed.

### The code

Sketch file: [`sketches/extra_03_text_adventure/extra_03_text_adventure.ino`](sketches/extra_03_text_adventure/extra_03_text_adventure.ino)

```cpp
int room = 0;   // 0 lobby, 1 atrium, 2 roof, 3 basement
String roomNames[] = {"Lobby", "Atrium", "Roof", "Basement"};

void describe() {
  Serial.println("--- " + roomNames[room] + " ---");
  if (room == 0) Serial.println("A cold lobby. Go n to the atrium, or d down to the basement.");
  if (room == 1) Serial.println("A tall atrium full of light. Go s back to the lobby, or u up to the roof.");
  if (room == 2) Serial.println("The roof. The whole city is below you. You found the best view. Go d to come down.");
  if (room == 3) Serial.println("A damp basement with one flickering lamp. Go u back up to the lobby.");
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Building tour. Type n, s, u or d and press Enter.");
  describe();
}

void loop() {
  if (Serial.available()) {
    String c = Serial.readStringUntil('\n');
    c.trim();
    int next = room;
    if (room == 0 && c == "n") next = 1;
    else if (room == 0 && c == "d") next = 3;
    else if (room == 1 && c == "s") next = 0;
    else if (room == 1 && c == "u") next = 2;
    else if (room == 2 && c == "d") next = 1;
    else if (room == 3 && c == "u") next = 0;
    if (next == room) {
      Serial.println("You cannot go that way.");
    } else {
      room = next;
      describe();
    }
  }
}
```

### How it works

- At the start you are in room 0, the lobby.
- Each command works only in the right room. `n` works in the lobby and takes you to the atrium.
- If no rule matched, `next` still equals `room`, so the board says you cannot go that way.
- Otherwise it moves you and describes the new room.

### Try it

1. Set the line ending to **Newline**.
2. Type n, s, u or d and press Enter. Find the roof.

### Mod it

- Add a fifth room, like a courtyard.
- Hide an object in the basement and let the player pick it up.
- Make the roof a locked door that needs the object.

---

## Extra 4: Code breaker

**Time:** 6 min   **Needs:** Nothing   **Teaches:** Arrays, loops, comparing characters

*Show it when:* A good one to play in pairs.

### New ideas

- `int code[3]` is an array of three numbers.
- `guess[i] - '0'` turns the character in the text into the number it stands for.
- A loop checks each position.
- `tries` counts your guesses.

### The code

Sketch file: [`sketches/extra_04_code_breaker/extra_04_code_breaker.ino`](sketches/extra_04_code_breaker/extra_04_code_breaker.ino)

```cpp
int code[3];
int tries = 0;

void newCode() {
  for (int i = 0; i < 3; i++) {
    code[i] = random(0, 10);
  }
  tries = 0;
}

void setup() {
  Serial.begin(115200);
  newCode();
  delay(2000);
  Serial.println("Crack the 3 digit code. Type three digits, like 482.");
}

void loop() {
  if (Serial.available()) {
    String guess = Serial.readStringUntil('\n');
    guess.trim();
    if (guess.length() != 3) {
      Serial.println("Type exactly three digits.");
      return;
    }
    tries++;
    int right = 0;
    for (int i = 0; i < 3; i++) {
      if (guess[i] - '0' == code[i]) right++;
    }
    Serial.println(String(right) + " digit(s) in the right place");
    if (right == 3) {
      Serial.println("Cracked in " + String(tries) + " tries! New code...");
      newCode();
    }
  }
}
```

### How it works

- `newCode()` picks three random digits and resets the tries.
- You type three digits. The board checks each one against the code and counts the ones in the right place.
- It tells you the count. At three it says you cracked it and starts again.

### Try it

1. Set the line ending to **Newline**.
2. Type three digits, like 482, and press Enter. Use the clues.

### Mod it

- Make the code four digits long.
- Also say how many digits are right but in the wrong place.
- Give the player only ten tries.

---

## Extra 5: Memory game

**Time:** 6 min   **Needs:** Nothing   **Teaches:** Strings, functions, a score that grows

*Show it when:* The scrolling trick surprises people.

### New ideas

- `sequence` is a String that grows by one random digit each time through the loop.
- `newRound()` shows the digits, waits, then prints 30 empty lines to push them off the screen.
- `sequenceLen` is the difficulty. It goes up when you are right.

### The code

Sketch file: [`sketches/extra_05_memory_game/extra_05_memory_game.ino`](sketches/extra_05_memory_game/extra_05_memory_game.ino)

```cpp
int sequenceLen = 3;
String sequence = "";

void newRound() {
  sequence = "";
  for (int i = 0; i < sequenceLen; i++) {
    sequence += String(random(1, 10));
  }
  Serial.println("Remember: " + sequence);
  delay(2000 + sequenceLen * 500);
  for (int i = 0; i < 30; i++) {
    Serial.println();   // push the numbers off the screen
  }
  Serial.println("Type the digits you saw:");
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Memory game");
  newRound();
}

void loop() {
  if (Serial.available()) {
    String answer = Serial.readStringUntil('\n');
    answer.trim();
    if (answer == sequence) {
      Serial.println("Correct! One digit longer.");
      sequenceLen++;
    } else {
      Serial.println("Wrong. It was " + sequence + ". Back to 3.");
      sequenceLen = 3;
    }
    newRound();
  }
}
```

### How it works

- The board shows a short string of digits and waits.
- Then it prints empty lines so the digits scroll out of view.
- You type what you remember. If it matches, the next round has one more digit. If not, you start again at three.

### Try it

1. Set the line ending to **Newline**.
2. Read the digits. Wait. Type them back.

### Mod it

- Make the time you get to read shorter each round.
- Use letters as well as digits.
- Print your best streak.

---

## Extra 6: Morse translator

**Time:** 6 min   **Needs:** Nothing   **Teaches:** Arrays side by side, strings, loops over characters

*Show it when:* Short and a little magic. Nice after the code breaker.

### New ideas

- Two lists that line up: `letters` and `morse`. The letter `b` is at place 1 in `letters`, and place 1 in `morse` is `-...`.
- `letters.indexOf(c)` gives the place of a character, or -1 if it is not there.
- `text[i]` is the character at place `i`.
- `toLowerCase()` makes capitals into small letters so they match.

### The code

Sketch file: [`sketches/extra_06_morse_translator/extra_06_morse_translator.ino`](sketches/extra_06_morse_translator/extra_06_morse_translator.ino)

```cpp
String letters = "abcdefghijklmnopqrstuvwxyz";
String morse[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type some words and press Enter");
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    text.trim();
    text.toLowerCase();
    for (int i = 0; i < text.length(); i++) {
      char c = text[i];
      int place = letters.indexOf(c);
      if (place >= 0) {
        Serial.print(morse[place] + " ");
      } else if (c == ' ') {
        Serial.print(" /  ");
      }
    }
    Serial.println();
  }
}
```

### How it works

- It reads a line and turns it to lower case.
- A loop goes through the characters one at a time.
- For each letter it finds its place and prints the matching code.
- A space prints a slash between words.

### Try it

1. Set the line ending to **Newline**.
2. Type `sos` and then `hello world`.

### Mod it

- Add the digits 0 to 9.
- Go the other way: type dots and dashes and print the letter.
- Print the dots and dashes slowly, with `delay()` between them.

---

## Extra 7: Stopwatch

**Time:** 4 min   **Needs:** Nothing   **Teaches:** A bool as a switch, millis()

*Show it when:* Fun as a competition: who can stop it closest to ten seconds without looking?

### New ideas

- `running` is a `bool`. It switches between true and false each press. This is a switch variable.
- `startTime` remembers `millis()` at the moment you started.
- `elapsed / 1000.0` divides by a decimal number so the answer has decimals.
- `String(x, 2)` prints x with two decimals.

### The code

Sketch file: [`sketches/extra_07_stopwatch/extra_07_stopwatch.ino`](sketches/extra_07_stopwatch/extra_07_stopwatch.ino)

```cpp
bool running = false;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  delay(2000);
  Serial.println("Press BOOT to start and stop the stopwatch");
}

void loop() {
  if (digitalRead(0) == LOW) {
    if (!running) {
      running = true;
      startTime = millis();
      Serial.println("Started");
    } else {
      running = false;
      unsigned long elapsed = millis() - startTime;
      Serial.println("Time: " + String(elapsed / 1000.0, 2) + " s");
    }
    delay(300);
    while (digitalRead(0) == LOW) {}
  }
}
```

### How it works

- Press BOOT. If it was not running, save the time and say Started.
- Press again. It subtracts the start from `millis()` and prints the seconds.
- The wait at the end stops one press counting twice.

### Try it

1. Press BOOT to start. Press BOOT to stop.

### Mod it

- Add a lap button using a second variable.
- Print minutes and seconds.
- Challenge a neighbour to stop it at exactly 5 seconds.

---

## Extra 8: Multiplication table

**Time:** 4 min   **Needs:** Nothing   **Teaches:** for, parseInt, loops inside loops (in the mod)

*Show it when:* Use it to show a loop inside a loop. It is the simplest way to see the idea.

### New ideas

- `Serial.parseInt()` reads a number you typed.
- A `for` loop from 1 to 10 prints one row per round.
- `n * i` multiplies.

### The code

Sketch file: [`sketches/extra_08_multiplication_table/extra_08_multiplication_table.ino`](sketches/extra_08_multiplication_table/extra_08_multiplication_table.ino)

```cpp
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type a number and press Enter");
}

void loop() {
  if (Serial.available()) {
    int n = Serial.parseInt();
    while (Serial.available()) Serial.read();
    for (int i = 1; i <= 10; i++) {
      Serial.println(String(n) + " x " + String(i) + " = " + String(n * i));
    }
  }
}
```

### How it works

- It waits for a number.
- It throws away anything else left in the line.
- It prints the ten rows of that number's table.

### Try it

1. Set the line ending to **Newline**.
2. Type 7 and press Enter.

### Mod it

- Print the whole 10 by 10 table with one loop inside another loop.
- Print the times table backwards, from 10 to 1.
- Make it print squares instead.

---

## Extra 9: Board info

**Time:** 3 min   **Needs:** Nothing   **Teaches:** Built-in functions, the chip is a computer

*Show it when:* Short, and it makes the chip feel like a real computer.

### New ideas

- `ESP` is an object that knows about the chip. `ESP.getChipModel()` asks it questions.
- The flash size is in bytes. Dividing by 1048576 gives megabytes.
- `temperatureRead()` is a temperature sensor inside the chip. It reads the chip, not the room, so it is higher than the air.
- A MAC address is a number unique to each board.

### The code

Sketch file: [`sketches/extra_09_board_info/extra_09_board_info.ino`](sketches/extra_09_board_info/extra_09_board_info.ino)

```cpp
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Chip: " + String(ESP.getChipModel()));
  Serial.println("Cores: " + String(ESP.getChipCores()));
  Serial.println("CPU speed: " + String(ESP.getCpuFreqMHz()) + " MHz");
  Serial.println("Flash size: " + String(ESP.getFlashChipSize() / 1048576) + " MB");
  Serial.println("Free memory: " + String(ESP.getFreeHeap() / 1024) + " KB");
  Serial.println("Chip temperature: " + String(temperatureRead()) + " C");
  Serial.println("MAC address: " + WiFi.macAddress());
}

void loop() {}
```

### How it works

- In `setup()` it asks the chip seven questions and prints each answer.
- There is no repeating, so `loop()` is empty.

### Try it

1. Upload and read the Serial Monitor.
2. Compare your numbers with a neighbour. Which are the same? Which are different?

### Mod it

- Print the temperature every second and warm the chip with a finger.
- Print the uptime with `millis()`.
- Print the free memory again after 10 seconds. Does it change?

---

## Extra 10: Deep sleep, wake by touch

**Time:** 6 min   **Needs:** Nothing. Experimental   **Teaches:** Power saving, memory that survives sleep

*Show it when:* A good way to talk about battery life and long-running projects. Test it first.

### New ideas

- Deep sleep switches nearly everything off. The board draws very little power.
- `RTC_DATA_ATTR` marks a variable that stays alive during sleep. Normal variables are lost.
- `touchSleepWakeUpEnable(4, threshold)` says: wake when pin 4 is touched.
- `esp_deep_sleep_start()` goes to sleep. When the board wakes, it starts again from `setup()`.

### The code

Sketch file: [`sketches/extra_10_deep_sleep_touch/extra_10_deep_sleep_touch.ino`](sketches/extra_10_deep_sleep_touch/extra_10_deep_sleep_touch.ino)

```cpp
RTC_DATA_ATTR int wakeCount = 0;   // this value survives deep sleep
const int threshold = 40;          // set this between your untouched and touched values

void setup() {
  Serial.begin(115200);
  delay(2000);
  wakeCount++;
  Serial.println("Wake number " + String(wakeCount));
  Serial.println("Going to sleep in 3 seconds. Touch pin 4 to wake me.");
  delay(3000);
  touchSleepWakeUpEnable(4, threshold);
  esp_deep_sleep_start();
}

void loop() {}
```

### How it works

- The board adds one to `wakeCount` and prints it.
- It waits three seconds, then sleeps.
- A touch wakes it. It runs `setup()` again, and `wakeCount` is one higher.

### Try it

1. Upload and watch the Serial Monitor. After it sleeps the monitor may disconnect. That is normal.
2. Touch pin 4. The board wakes and prints the new count.
3. Check `threshold`: it must be between your untouched and touched readings from Level 9. If the board wakes straight away, make it smaller. If it never wakes, make it bigger.

### Mod it

- Wake up every 10 seconds on a timer instead: `esp_sleep_enable_timer_wakeup(10 * 1000000);`.
- Print why it woke up with `esp_sleep_get_wakeup_cause()`.

---

## Extra 11: Weather

**Time:** 8 min   **Needs:** Phone hotspot (2.4 GHz), ArduinoJson 7   **Teaches:** Joining Wi-Fi, getting data from the internet

*Show it when:* A good moment: the board looks out of the window.

### New ideas

- `WiFi.begin(name, password)` joins a network. It takes a moment, so we wait in a loop and give up after about 15 seconds.
- `HTTPClient` asks a website for data. `http.GET()` returns a status code. 200 means all good.
- `client.setInsecure()` skips the check of the website's certificate. That is fine for a class demo and not for anything private.
- The weather service replies in JSON. `ArduinoJson` reads it, like in Level 10.
- The numbers `51.52` and `-0.13` are London's latitude and longitude.

### The code

Sketch file: [`sketches/extra_11_weather/extra_11_weather.ino`](sketches/extra_11_weather/extra_11_weather.ino)

```cpp
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_HOTSPOT";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);
  int waited = 0;
  while (WiFi.status() != WL_CONNECTED && waited < 30) {
    delay(500);
    Serial.print(".");
    waited++;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Could not connect. Check the name, the password and that the hotspot is 2.4 GHz.");
    return;
  }
  Serial.println("Connected. IP: " + WiFi.localIP().toString());

  WiFiClientSecure client;
  client.setInsecure();   // skip certificate checking. Fine for a classroom demo.
  HTTPClient http;
  http.begin(client, "https://api.open-meteo.com/v1/forecast?latitude=51.52&longitude=-0.13&current=temperature_2m,wind_speed_10m");
  int code = http.GET();
  if (code == 200) {
    JsonDocument doc;
    deserializeJson(doc, http.getString());
    float temp = doc["current"]["temperature_2m"];
    float wind = doc["current"]["wind_speed_10m"];
    Serial.println("London now: " + String(temp) + " C, wind " + String(wind) + " km/h");
  } else {
    Serial.println("Request failed with code " + String(code));
  }
  http.end();
}

void loop() {}
```

### How it works

- It joins your hotspot.
- It sends one request to Open-Meteo, a free weather service with no account.
- It reads the temperature and wind from the reply and prints them.

### Try it

1. Turn on your phone hotspot. Set it to 2.4 GHz.
2. Type your hotspot name and password into the sketch.
3. Upload and read the Serial Monitor.

### Mod it

- Change the latitude and longitude to another city and compare.
- Ask the service for more things: add `,relative_humidity_2m` to the web address and read it.
- Check the weather every minute in `loop()`.

### If it does not work

- "Could not connect": check the name and password, and that the hotspot is on 2.4 GHz.
- Compile error about `JsonDocument`: install ArduinoJson version 7.

---

## Extra 12: Clock

**Time:** 5 min   **Needs:** Phone hotspot (2.4 GHz)   **Teaches:** NTP, time zones

*Show it when:* Quick. It sets up a talk about how a board with no clock still knows what time it is.

### New ideas

- **NTP** is a way for devices to ask the internet for the exact time.
- `configTzTime("GMT0BST,M3.5.0/1,M10.5.0", "pool.ntp.org")` gives the board two things: the rules for London time, including summer time, and a server to ask.
- `getLocalTime(&now)` fills `now` with the date and time. It returns false if the time is not ready yet.
- `"%A %d %B %Y, %H:%M:%S"` is a pattern. Each `%` letter is a part of the time.

### The code

Sketch file: [`sketches/extra_12_clock/extra_12_clock.ino`](sketches/extra_12_clock/extra_12_clock.ino)

```cpp
#include <WiFi.h>
#include <time.h>

const char* ssid = "YOUR_HOTSPOT";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  delay(2000);
  WiFi.begin(ssid, password);
  int waited = 0;
  while (WiFi.status() != WL_CONNECTED && waited < 30) {
    delay(500);
    Serial.print(".");
    waited++;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Could not connect.");
    return;
  }
  Serial.println("Connected");
  // London time, including summer time changes
  configTzTime("GMT0BST,M3.5.0/1,M10.5.0", "pool.ntp.org");
}

void loop() {
  struct tm now;
  if (getLocalTime(&now)) {
    Serial.println(&now, "%A %d %B %Y, %H:%M:%S");
  } else {
    Serial.println("Waiting for the time...");
  }
  delay(1000);
}
```

### How it works

- It joins the hotspot, then sets the time rules.
- Every second it checks the time and prints it.
- For the first moment it prints "Waiting for the time...".

### Try it

1. Fill in your hotspot name and password.
2. Upload and read the Serial Monitor.

### Mod it

- Print only the hour and minute: `"%H:%M"`.
- Change the rules to another city's.
- Print "Time for a break!" at a time you pick.

### If it does not work

- "Could not connect": check the hotspot name, password and 2.4 GHz.

---

## Extra 13: Wi-Fi data walk logger

**Time:** 10 min plus the walk   **Needs:** A Wi-Fi network to measure   **Teaches:** Data collection, functions that return a value

*Show it when:* The best extra for this course. It turns the board into a way to measure a building. Send the numbers into Grasshopper afterwards.

### New ideas

- `signalOf(name)` is a function that gives back a number. It scans, looks for the network by name, and returns its strength.
- `return 0` means "not found". The strength of a real network is never 0.
- The output is **CSV**: values separated by commas. A spreadsheet opens it directly.
- `spot` counts your places.

### The code

Sketch file: [`sketches/extra_13_data_walk_logger/extra_13_data_walk_logger.ino`](sketches/extra_13_data_walk_logger/extra_13_data_walk_logger.ino)

```cpp
#include <WiFi.h>

const char* target = "YOUR_NETWORK_NAME";   // the network you want to measure
int spot = 0;

int signalOf(const char* name) {
  int found = WiFi.scanNetworks();
  for (int i = 0; i < found; i++) {
    if (WiFi.SSID(i) == name) return WiFi.RSSI(i);
  }
  return 0;   // not found
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  pinMode(0, INPUT_PULLUP);
  delay(2000);
  Serial.println("Data walk. Stand at a spot and press BOOT to log it.");
  Serial.println("spot,rssi_dBm");
}

void loop() {
  if (digitalRead(0) == LOW) {
    spot++;
    int strength = signalOf(target);
    if (strength == 0) {
      Serial.println(String(spot) + ",not found");
    } else {
      Serial.println(String(spot) + "," + String(strength));
    }
    delay(300);
    while (digitalRead(0) == LOW) {}
  }
}
```

### How it works

- Set `target` to the exact name of a network.
- You stand at a spot and press BOOT. The board scans, finds the network and prints a line like `3,-67`.
- Walk to the next spot and press again.
- When you finish, copy the lines from the Serial Monitor into a spreadsheet.

### Try it

1. Power the board from a laptop or power bank. Choose a network you can reach in many places.
2. Log six spots.
3. Paste the lines into a spreadsheet and chart them.

### Mod it

- Mark the spots on a plan of the room, and colour them by strength.
- Log several networks at once.
- Add the touch reading as a second column.

### If it does not work

- "not found": the name in `target` must match exactly, including capitals.

---

## Extra 14: ESP-NOW room chat

**Time:** 8 min   **Needs:** Two or more boards. Experimental   **Teaches:** Boards talking directly

*Show it when:* Great for the last five minutes when everyone has a board running. The room talks.

### New ideas

- **ESP-NOW** lets boards send short messages straight to each other with no router and no internet.
- The address `FF:FF:FF:FF:FF:FF` is **broadcast**. It means everyone, so you do not need to know any board's address.
- A **callback** is a function you give to the library. It runs by itself when something arrives. `onReceive` runs whenever a message comes in.
- `esp_now_send` sends the bytes of your text.

### The code

Sketch file: [`sketches/extra_14_espnow_room_chat/extra_14_espnow_room_chat.ino`](sketches/extra_14_espnow_room_chat/extra_14_espnow_room_chat.ino)

```cpp
#include <WiFi.h>
#include <esp_now.h>

uint8_t everyone[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};   // broadcast: every board hears it
String myName = "Ada";                                       // change this

void onReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  String msg = "";
  for (int i = 0; i < len; i++) {
    msg += (char)data[i];
  }
  Serial.println(msg);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(2000);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW failed to start");
    return;
  }
  esp_now_register_recv_cb(onReceive);
  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, everyone, 6);
  peer.channel = 0;
  peer.encrypt = false;
  esp_now_add_peer(&peer);
  Serial.println("Room chat. Type a message and press Enter.");
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    text.trim();
    String msg = myName + ": " + text;
    esp_now_send(everyone, (const uint8_t *)msg.c_str(), msg.length());
    Serial.println("(sent) " + msg);
  }
}
```

### How it works

- Each board starts ESP-NOW and registers `onReceive`.
- When you type a line, it adds your name and sends it to everyone.
- Every other board that runs this sketch prints the message in its Serial Monitor.

### Try it

1. Everyone sets `myName` to their own name and uploads.
2. Keep the Serial Monitor open and type. Messages from the room appear.

### Mod it

- Send a dice roll instead of text when you press BOOT.
- Send your touch reading every second and print the most recent from each person.
- Add a command: if the message starts with `!`, do something.

### If it does not work

- "ESP-NOW failed to start": press EN and try again.
- It does not compile: this sketch is for package version 3.3. Check Boards Manager.

---

## Extra 15: Bluetooth chat (Android only)

**Time:** 6 min   **Needs:** An Android phone. Experimental   **Teaches:** Another way boards talk

*Show it when:* Only if there are Android phones in the room.

### New ideas

- The board can act as a **Bluetooth serial** device. Anything you send to one side comes out of the other.
- `SerialBT` works just like `Serial`, but over Bluetooth.
- Whatever comes in on one is written out on the other, one character at a time.

### The code

Sketch file: [`sketches/extra_15_bluetooth_chat/extra_15_bluetooth_chat.ino`](sketches/extra_15_bluetooth_chat/extra_15_bluetooth_chat.ino)

```cpp
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("RC7-board-yourname");   // change this name
  delay(2000);
  Serial.println("Pair your Android phone with RC7-board-yourname.");
  Serial.println("Then open a Bluetooth serial terminal app and connect.");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
}
```

### How it works

- The board starts Bluetooth with a name.
- In `loop()`, a character from the Serial Monitor goes to the phone, and a character from the phone goes to the Serial Monitor.

### Try it

1. Set the board name to something with your own name.
2. Pair your Android phone with it in the phone's Bluetooth settings.
3. Open a Bluetooth serial terminal app, connect, and type.

### Mod it

- Send "Hello" to the phone when it connects.
- Make the phone able to roll your dice by sending the letter `d`.

### If it does not work

- iPhones cannot connect to this kind of Bluetooth.
- If the sketch is too big, choose Tools > Partition Scheme > Huge APP.

---

## When it breaks

### Uploading and the Serial Monitor

| What you see | What it usually means | Fix |
|---|---|---|
| `expected ';' before ...` | A missing semicolon on the line above | Add it at the end of that line |
| `'xyz' was not declared in this scope` | A typo or the wrong capital letter | Check the spelling. `Serial`, not `serial` |
| `Connecting........` then it fails | The board is not in upload mode | Hold the **BOOT** button while it says Connecting |
| No port under Tools > Port | A cable that only charges, or a missing driver | Try another cable. Install the CP210x driver |
| Rubbish characters in the Serial Monitor | The baud rate does not match | Set 115200 in the Serial Monitor |
| Nothing prints at the start | The sketch printed before the Serial Monitor was ready | Press **EN** on the board with the Serial Monitor open. Add `delay(2000);` after `Serial.begin(115200);` |
| No answer to what you type | The line ending is wrong | Set **Newline** at the bottom of the Serial Monitor |

### Touch, libraries and Wi-Fi

| What you see | What it usually means | Fix |
|---|---|---|
| Touch does nothing | The reading barely moves | Check it in the Serial Plotter. Use a wire and foil for a bigger pad |
| Touch fires by itself | Your hand was near the pin at start | Press **EN** and keep away for two seconds |
| `fatal error: XYZ.h: No such file or directory` | The library is not installed | Sketch > Include Library > Manage Libraries |
| Wi-Fi never connects | Wrong password, or the hotspot is 5 GHz | Check both. Switch the hotspot to 2.4 GHz |
| Cannot join eduroam | It needs a personal login | Use a phone hotspot or the board's own network |
| The page does not load on the phone | You typed `https://` | Use `http://192.168.4.1` |
| Sketch too big to upload | Bluetooth needs more space | Tools > Partition Scheme > **Huge APP** |

---

## Cheat sheet

| Idea | Looks like | What it does |
|---|---|---|
| Variable | `int lives = 3;` | Stores a value in a named box |
| Print | `Serial.println(x);` | Sends x to the Serial Monitor |
| Wait | `delay(500);` | Pauses for 500 milliseconds |
| Loop | `for (int i = 0; i < 5; i++) { }` | Repeats a block five times |
| Decision | `if (x > 3) { } else { }` | Chooses between two paths |
| Function | `void shout(String w) { }` | Names steps you can reuse |
| Array | `String a[] = {"x", "y"};` | A numbered list. `a[0]` is "x" |
| Input | `Serial.readStringUntil('\n')` | Reads a line you typed |
| Button | `digitalRead(0) == LOW` | True while BOOT is pressed |
| Time | `millis()` | Milliseconds since the board started |
| Random | `random(1, 7)` | A number from 1 to 6 |
| Touch | `touchRead(4)` | A number that drops when you touch pin 4 |
| Scale | `map(v, 0, 100, 0, 40)` | Turns 0 to 100 into 0 to 40 |
| Limit | `constrain(v, 0, 40)` | Keeps v between 0 and 40 |
| Library | `#include <WiFi.h>` | Adds someone else's commands |
| Save | `prefs.putULong("best", t);` | Saves a number that survives a reset |
| Wi-Fi scan | `WiFi.scanNetworks();` | Counts the networks around you |
| Web server | `server.on("/", handleRoot);` | Runs a function when a browser asks for a page |

---

## Credits

The level order for the first part is adapted from the Pervasive Urbanism Arduino coding tutorial (Skills Module 2, Prosthetic Clouds, RC15, The Bartlett School of Architecture).

The sketches are rewritten for the ESP32. The games, challenges, touch, library and Wi-Fi levels are new for this course.

Weather data in the extras comes from [Open-Meteo](https://open-meteo.com).

Arduino reference: [docs.arduino.cc](https://docs.arduino.cc)
ESP32 package documentation: [docs.espressif.com/projects/arduino-esp32](https://docs.espressif.com/projects/arduino-esp32)
