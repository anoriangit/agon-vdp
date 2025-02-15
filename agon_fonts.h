//
// Title:	        Agon Video BIOS - font file
// Author:        	Damien Guard
// Contributor		Gerhard Skronn (multi font)
// Created:       	06/08/2022
// Last Updated:	18/04/2023 (see CHANGELOG.md gs)
//
// Modinfo:
// 17/08/2022:		Implemented Acorn font
// 05/09/2022:		Renamed file
// 20/02/2023:		Marked out non-standard CP-1252 characters in comments, fixed £ and `

#pragma once


// #define BIG_FONTS 1

// BIG_FONTS = max 16x16 = 8k
#ifdef BIG_FONTS
#define AGON_MAX_FONT_SIZE    8192
#define AGON_MAX_FONT_WIDTH	  16
#else
#define AGON_MAX_FONT_SIZE    2048
#define AGON_MAX_FONT_WIDTH	  8
#endif

#define AGON_MAX_FONT_HEIGHT  16

#define AGON_SYSTEM_FONT_ID   0
#define AGON_ATARI_FONT_ID    1
#define AGON_THIN_FONT_ID     2
#define AGON_IBM_FONT_ID      3

#ifdef BIG_FONTS
#define AGON_FAB9x15_FONT_ID  4
#define AGON_NUM_FLASH_FONTS  5
#else
#define AGON_NUM_FLASH_FONTS  4
#endif

#define AGON_USER_FONT_ID     255   // the user font


typedef struct fontmem {
  const uint8_t *bitmap;
  size_t offset, size;
} fontmem_t;

namespace fabgl {
	uint8_t FONT_AGON_DATA[AGON_MAX_FONT_SIZE]; 
}

#include "atari_font.h"
#include "thin_font.h"
#include "ibm_font.h"
#include "fabfont_9x15.h"

namespace fabgl {

	static const uint8_t FONT_AGON_BITMAP[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  
		0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x00, // !
		0x6c, 0x6c, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, // "
		0x36, 0x36, 0x7f, 0x36, 0x7f, 0x36, 0x36, 0x00, // #
		0x0c, 0x3f, 0x68, 0x3e, 0x0b, 0x7e, 0x18, 0x00, // $
		0x60, 0x66, 0x0c, 0x18, 0x30, 0x66, 0x06, 0x00, // %
		0x38, 0x6c, 0x6c, 0x38, 0x6d, 0x66, 0x3b, 0x00, // &
		0x0c, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, // '
		0x0c, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x00, // (
		0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x18, 0x30, 0x00, // )
		0x00, 0x18, 0x7e, 0x3c, 0x7e, 0x18, 0x00, 0x00, // *
		0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00, // +
		0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, // ,
		0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, // -
		0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, // .
		0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x00, 0x00, // /

		0x3c, 0x66, 0x6e, 0x7e, 0x76, 0x66, 0x3c, 0x00, // 0
		0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00, // 1
		0x3c, 0x66, 0x06, 0x0c, 0x18, 0x30, 0x7e, 0x00, // 2
		0x3c, 0x66, 0x06, 0x1c, 0x06, 0x66, 0x3c, 0x00, // 3
		0x0c, 0x1c, 0x3c, 0x6c, 0x7e, 0x0c, 0x0c, 0x00, // 4
		0x7e, 0x60, 0x7c, 0x06, 0x06, 0x66, 0x3c, 0x00, // 5
		0x1c, 0x30, 0x60, 0x7c, 0x66, 0x66, 0x3c, 0x00, // 6
		0x7e, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x00, // 7
		0x3c, 0x66, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x00, // 8
		0x3c, 0x66, 0x66, 0x3e, 0x06, 0x0c, 0x38, 0x00, // 9
		0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, // :
		0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x30, // ;
		0x0c, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0c, 0x00, // <
		0x00, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x00, 0x00, // =
		0x30, 0x18, 0x0c, 0x06, 0x0c, 0x18, 0x30, 0x00, // >
		0x3c, 0x66, 0x0c, 0x18, 0x18, 0x00, 0x18, 0x00, // ?

		0x3c, 0x66, 0x6e, 0x6a, 0x6e, 0x60, 0x3c, 0x00, // @
		0x3c, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00, // A
		0x7c, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x7c, 0x00, // B
		0x3c, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3c, 0x00, // C
		0x78, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0x78, 0x00, // D
		0x7e, 0x60, 0x60, 0x7c, 0x60, 0x60, 0x7e, 0x00, // E
		0x7e, 0x60, 0x60, 0x7c, 0x60, 0x60, 0x60, 0x00, // F
		0x3c, 0x66, 0x60, 0x6e, 0x66, 0x66, 0x3c, 0x00, // G
		0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00, // H
		0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00, // I
		0x3e, 0x0c, 0x0c, 0x0c, 0x0c, 0x6c, 0x38, 0x00, // J
		0x66, 0x6c, 0x78, 0x70, 0x78, 0x6c, 0x66, 0x00, // K
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x00, // L
		0x63, 0x77, 0x6b, 0x6b, 0x63, 0x63, 0x63, 0x00, // M
		0x66, 0x66, 0x76, 0x7e, 0x6e, 0x66, 0x66, 0x00, // N
		0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00, // O

		0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0x00, // P
		0x3c, 0x66, 0x66, 0x66, 0x6a, 0x6c, 0x36, 0x00, // Q
		0x7c, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0x66, 0x00, // R
		0x3c, 0x66, 0x60, 0x3c, 0x06, 0x66, 0x3c, 0x00, // S
		0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, // T
		0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00, // U
		0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, // V
		0x63, 0x63, 0x6b, 0x6b, 0x7f, 0x77, 0x63, 0x00, // W
		0x66, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x66, 0x00, // X
		0x66, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x00, // Y
		0x7e, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x7e, 0x00, // Z
		0x7c, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7c, 0x00, // [
		0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x00, 0x00, // 
		0x3e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x3e, 0x00, // ]
		0x18, 0x3c, 0x66, 0x42, 0x00, 0x00, 0x00, 0x00, // ^
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, // _

		0x30, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, // `
		0x00, 0x00, 0x3c, 0x06, 0x3e, 0x66, 0x3e, 0x00, // a
		0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x7c, 0x00, // b
		0x00, 0x00, 0x3c, 0x66, 0x60, 0x66, 0x3c, 0x00, // c
		0x06, 0x06, 0x3e, 0x66, 0x66, 0x66, 0x3e, 0x00, // d
		0x00, 0x00, 0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x00, // e
		0x1c, 0x30, 0x30, 0x7c, 0x30, 0x30, 0x30, 0x00, // f
		0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x3c, // g
		0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x00, // h
		0x18, 0x00, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x00, // i
		0x0c, 0x00, 0x1c, 0x0c, 0x0c, 0x0c, 0x0c, 0x78, // j
		0x60, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0x00, // k
		0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, // l
		0x00, 0x00, 0x36, 0x7f, 0x6b, 0x6b, 0x63, 0x00, // m
		0x00, 0x00, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x00, // n
		0x00, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x3c, 0x00, // o

		0x00, 0x00, 0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, // p
		0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x07, // q
		0x00, 0x00, 0x6c, 0x76, 0x60, 0x60, 0x60, 0x00, // r
		0x00, 0x00, 0x3e, 0x60, 0x3c, 0x06, 0x7c, 0x00, // s
		0x30, 0x30, 0x78, 0x30, 0x30, 0x30, 0x1e, 0x00, // t
		0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00, // u
		0x00, 0x00, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, // v
		0x00, 0x00, 0x63, 0x6b, 0x6b, 0x7f, 0x36, 0x00, // w
		0x00, 0x00, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x00, // x
		0x00, 0x00, 0x66, 0x66, 0x66, 0x3e, 0x06, 0x3c, // y
		0x00, 0x00, 0x7e, 0x0c, 0x18, 0x30, 0x7e, 0x00, // z
		0x0c, 0x18, 0x18, 0x70, 0x18, 0x18, 0x0c, 0x00, // {
		0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00, // |
		0x30, 0x18, 0x18, 0x0e, 0x18, 0x18, 0x30, 0x00, // }
		0x66, 0xd6, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, // ~
		0x3c, 0x42, 0x9d, 0xb1, 0xb1, 0x9d, 0x42, 0x3c, // © (should be delete)

		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //

		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x1c, 0x36, 0x30, 0x7c, 0x30, 0x30, 0x7e, 0x00, // £
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //		
	};

	extern FontInfo const FONT_AGON = {
		.pointSize = 6,
		.width     = 8,
		.height    = 8,
		.ascent    = 7,
		.inleading = 0,
		.exleading = 0,
		.flags     = 0,
		.weight    = 400,
		.charset   = 255,
		.data      = FONT_AGON_DATA,
		.chptr     = nullptr,
		.codepage  = 1252,
	};

  // USER FONT descriptor in RAM: we need to be able to write to this one
	extern FontInfo FONT_USER = {
		.pointSize = 6,
		.width     = 8,
		.height    = 8,
		.ascent    = 7,
		.inleading = 0,
		.exleading = 0,
		.flags     = 0,
		.weight    = 400,
		.charset   = 255,
		.data      = FONT_AGON_DATA,
		.chptr     = nullptr,
		.codepage  = 1252,
  };


  // these get passed to fabgl
  extern FontInfo const *AGON_FONTS_TABLE[] = {
#ifdef BIG_FONTS
      &FONT_AGON, &FONT_ATARI, &FONT_THIN, &FONT_IBM, &FAB_FONT_9x15, &FONT_USER
#else
      &FONT_AGON, &FONT_ATARI, &FONT_THIN, &FONT_IBM, &FONT_USER
#endif
  };

  // these are needed by copy_font()
  extern fontmem_t AGON_FONTS_MEMORY[] = {
 
      { FONT_AGON_BITMAP, 256, sizeof(FONT_AGON_BITMAP) },
      { FONT_ATARI_BITMAP, 0, sizeof(FONT_ATARI_BITMAP) },
      { FONT_THIN_BITMAP, 0, sizeof(FONT_THIN_BITMAP) },
      { FONT_IBM_BITMAP, 0, sizeof(FONT_IBM_BITMAP) },
      { FONT_9x15_BITMAP, 0, sizeof(FONT_9x15_BITMAP) },
 
  };                                        

} // namespace fabgl
