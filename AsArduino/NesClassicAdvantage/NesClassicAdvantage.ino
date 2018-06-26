/*
* Nintendo Classic Advantage Controller - Nintendo Advantage inspired 
* controller for the NES Classic Mini!
* Copyright (c) 2017 bbtinkerer
* 
* Based off of Wii RetroPad Adapter by Bruno Freitas - 
* https://github.com/bootsector/wii-retropad-adapter
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*Beginning of Auto generated code by Atmel studio */
#include <Arduino.h>
/*End of auto generated code by Atmel studio */

#include "WMExtension.h"
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

// controller buttons
// pin numbers according to Arduino pin numbering
#define LEFT_BUTTON_PIN 2
#define RIGHT_BUTTON_PIN 3
#define UP_BUTTON_PIN 4
#define DOWN_BUTTON_PIN 5

#define A_BUTTON_PIN 6
#define B_BUTTON_PIN 7
#define X_BUTTON_PIN 8
#define Y_BUTTON_PIN 9

// Select, Start
#define MINUS_BUTTON_PIN 10
#define PLUS_BUTTON_PIN 11

#define L_BUTTON_PIN 12
#define R_BUTTON_PIN 13

// L has an optional input due to how the UD-DB15 works
// This is on the analog input
#define L_BUTTON_PIN_OPT A0


// Classic Controller Buttons
int bdl = 0; // D-Pad Left state
int bdr = 0; // D-Pad Right state
int bdu = 0; // D-Pad Up state
int bdd = 0; // D-Pad Down state
int ba = 0; // A button state
int bb = 0; // B button state
int bx = 0; // X button state
int by = 0; // Y button state
int bl = 0; // L button state
int br = 0; // R button state
int bm = 0; // MINUS button state
int bp = 0; // PLUS button state
int bhome = 0; // HOME button state
int bzl = 0; // ZL button state
int bzr = 0; // ZR button state
int lt = 0; // L analog value
int rt = 0; // R analog value

// Analog Buttons
byte lx = WMExtension::get_calibration_byte(2);
byte ly = WMExtension::get_calibration_byte(5);
byte rx = WMExtension::get_calibration_byte(8);
byte ry = WMExtension::get_calibration_byte(11);

void setup() {
   // Set PushButton pins as input, turning pull-up on
   pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
   pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
   pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
   pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);
   
   pinMode(A_BUTTON_PIN, INPUT_PULLUP);
   pinMode(B_BUTTON_PIN, INPUT_PULLUP);
   pinMode(X_BUTTON_PIN, INPUT_PULLUP);
   pinMode(Y_BUTTON_PIN, INPUT_PULLUP);
   
   pinMode(MINUS_BUTTON_PIN, INPUT_PULLUP);
   pinMode(PLUS_BUTTON_PIN, INPUT_PULLUP);

   pinMode(L_BUTTON_PIN, INPUT_PULLUP);
   pinMode(R_BUTTON_PIN, INPUT_PULLUP);
   pinMode(L_BUTTON_PIN_OPT, INPUT_PULLUP);
        
   digitalWrite(LEFT_BUTTON_PIN, HIGH);
   digitalWrite(RIGHT_BUTTON_PIN, HIGH);
   digitalWrite(UP_BUTTON_PIN, HIGH);
   digitalWrite(DOWN_BUTTON_PIN, HIGH);
   
   digitalWrite(A_BUTTON_PIN, HIGH);
   digitalWrite(B_BUTTON_PIN, HIGH);
   digitalWrite(X_BUTTON_PIN, HIGH);
   digitalWrite(Y_BUTTON_PIN, HIGH);
   
   digitalWrite(MINUS_BUTTON_PIN, HIGH);
   digitalWrite(PLUS_BUTTON_PIN, HIGH);
   
   digitalWrite(L_BUTTON_PIN, HIGH);
   digitalWrite(R_BUTTON_PIN, HIGH);
   digitalWrite(L_BUTTON_PIN_OPT, HIGH);

  // If booted when SNES classic boots, we don't have input unless we pause for this.
  delay(3000);
   
   // Prepare wiimote communications
   WMExtension::init();
}

void loop() {
   bdl = !digitalRead(LEFT_BUTTON_PIN);
   bdr = !digitalRead(RIGHT_BUTTON_PIN);
   bdu = !digitalRead(UP_BUTTON_PIN);
   bdd = !digitalRead(DOWN_BUTTON_PIN);
   
   ba = !digitalRead(A_BUTTON_PIN);
   bb = !digitalRead(B_BUTTON_PIN);
   bx = !digitalRead(X_BUTTON_PIN);
   by = !digitalRead(Y_BUTTON_PIN);
   
   bm = !digitalRead(MINUS_BUTTON_PIN);
   bp = !digitalRead(PLUS_BUTTON_PIN);

   // L is special
   bl = (!digitalRead(L_BUTTON_PIN)) || (!digitalRead(L_BUTTON_PIN_OPT));
   br = !digitalRead(R_BUTTON_PIN);
   
   WMExtension::set_button_data(
     bdl, bdr, bdu, bdd, 
     ba, bb, bx, by, 
     bl, br,
     bm, bp, 
     bhome, 
     lx, ly, rx, ry, bzl, bzr, 
     lt, rt);
}




