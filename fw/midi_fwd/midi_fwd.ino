// forwarding midi message from UART to USB MIDI
//* Ras Pi Pico/RP2040 - Seeed XIAO_RP2040 -> ok.
//  Ras Pi Pico/RP2040 - Waveshare RP2040 Zero 
//  esp32 - XIAO_ESP32C3

// Tools > USB Stack > TinyUSB

// MIDI Library by Francois Best, lathoub

// Adafruit_TinyUSB_Arduino/examples/MIDI/midi_test
// https://github.com/FortySevenEffects/arduino_midi_library/blob/master/examples/DualMerger/DualMerger.ino
//   https://github.com/FortySevenEffects/arduino_midi_library

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include <MIDI.h>

Adafruit_USBD_MIDI usb_midi;

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, midiIN);
MIDI_CREATE_INSTANCE(Adafruit_USBD_MIDI, usb_midi, midiOUT);

void setup()
{
#if defined(ARDUINO_ARCH_MBED) && defined(ARDUINO_ARCH_RP2040)
  // Manual begin() is required on core without built-in support for TinyUSB such as mbed rp2040
  TinyUSB_Device_Init(0);
#endif

  //pinMode(LED_BUILTIN, OUTPUT);

  midiIN.begin(MIDI_CHANNEL_OMNI);
  midiOUT.begin(MIDI_CHANNEL_OMNI); // Ch#

  //Serial.begin(115200); // for USB-MIDI
  //Serial1.begin(31250); // from UART/RX

  // wait until device mounted
  while( !TinyUSBDevice.mounted() ) delay(1);
}

void loop()
{
  if (midiIN.read()) {
    midiOUT.send(
      midiIN.getType(),
      midiIN.getData1(),
      midiIN.getData2(),
      midiIN.getChannel()
    );
  }  
}
