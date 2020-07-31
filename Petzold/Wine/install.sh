#!/bin/bash

chmod +w `find . -type d`

rm -rf Chap[012][0123456789]/*/*.mak

unzip -qao PetzoldMakefiles.zip

move()
{
    if [ -f $1 ]; then mv $1 $2; fi
}

for sample in `find -name RESOURCE.H | sed 's%/RESOURCE.H%%'`; do
    (cd $sample; move RESOURCE.H Resource.h; ln -sf Resource.h resource.h)
done

for i in 1 2 3; do
    (cd Chap04/SysMets$i; ln -sf SysMets.h sysmets.h)
done

for sample in Chap06/SysMets4 Chap07/SysMets; do
    (cd $sample; ln -sf SysMets.h sysmets.h)
done

for sample in Chap15/Apollo11 Chap15/ShowDib1 Chap15/ShowDib2; do
    (cd $sample; ln -sf DibFile.h dibfile.h)
done

for i in 4 5 6 7 8; do
    (cd Chap16/ShowDib$i; ln -sf ../ShowDib3/PackeDib.h ..\\\\ShowDib3\\\\PackeDib.h)
done

for sample in ChosFont  EndJoin  FontClip  FontFill  FontOut1  FontOut2  FontRot  Justify1  Justify2 PickFont UniChars; do
    (cd Chap17/$sample; ln -sf ../EZTest/ezfont.h ..\\\\eztest\\\\ezfont.h)
    (cd Chap17/$sample; ln -sf ../EZTest/ezfont.h ..\\\\EZTest\\\\EzFont.h)
    (cd Chap17/$sample; ln -sf ../EZTest/resource.h ..\\\\EZTest\\\\resource.h)
    (cd Chap17/$sample; ln -sf ../EZTest/ezfont.h)
    (cd Chap17/$sample; if ! [ -f afxres.h ]; then ln -sf ../EZTest/afxres.h; fi)
    (cd Chap17/$sample; if [ -f Resource.h ]; then ln -sf Resource.h resource.h; else ln -sf ../EZTest/resource.h; fi)
done

for sample in Emf1  Emf10  Emf11  Emf12  Emf13  Emf2  Emf3  Emf4  Emf5  Emf6  Emf7  Emf9  EmfView  Metafile; do
   (cd Chap18/$sample; ln -sf ../Emf8/resource.h ..\\\\emf8\\\\resource.h)
   (cd Chap18/$sample; if [ -f Resource.h ]; then ln -sf Resource.h resource.h; else ln -sf ../Emf8/resource.h; fi)
   (cd Chap18/$sample; ln -sf ../Emf8/afxres.h)
done

for sample in Record2 Record3; do
   (cd Chap22/$sample; ln -sf ../Record1/resource.h ..\\\\record1\\\\resource.h)
   (cd Chap22/$sample; ln -sf ../Record1/resource.h)
   (cd Chap22/$sample; ln -sf ../Record1/afxres.h)
done

(cd Chap10/IconDemo; move ICONDEMO.ICO icondemo.ico)
(cd Chap10/PoePoem; move POEPOEM.ICO poepoem.ico; move POEPOEM.TXT poepoem.txt)
(cd Chap10/PopPad2; move POPPAD2.ICO poppad2.ico)
(cd Chap11/About3; move ICON1.ICO icon1.ico)
(cd Chap11/HexCalc; ln -sf HexCalc.dlg hexcalc.dlg)
(cd Chap11/PopPad3; move POPPAD.ICO poppad.ico)
(cd Chap13/PopPad; move POPPAD.ICO poppad.ico)
(cd Chap14/BitMask; move Matthew.bmp matthew.bmp)
(cd Chap14/Bricks3; move BRICKS3.C BRICKS3.c)
(cd Chap16/Dibble; ln -sf DibConv.h dibconv.h; ln -sf DibHelp.h dibhelp.h; ln -sf DibPal.h dibpal.h)
(cd Chap17/EZTest; ln -sf EZFont.h ezfont.h; ln -sf ezfont.h ..\\\\EZTest\\\\EzFont.h; ln -sf resource.h ..\\\\EZTest\\\\resource.h)
(cd Chap18/Emf8; ln -sf resource.h ..\\\\emf8\\\\resource.h)
(cd Chap21/EdrTest; ln -sf EdrLib.h edrlib.h)
(cd Chap21/ShowBit; for i in 1 2 3 4 5 6 7 8 9; do move BITMAP$i.BMP bitmap$i.bmp; done)
(cd Chap21/StrProg; ln -sf StrLib.h strlib.h)
(cd Chap22/AddSynth; ln -sf AddSynth.h addsynth.h)
(cd Chap22/Drum; move DRUM.ICO drum.ico; ln -sf DrumFile.h drumfile.h; ln -sf DrumTime.h drumtime.h)
