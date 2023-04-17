/*
 * Title:			fontsel - select a font
 *
 * Select a font by id, optionally do a video mode switch 
 * (requires the "multi font" VDP modification)
 *
 * Author:			Gerhard Skronn
 * Created:			06/04/2023
 *
 * Updated:	
 * 11/04/2023	- 1.02 add optional video mode setting
 * 13/04/2023	- 1.03 changed size,width,height dummy values sending
 *		
 */
 
#include <stdio.h>
#include <stdlib.h>

int errno = 0;	// keep runtime happy

int main(int argc, char * argv[]) {
	int	i;
	unsigned char font_id, mode_id;
	
	if(argc < 2 || argc > 3) {
		printf("fontsel v.1.03\n\r");
		printf("usage: fontsel font_id [video_mode_id]\n\r");		
		return 19;	// MOS "Invalid Parameter" 
	}

	// send a short form "Select Font" (VDU 23, 26) to the VDP
	// only font_id needs to be valid, pointSize, width & height are dummy values indicating "don't change" 
	font_id = (unsigned char)atoi(argv[1]);
	printf("%c%c%c%c%c%c", 23, 26, font_id, 0, 0, 0);	

	// send "Mode" if requested
	if(argc == 3) {
		mode_id = (unsigned char)atoi(argv[2]);
		printf("%c%c", 22, mode_id);	
	}
	
	return 0;
}