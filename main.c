#include <stdio.h>
#include <stdint.h>
#include "HIDReportData.h"
#define KEYBOARD_REPORT_BITS (32 - 2)
/*
 * HID report descriptors
 */
const uint8_t HIDReport[] = {
    HID_RI_USAGE_PAGE(8, 0x01),00,        // Generic Desktop
    
    HID_RI_USAGE(8, 0x06),00,             // Keyboard
    HID_RI_COLLECTION(8, 0x01),00,        // Application

        HID_RI_REPORT_ID(8, 1),00,

        // Modifiers (8 bits)
        HID_RI_USAGE_PAGE(8, 0x07),00,    // Keyboard/Keypad
        HID_RI_USAGE_MINIMUM(8, 0xE0),00, // Keyboard Left Control
        HID_RI_USAGE_MAXIMUM(8, 0xE7),00, // Keyboard Right GUI
        HID_RI_LOGICAL_MINIMUM(8, 0x00),00,
        HID_RI_LOGICAL_MAXIMUM(8, 0x01),00,
        HID_RI_REPORT_COUNT(8, 0x08),00,
        HID_RI_REPORT_SIZE(8, 0x01),00,
        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),00,
        // Reserved (1 byte)
        HID_RI_REPORT_COUNT(8, 0x01),00,
        HID_RI_REPORT_SIZE(8, 0x08),00,
        HID_RI_INPUT(8, HID_IOF_CONSTANT),00,
        // Keycodes (6 bytes)
        HID_RI_USAGE_PAGE(8, 0x07),00,    // Keyboard/Keypad
        HID_RI_USAGE_MINIMUM(8, 0x00),00,
        HID_RI_USAGE_MAXIMUM(8, 0xFF),00,
        HID_RI_LOGICAL_MINIMUM(8, 0x00),00,
        HID_RI_LOGICAL_MAXIMUM(16, 0x00FF),00,
        HID_RI_REPORT_COUNT(8, 0x06),00,
        HID_RI_REPORT_SIZE(8, 0x08),00,
        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_ARRAY | HID_IOF_ABSOLUTE),00,

        // Status LEDs (5 bits)
        HID_RI_USAGE_PAGE(8, 0x08),00,    // LED
        HID_RI_USAGE_MINIMUM(8, 0x01),00, // Num Lock
        HID_RI_USAGE_MAXIMUM(8, 0x05),00, // Kana
        HID_RI_LOGICAL_MINIMUM(8, 0x00),00,
        HID_RI_LOGICAL_MAXIMUM(8, 0x01),00,
        HID_RI_REPORT_COUNT(8, 0x05),00,
        HID_RI_REPORT_SIZE(8, 0x01),00,
        HID_RI_OUTPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE | HID_IOF_NON_VOLATILE),00,
        // LED padding (3 bits)
        HID_RI_REPORT_COUNT(8, 0x01),00,
        HID_RI_REPORT_SIZE(8, 0x03),00,
        HID_RI_OUTPUT(8, HID_IOF_CONSTANT),00,
    HID_RI_END_COLLECTION(0),00,

    HID_RI_USAGE_PAGE(8, 0x01),00,            // Generic Desktop
    HID_RI_USAGE(8, 0x02),00,                 // Mouse
    HID_RI_COLLECTION(8, 0x01),00,            // Application

        HID_RI_REPORT_ID(8, 2),00,
        HID_RI_USAGE(8, 0x01),00,             // Pointer
        HID_RI_COLLECTION(8, 0x00),00,        // Physical
            // Buttons (8 bits)
            HID_RI_USAGE_PAGE(8, 0x09),00,    // Button
            HID_RI_USAGE_MINIMUM(8, 0x01),00, // Button 1
            HID_RI_USAGE_MAXIMUM(8, 0x08),00, // Button 8
            HID_RI_LOGICAL_MINIMUM(8, 0x00),00,
            HID_RI_LOGICAL_MAXIMUM(8, 0x01),00,
            HID_RI_REPORT_COUNT(8, 0x08),00,
            HID_RI_REPORT_SIZE(8, 0x01),00,
            HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),00,


            // Boot protocol XY ignored in Report protocol
            HID_RI_REPORT_COUNT(8, 0x02),00,
            HID_RI_REPORT_SIZE(8, 0x08),00,
            HID_RI_INPUT(8, HID_IOF_CONSTANT),00,

            // X/Y position (2 or 4 bytes)
            HID_RI_USAGE_PAGE(8, 0x01),00,    // Generic Desktop
            HID_RI_USAGE(8, 0x30),00,         // X
            HID_RI_USAGE(8, 0x31),00,         // Y

            HID_RI_LOGICAL_MINIMUM(16, -32767),00,
            HID_RI_LOGICAL_MAXIMUM(16,  32767),00,
            HID_RI_REPORT_COUNT(8, 0x02),00,
            HID_RI_REPORT_SIZE(8, 0x10),00,
            HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),00,

            // Vertical wheel (1 byte)
            HID_RI_USAGE(8, 0x38),00,         // Wheel
            HID_RI_LOGICAL_MINIMUM(8, -127),00,
            HID_RI_LOGICAL_MAXIMUM(8, 127),00,
            HID_RI_REPORT_COUNT(8, 0x01),00,
            HID_RI_REPORT_SIZE(8, 0x08),00,
            HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),00,
            // Horizontal wheel (1 byte)
            HID_RI_USAGE_PAGE(8, 0x0C),00,    // Consumer
            HID_RI_USAGE(16, 0x0238),00,      // AC Pan
            HID_RI_LOGICAL_MINIMUM(8, -127),00,
            HID_RI_LOGICAL_MAXIMUM(8, 127),00,
            HID_RI_REPORT_COUNT(8, 0x01),00,
            HID_RI_REPORT_SIZE(8, 0x08),00,
            HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),00,
        HID_RI_END_COLLECTION(0),00,
    HID_RI_END_COLLECTION(0),00,


    HID_RI_USAGE_PAGE(8, 0x01),00,           // Generic Desktop
    HID_RI_USAGE(8, 0x80),00,                // System Control
    HID_RI_COLLECTION(8, 0x01),00,           // Application
        HID_RI_REPORT_ID(8, 3),00,
        HID_RI_USAGE_MINIMUM(8, 0x01),00,    // Pointer
        HID_RI_USAGE_MAXIMUM(16, 0x00B7),00, // System Display LCD Autoscale
        HID_RI_LOGICAL_MINIMUM(8, 0x01),00,
        HID_RI_LOGICAL_MAXIMUM(16, 0x00B7),00,
        HID_RI_REPORT_COUNT(8, 1),00,
        HID_RI_REPORT_SIZE(8, 16),00,
        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_ARRAY | HID_IOF_ABSOLUTE),00,
    HID_RI_END_COLLECTION(0),00,

    HID_RI_USAGE_PAGE(8, 0x0C),00,           // Consumer
    HID_RI_USAGE(8, 0x01),00,                // Consumer Control
    HID_RI_COLLECTION(8, 0x01),00,           // Application
        HID_RI_REPORT_ID(8, 4),00,
        HID_RI_USAGE_MINIMUM(8, 0x01),00,    // Consumer Control
        HID_RI_USAGE_MAXIMUM(16, 0x02A0),00, // AC Desktop Show All Applications
        HID_RI_LOGICAL_MINIMUM(8, 0x01),00,
        HID_RI_LOGICAL_MAXIMUM(16, 0x02A0),00,
        HID_RI_REPORT_COUNT(8, 1),00,
        HID_RI_REPORT_SIZE(8, 16),00,
        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_ARRAY | HID_IOF_ABSOLUTE),00,
    HID_RI_END_COLLECTION(0),00,


    HID_RI_USAGE_PAGE(8, 0x01),00,        // Generic Desktop
    HID_RI_USAGE(8, 0x06),00,             // Keyboard
    HID_RI_COLLECTION(8, 0x01),00,        // Application
        HID_RI_REPORT_ID(8, 5),00,
        // Modifiers (8 bits)
        HID_RI_USAGE_PAGE(8, 0x07),00,    // Keyboard/Keypad
        HID_RI_USAGE_MINIMUM(8, 0xE0),00, // Keyboard Left Control
        HID_RI_USAGE_MAXIMUM(8, 0xE7),00, // Keyboard Right GUI
        HID_RI_LOGICAL_MINIMUM(8, 0x00),00,
        HID_RI_LOGICAL_MAXIMUM(8, 0x01),00,
        HID_RI_REPORT_COUNT(8, 0x08),00,
        HID_RI_REPORT_SIZE(8, 0x01),00,
        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),00,
        // Keycodes
        HID_RI_USAGE_PAGE(8, 0x07),00,    // Keyboard/Keypad
        HID_RI_USAGE_MINIMUM(8, 0x00),00,
        HID_RI_USAGE_MAXIMUM(8, KEYBOARD_REPORT_BITS * 8 - 1),00,
        HID_RI_LOGICAL_MINIMUM(8, 0x00),00,
        HID_RI_LOGICAL_MAXIMUM(8, 0x01),00,
        HID_RI_REPORT_COUNT(8, KEYBOARD_REPORT_BITS * 8),00,
        HID_RI_REPORT_SIZE(8, 0x01),00,
        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),00,

        // Status LEDs (5 bits)
        HID_RI_USAGE_PAGE(8, 0x08),00,    // LED
        HID_RI_USAGE_MINIMUM(8, 0x01),00, // Num Lock
        HID_RI_USAGE_MAXIMUM(8, 0x05),00, // Kana
        HID_RI_REPORT_COUNT(8, 0x05),00,
        HID_RI_REPORT_SIZE(8, 0x01),00,
        HID_RI_OUTPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE | HID_IOF_NON_VOLATILE),00,
        // LED padding (3 bits)
        HID_RI_REPORT_COUNT(8, 0x01),00,
        HID_RI_REPORT_SIZE(8, 0x03),00,
        HID_RI_OUTPUT(8, HID_IOF_CONSTANT),00,
    HID_RI_END_COLLECTION(0),00,
};



static void pp_descriptor(const uint8_t *descriptor, size_t len) {
  const uint8_t *end = descriptor + len;
  const uint8_t *p = descriptor;
  int i;
  printf("<\n");
  while (p < end) {
    for (i = 0; i < 8 && p < end; i++) {
      printf("%.2x ", *p++);
    }
    for (i = 0; i < 8 && p < end; i++) {
      printf(" %.2x", *p++);
    }
    printf("\n");
  }
  printf(">\n");
}

int main() {
  printf("HIDReport:\n");
  pp_descriptor(HIDReport, sizeof(HIDReport));
  printf("\n");
}