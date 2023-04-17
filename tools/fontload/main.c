/*
 * fontload - load user font from file
 * (requires the "multi font" VDP modification)
 *
 * Author:	Gerhard Skronn
 * Created:	11/04/2023
 *
 * Updated:	
 *		
 */
 
#include <stdio.h>
#include <stdlib.h>


#define S_BANNER "fontload 1.03c\n\r"

#define USER_FONT_ID 255
#define MAX_FONT_SIZE	8192

char fontbuf[MAX_FONT_SIZE];

int errno = 0;	// keep runtime happy


// moscalls.asm
extern int load_file(char *filename, char *buffer, int maxlen);
extern void putch(int c);

//
// Arguments:
// font id (64-67), filename, width, height 
//
int main(int argc, char * argv[]) {
	int	i, j, p, n, offset;
	int columns, rows, bytes_per_glyph, bytes_remaining;
	unsigned char width, height, pointsize;
	char *filename;
	char *cp;
	
	if(argc < 5 || argc > 6) {
		printf(S_BANNER);
		printf("usage: fontload filename pointsize width height [offset]\n\r");		
		return 19;	// MOS "Invalid Parameter" 
	}

	filename = argv[1];
	pointsize = (unsigned char)atoi(argv[2]);
	width  = (unsigned char)atoi(argv[3]);
	height = (unsigned char)atoi(argv[4]);
	
	if(argc == 6)
		offset = atoi(argv[5]);
	else
		offset = 0;
	
	// load the font file
	i = load_file(filename, fontbuf, MAX_FONT_SIZE);
	if(i != 0) {
		printf(S_BANNER);
		printf("error: loading file:\"%s\" failed.\n\r", filename);		
		return 4;	// MOS "Could not find file" 
	}
	
	// send long form VDU "Select Font": font_id, pointsize, width, height
	printf("%c%c%c%c%c%c", 23, 26, USER_FONT_ID, pointsize, width, height);	

	// now repeatedly send VDU "Define Character" in order to upload the font glyphs
	columns = (width + 8 - 1) / 8;  // aka bytes per row
	rows = height;
	bytes_per_glyph = columns * rows;
	
	p = (bytes_per_glyph + 7) / 8;	// how many passes do we need for one glyph
	
	//printf("size:%d, width:%d, height:%d, offset:%d\n\r", pointsize, width,height, offset);
	//printf("rows:%d, columns:%d, bytes_per_glyph:%d, p:%d\n\r", rows, columns, bytes_per_glyph, p);
	
	cp = fontbuf + offset;
	
	for(i=32; i<256; i++) {
		bytes_remaining = bytes_per_glyph;
		for(j=0; j<p; j++) {
			putch(23);
			putch(i);
			for(n=0; n<8; n++) {
				if(bytes_remaining) {
					putch(*cp++);
					bytes_remaining--;
				}
				else
					putch(0);
			}
		}
	}
	
	return 0;
}