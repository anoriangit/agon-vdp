# AGON-VDP MultiFont Changelog


### 8-Apr-2023 1.00
- fabgl::FontInfo *CURRENT_FONT pointer added
- modified copy_font() to take an int parameter: font_id
- changed call to copy_font to select font 0 at startup
- adapted change_mode() to call Canvas->selectFont(CURRENT_FONT);
- implemented VDP_SETFONT (VDU 23,0,160,id) in vdu_sys_video()
- added a number of font related defines to agon_fonts.h
- added includes for three fonts: atari_font.h, thin_font.h, ibm_font.h

### 9-Apr-2023 
- modified copy_font() to used the FONTS_MEMORY descriptors
- renamed AGON_FONT_SIZE to AGON_MAX_FONT_SIZE for clarity
- added fontmem_t type and fontmem_t FONTS_MEMORY[] array

### 11/04/2023 1.02
- enabled user font
- enabeled short form VDU 23,26,font_id for font selection
- enabeled long form VDU 23,26,font_id,size,width,height
- modified UDG upload to enable processing of more than 8 bytes
- enabled more ram storage for max 4 concurrent fonts in memory (8k)

### 12/04/2023 1.03
- display reset (via set_mode()) no always happens when switching fonts
- changed back to just one user font
- font buffer size now 4k
- user font id changed to 255 

### 13/04/2023 1.03b
- now creates backup copy of user font bitmap before switching it out
- adapted get_screen_char() to handle variable font heights
- added BIG_FONTS #define for 16x16 fonts (uses 16k of RAM in total)

### 17/04/2023 1.03c
- many improvements to the "Define Character" VDU
- removed backup copies of user font (too much RAM usage)
- added another fix to get_screen_char()
- removed double buffering for saving user fonts (way too much RAM use)
- reduced the standard buffer (without BIG_FONTS support) back down
  	to 2k as per the original VDP. This should remove issues with running
    out off RAM on the esp32 when the sprite system is used in Mode 3
    Note that this limits 8x16 fonts to max. ASCII 127 

### 18/04/2023 
- merged in upstream 1.03RC5
