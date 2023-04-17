# fontload for multi font VDP

### Usage 

fontload fontfile width height

loads a binary font file into font id 255 
width currently must be 8
height 8-16


### Building 

You'll need the Zilog ZDS II Tools (available for free at zilog.com, windows only) and either some hex2bin tool or Envenomators wonderfull HEXLOAD program for the AGON: https://github.com/envenomator/agon-hexload 

Place (or download via hexload) fontsel.bin into the mos directory on your SD card.


NB:
- The paths in the link files (Debug.linkcmd and Release.linkcmd) need to be modified to reflect where the tools are located on your hard drive before this will compile.