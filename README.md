# Electronic Carillon Practice Stand
Development of an electronic carillon practice stand with improved dynamic sensitivity

The current design uses Arduino-style microcontrollers and pairs of mechanical switches to sense velocity (via time-of-flight calculations).
The microcontrllers send out MIDI messages over serial-USB to an ancient netbook running the SyFonOne sequencer (loaded with a soundfont made with recorded samples).

Future versions will hopefully use FSRs (force sensing resistors) as the current version is not really an improvement on existing electronic practice stands.
