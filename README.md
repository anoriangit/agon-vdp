# AGON-VDP (multi font) 1.03 (based on VDP 1.03 RC4)

### What is the multi font VDP

This is a modification of the official firmware for the esp32 co-processor on the AGON.

It is based on version 1.03 RC4 of AGON Quark VDP and will most likely only work with MOS 1.03 RC4

The purpose of this modification is to enable bitmap fonts other than the inbuilt official one, for fun and increased readability, especially in high resolution mode 0. 

The actual changes to the official VDP code base are minimal, they consist of only a few modifications in the main video.ino file, in agon_fonts.h and the addition of three new fonts (ATARI, Olivetti THIN, IBM VGA) in include files.

### Usage

The available fonts can be selected by using the "Select Font" VDU command byte sequence: 

`VDU 23,26,FONTID,POINTSIZE,WIDTH,HEIGHT`

where FONTID is one of 
- 0 Agon system font
- 1	ATARI
- 2	Olivetti THIN
- 3	IMB VGA
- 4	FONT9x15 (only available in BIG_FONTS builds, see below)
- 255 USER font

Note that for selecting one of the provided "baked in" fonts, POINTSIZE, WIDTH and HEIGHT can be any arbitrary value as they will be ignored, but you still have to provide them.

### Big Fonts

This version of the VDP can be built enabling a feature named BIG_FONTS
Enabling this will increase the font buffer in RAM from the default 2k to 8k. This allows using fonts with dimensions of up to 16x16.

Note that, without BIG_FONTS support, even 8x16 fonts are limited to supporting ASCII codes ranging from 32 to 127. While this will be ok for many applications it might not be acceptable to all. In this case you will have to limit yourself to using the standard 8x8 font size (or smaller).

### User Fonts

From version 1.03 of this mod you can upload fonts from files at runtime.

The process involves two VDU sequences as follows:

- Select the user font (255) (VDU 23,26,255...) see above 
- Define Character (VDU 23,code,byte0,byte1,byte2,byte3,byte4,byte5,byte6,byte7)
 
When uploading from a file, FONTID needs to be 255 and you have to provide POINTSIZE,WIDTH and HEIGHT. After the initial "Select Font" simply proceed to send glyph data using "Define Character"

The fonts folder of this repository contains an example file. BESCII.BIN is a recreation (8x8) of the classic Commodore font. This small version only contains the glyphs for character codes 32-126. A BBCBASIC example demonstrating how to upload this font is provided in the examples folder.

The user font stays resident im RAM only. You can switch between it and the flash fonts but after a restart its gone.

### Tools

The repository includes the source code for two tools

- fontsel
- fontload

These are small AGON MOS applications for selecting fonts (and video modes) and uploading user fonts from files. Please see the accompanying documents inside the respective subfolders for more information.

### Fonts licensing

Fonts licensing: The IBM VGA and Olivetti THIN fonts where taken from the "Ultimate Oldschool PC Font Pack" (https://int10h.org/oldschool-pc-fonts/) and are licensed under the Creative Commons Attribution-ShareAlike 4.0 International License (http://creativecommons.org/licenses/by-sa/4.0/)

The "Atari ST 8x16 System Font by divVerent" is available on many internet font download sites "free for personal use", if you are the original author and disagree with my use, please let me know!

Font9x15 is included with the fabgl library used by the VDP and licensed accordingly.

BESCII is licensed under CCO 1.0 and can be found here: https://github.com/damianvila/font-bescii  

### Build & install
 
The build and install process is unchanged and documented in the following (original) text, I'd only like to add one recommendation: git clone this repo into a folder named video ("git clone https://github.com/anoriangit/agon-vdp.git video") in order to prevent the Arduino IDE from complaining about the project folder name.

# agon-vdp

Part of the official Quark firmware for the Agon series of microcomputers

### What is the Agon

Agon is a modern, fully open-source, 8-bit microcomputer and microcontroller in one small, low-cost board. As a computer, it is a standalone device that requires no host PC: it puts out its own video (VGA), audio (2 identical mono channels), accepts a PS/2 keyboard and has its own mass-storage in the form of a µSD card.

https://www.thebyteattic.com/p/agon.html

### What is the VDP

The VDP is a serial graphics terminal that takes a BBC Basic text output stream as input. The output is via the VGA connector on the Agon.

It will process any valid BBC Basic VDU commands (starting with a character between 0 and 31).

For example:

`VDU 25, mode, x; y;` is the same as `PLOT mode, x, y` 

### Documentation

The AGON documentation can now be found on the [Agon Light Documentation Wiki](https://github.com/breakintoprogram/agon-docs/wiki)

### Building

The ESP32 is programmed via the USB connector at the top of the board using the Arduino IDE. It has been tested on version 1.8.19 and the latest 2.0.4.

#### Arduino IDE settings

In order to add the ESP32 as a supported board in the Arudino IDE, you will need to add in this URL into the board manager:

Select Preferences from the File menu

In the Additional Board Manager URLs text box, enter the following URL:

`https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`

In the Board Manager (from the Tools menu), select the esp32 board, making sure version 2.0.4 is installed.

Now the board can be selected and configured:

* Board: “ESP32 Dev Module”
* Upload Speed: “921600”
* CPU Frequency: “240Mhz (WiFi/BT)”
* Flash Frequency: “80Mhz”
* Flash Mode: “QIO”
* Flash Size: “4MB (32Mb)”
* Partition Scheme: “Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)”
* Core Debug Level: “None”
* PSRAM: “Enabled”

Bernado writes:

> Although I am using 4MB for the PSRAM coupled to the ESP32 (the FabGL assumption), that memory actually has 8MB, so if you find a way to use the extra 4MB, please change the configuration to 8MB.

And for the Port, you will need to determine the Com port that the Agon Light is assigned from your OS after it is connected.

Now the third party libraries will need to be installed from the Library Manager in the Tools menu

* FabGL version 1.0.8
* ESP32Time version 2.0.0

It is important you use these exact versions otherwise I cannot guarantee the code will compile or run correctly.

NB:

If you are using version 2.0.x of the IDE and get the following message during the upload stage:

`ModuleNotFoundError: No module named 'serial'`

then you will need to install the python3-serial package