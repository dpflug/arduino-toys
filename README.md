# My Arduino Toys #

## blinks ##
This is just me playing with blinking. On the Digispark, the LED's on an analog pin, so I can simulate a breathing LED. Yay!

I also created a timing array and a procedure to take that and blink through the timings.

## blinks2 ##
Simpler blinking. I don't remember why I made this, now.

## timing ##
Experiments with premature optimization. Also, just curiosity.

For the record, based on this test, keeping a variable updated in memory is faster than reading from the pins. But not much.

## blinks3 ##
Now we're getting fancy. Accept a list of timings from the computer via Serial, then blink that pattern.

### Possible extensions: ###
- Add support for choosing a pin and an analog level. Probably easiest to just use Firmata at that point, though.

## hvsp-digispark ##
This is a High Voltage Serial Programming sketch for the Digispark. I need to rescue one of mine, so I'll be using this at some point. NOT MY CODE!
