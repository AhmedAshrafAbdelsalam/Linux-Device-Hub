#pragma once

#include <cstring>
#include <string>

enum class DeviceType {
#ifdef JOYSTICK
  Joystick,
#endif
#ifdef POWERLED
  PowerLed,
#endif
#ifdef BLUETOOTH
  Bluetooth
#endif
};
#ifdef JOYSTICK
/*              Joystick
 *
 * Joystick event types */
/*************************************/
#define JS_EVENT_BUTTON 0x01
#define JS_EVENT_AXIS 0x02
#define JS_EVENT_INIT 0x80

/* AXIS event numbers */
/*************************************/
#define LEFT_ANALOG_HOR 0x00
#define LEFT_ANALOG_VER 0x01
#define RIGHT_ANALOG_HOR 0x03
#define RIGHT_ANALOG_VER 0x02
#define BUTTON_HOR 0x04
#define BUTTON_VER 0x05

/* BUTTONS event numbers */
/*************************************/
#define TRIANGLE_BUTTON 0x00
#define CIRCLE_BUTTON 0x01
#define X_BUTTON 0x02
#define SQUARE_BUTTON 0x03
#define L1_BUTTON 0x04
#define R1_BUTTON 0x05
#define L2_BUTTON 0x06
#define R2_BUTTON 0x07
#define SELECT_BUTTON 0x08
#define START_BUTTON 0x09
#define LEFT_BUTTON 0x0A
#define RIGHT_BUTTON 0x0B

/* Joystick event values */
/*************************************/
#define UNPRESSED 0x00
#define MAX_LEFT_UP 0x7FFF
#define MAX_RIGHT_DOWN -0x7FFF

/// @brief Joystick type
struct JoystickEvent {
  unsigned int time;
  short value;
  unsigned char type;
  unsigned char number;
};
#endif
#ifdef POWERLED
/*              PowerLed
 *
 * PowerLed values */
/*************************************/
#define PWR_LED_ON "0"
#define PWR_LED_OFF "255"

/// @brief PowerLed type
using PowerLedEvent = const char*;
#endif