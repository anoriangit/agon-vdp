# fontsel

### Usage 

fontsel fontid [mode]

fontid needs to be one of:

- 0 	agon system font
- 1 	flash font 1 ("Atari ST" style)
- 2 	flash font 2 ("Olivetti Thin" style)
- 3 	flash font 3 ("IBM VGA" style)
- 255 	user font

Note that you'll need to upload a font file (using the fontload tool or some program like the BBCBASIC example provided with agon multifont) for the user font before you select it.

### Building 

You'll need the Zilog ZDS II Tools (available for free at zilog.com, windows only) and either some hex2bin tool or Envenomators wonderfull HEXLOAD program for the AGON: https://github.com/envenomator/agon-hexload 

Place (or download via hexload) fontsel.bin into the mos directory on your SD card.


NB:
- The paths in the link files (Debug.linkcmd and Release.linkcmd) need to be modified to reflect where the tools are located on your hard drive before this will compile.