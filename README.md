# Toy Synthesizer

Toy musical synthesizer for Linux that generates audio notes using your computer keyboard.

The lower keys on the computer keyboard z to m are mapped to synthesized musical tones A to G.

```
-------------KEYS: ----------------| 
       			           |
  [z][x][c][v][b][n][m]            |
                                   |
------- MUSICAL TONES -------------|
                                   |
   [A][B][C][D][E][F][G]           |         
___________________________________|
```

Once compiled you run the toy synthesizer from the terminal using the command below.

```
./toysynth
```

You can make a piano-keys template using the diagrams at [Piano-Keyboard-Guide](https://www.piano-keyboard-guide.com/piano-notes.html) to fit on top of the computer keyboard.

Test the synthesizer by tapping out a tune such as [Twinkle Twinkle Litte Star](https://www.letsplaykidsmusic.com/twinkle-twinkle-little-star-easy-piano-music/) which has the musical note sequence shown below.

```
CC GG AA G
FF EE DD C
GG FF EE D
CC GG AA G
FF EE DD C

```
Press the "Q-Key" to quit.

## Build From Source

The C source code for the Toy Synthesizer application is provided in the src directory.

You need to install the [GCC GNU Compiler Collection](https://gcc.gnu.org/). With both Debian Bookworm and Ubuntu you this by installing the build-essential package using the terminal command as shown below.

```
sudo apt install build-essential
```

The ALSA utils package is also required but should be installed by default. If not use the command below.

```
sudo apt install alsa-utils
```
Use the MAKEFILE to compile as shown below. 

```
make
```

To run the Toy Synthesizer from the terminal use

```
./toysynth
```

## To do

* tones for sharps

## Versioning

[SemVer](http://semver.org/) is used for versioning. The version number has the form 0.0.0 representing major, minor and bug fix changes.

## Author

* **Alan Crispin** [Github](https://github.com/crispinprojects)

## License

Toy Synthesizer is licensed under LGPL v2.1. 

## Project Status

Active.

## Acknowledgements

* [Geany](https://www.geany.org/) can be used as a source code editor for opening, viewing and then compiling the Toy Synthesizer C code. Geany is lightweight and has an integrated terminal for building the application.


