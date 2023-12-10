
#define MESSAGE "HELLO WORLD"

const int UNIT = 250;

const int DIT_TIME = UNIT;
const int DAH_TIME = 3 * UNIT;
const int INTRA_CHARACTER_TIME = UNIT;
const int INTER_CHARACTER_TIME = 3 * UNIT;
const int WORD_SPACE_TIME = 7 * UNIT;

const int MESSAGE_DELAY = 5000;

const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

const char *MORSE[] = {
".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--..",
".----",
"..---",
"...--",
"....-",
".....",
"-....",
"--...",
"---..",
"----.",
"-----"
};

char *char_to_morse(char c) {
    int i = 0;
    while (ALPHABET[i] != 0) {
        if (ALPHABET[i] == c) {
           return MORSE[i];
        }
        i++;
    }
    return "";
}

void print_char(char c) {
    if (c == ' ') {
        delay(WORD_SPACE_TIME);
        return;
    }
    char *morse = char_to_morse(c);
    int i = 0;
    while (morse[i] != 0) {
        if (morse[i] == '.') {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(DIT_TIME);
            digitalWrite(LED_BUILTIN, LOW);
        }
        else {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(DAH_TIME);
            digitalWrite(LED_BUILTIN, LOW);
        }
        delay(INTRA_CHARACTER_TIME);
        i++;
    }
    delay(INTER_CHARACTER_TIME);
}

void print_string(char *s) {
    int i = 0;
    while (s[i] != 0) {
        print_char(s[i]);
        i++;
    }
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    print_string(MESSAGE);
    delay(MESSAGE_DELAY);
}

