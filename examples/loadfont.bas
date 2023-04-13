   6 file$="/fonts/bescii.bin"
   7 width=8
   8 height=8
   9 REM try to open font file
   20 infile=OPENIN file$
   30 IF infile=0 THEN PRINT "file open error" : END
   32 VDU 23,26,255,6,width,height
   40 FOR i=32 TO 127
   50     c0=BGET#infile
   50     c1=BGET#infile
   50     c2=BGET#infile
   50     c3=BGET#infile
   50     c4=BGET#infile
   50     c5=BGET#infile
   50     c6=BGET#infile
   50     c7=BGET#infile
   120    VDU 23,i,c0,c1,c2,c3,c4,c5,c6,c7
   70 NEXT i
   80 CLOSE#infile
   90 END

