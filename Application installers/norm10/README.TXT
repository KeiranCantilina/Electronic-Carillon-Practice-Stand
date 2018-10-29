Readme.txt

(****************************************)
(*                                      *)
(*        SHORT NOTICE                  *)
(*                                      *)
(* Developement of this program is up   *)
(* you! (users) If you want something   *)
(* new you have to send E-Mail. I have  *)
(* few cool ideas, but I don't code 'em *)
(* if there is no users. Let me know if *)
(* you exist :=)                        *)
(*                                      *)
(* -Tommi- The Grape -                  *)
(****************************************)


The WavNormalizer 1.0.4 , build 205 (18. July 2000)
	
	- Now you really can minimize program while process.

The WavNormalizer 1.0.4 , build 204 (17. May 2000)

	- Support for Lame encoder now build in feature.

The WavNormalizer 1.0.4 , build 201

	- "Nag" screen now really is destroyed after "OK"

The WavNormalizer 1.0.4 , build 200
	
	- Corrected many GUI-based bugs
	- Added some GUI features
	- Simplifyed external encoder support
	- Added BladeEnc encoder profile
	- Lots of cleanups to code
	- Correct LinearTeam homepage link

The WavNormalizer 1.0.3 , build 172

	- Corrected startup bug on WinNT with
	  user right.

The WavNormalizer 1.0.2 , build 168

	- Added external command line encoder support
	- Fixed some minor bugs
	- Some minor changes

The WavNormalizer 1.0.0 , build 147
	
	- Optimized normalizatiom engine
	- Rewritten user interface
	- Added 'Normalize' command registration
	  for .Wav files

The WavNormalizer 0.7 PreRelease 3, build 217

	-Huge "What the hell I was thinking about" bug corrected.
	 There was about a 50% chance that a Normalized file was 
	 visited by the "Kellog's Snap, Crackle & Pop" team.
	-My apologies.


The WavNormalizer 0.7 PreRelease 2, build 210
	
	-Wave format bug corrected.


The WavNormalizer 0.7 PreRelease 2, build 208

Content of this file:
	
		Description of program
		System requirements
		Using the program
		License
		Contacting me
		Thanks to
		DISCLAIMER


PROGRAM DESCRIPTION:

	WavNormalizer is a program which will maximize the
	volume of (normalize) Microsoft wave (.wav) files,
	so that they all play at the same volume level. 

	The .wav file has to be 8bit or 16bit wave in PCM
	format in any sample rate, mono or stereo (which is
	actually a normal wave in normal format).

	WavNormalizer normalizes .wav files into themselves,
	therefore no extra hard disk space is needed. However,
	if your system crashes (or if you have a power outtage)
	during the normalization process, the wave file will
	most likely be corrupted. WavNormalizer is quite fast
	(milliseconds in most cases... but minutes could be
	required for files 800Mb or so in length), so the
	risk is really quite small when compared to the
	benefits that you achieve. To be safe, though, you
	might want to copy cherished/irreplaceable .wav files
	to a "working" directory as you modify them, just
	in case.  This action, of course, falls under the
	"common sense" directive as mandated by the ABC
	(Active Brain Cell) branch of life itself. 

System requirements:

        WavNormalizer requires Windows9x, WinNT 4.0 or Win2K.

Using the program:

	In my opinion, this program is so easy to use that
	it doesn´t need any specific help files. Just click
	on "Add files to list" and select the path/file(s)
	that you want to normalize or drag and drop files on
	window.  Then, simply click on the "Go" button.

	Under the Preferences tab, you can select the
	percentage of Normalization by changing the default
	value of 100.0% (either manually by double
	clicking/changing the value, or by using the
	up/down arrows).

	If "Quick Norm" is selected, then WavNormalizer
	will automatically Normalize any .wav file that
	you Drag and Drop onto the program icon.

	If "Hide main window" is selected, then WavNormalizer
	will not show main window during normalization
	(this option requires "Quick norm" option to work).


	Under Enc tab, you can define command line for
	external program. Normalizer will send file to
	program just after normalization. There is few
	details you need to know about how this encoder
	options will effect to commandline.

	Encoder path: 
	
		Path and file name that points your
		encoder executable (.exe) file.

	Encoder command line options:

		This is the "prototype" for your
		commandline that will be formatted
		by normalizer. There is couple things
		you need to put there.

		%inf variable: This variable is
		replaced with normalized file's
		path and name
		
		%outf variable: If you need to
		declare output file name for encoder

	(Like -i:%inf -o:%outf -a - c -SomeOptions ...)
	%inf and %outf variables must be written exactly
	like that (Small letters). You have to declare
	%inf variable!	

	Filename options:

	Extension: If you need to change outfile extension
	it will be replased with extension declared in here


	You can save this settings and and it to ready to
	roll profiles. It is handy if you use more that one
	encoders. (Please send me working profiles via E-mail.
	just send copy of ltn1.ini to me please.)


Licence:

	This program is free for use of any kind. If you
	like and/or use this program, please send me a
	postcard or contact me via Email at the address
	below (or you can contribute actual currency if
	you'd like!? :)

	You may distribute this program freely, as long
	as it is unchanged and includes all of the files
	listed below.

	Norm10.exe	Program
	Readme.txt	This file

Contacting me:

	If you have any suggestions, bugs, or comments
	pertaining to this program, I would be happy to
	hear from you. Here's how you can contact me:

	SnailMail:

		Send Email to find out.

	EMail:
	
		tommi.prami@kno.fi


Thanks to:

	Juha Hartikainen
		-Many programming hints.

	Edmond "Ed" L Lacoste III
		-Graphics design for program	

	JJ Richard
		-Major beta testing and his American
		 English language grammar corrections.
	
	Reijo "Reke" Tuononen
		-For cool (Programming) ideas and he's
		 professional touch :=)
	
	Marko Raninen
		-Many ideas pertaining to user interface.

	Sanna Antikainen
		-For lending me her copy of the Titanic Soundtrack
		(which helped me find that huge bug in build 210).

	all co-workers at KNO Oy...


DISCLAIMER OF WARRANTY: 
(I wish I didn't have to do this, but I must);

	THIS PROGRAM IS DISTRIBUTED AS FREEWARE, SO DON'T
ASSUME A WARRANTY OF ANY KIND. YOU USE THIS PROGRAM COMPLETELY
AT YOUR OWN RISK. DON'T ASSUME CORRECTNESS, ACCURACY OR RELIABILITY
OF ANY KIND WHEN USING THIS DISTRIBUTED SOFTWARE. ANY DAMAGE CAUSED 
BY THIS PROGRAM, WHETHER BEING FROM A DIRECT OR INDIRECT USE OF THIS 
PROGRAM, AS WELL AS TO ANY EQUIPMENT USED, AND/OR ANY MATERIAL IN IT,
IS SOLEY YOUR RESOPONSIBILITY.  THE RISK IS YOURS AND YOURS ONLY.
YOU AGREE TO ALL OF THESE TERMS BY STARTING THIS PROGRAM.  IF YOU 
DON'T AGREE WITH THESE TERMS, THEN DON'T USE THIS PROGRAM.

