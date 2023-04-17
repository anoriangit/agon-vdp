# fontload for multi font VDP

### Usage 

`fontload fontfile pointsize width height [offset]`

- loads a binary font file into font id 255 
- width and height both can range from 6-16

the offset argument is optional: its only required if the fontfile you intend
to load does not start at ascii 32 (space)

Example: loading a 9x15 font from a file that has all glyphs starting at code 0
you will have 30 bytes per glyph resulting in an offset of 32*30=960


### Building 

You'll need the Zilog ZDS II Tools (available for free at zilog.com, windows only) and either some hex2bin tool or Envenomators wonderfull HEXLOAD program for the AGON: https://github.com/envenomator/agon-hexload 

Place (or download via hexload) fontsel.bin into the mos directory on your SD card.


NB:
- The paths in the link files (Debug.linkcmd and Release.linkcmd) need to be modified to reflect where the tools are located on your hard drive before this will compile. 
- I am only using the release builds myself