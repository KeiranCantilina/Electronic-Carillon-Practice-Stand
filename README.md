# Electronic Carillon Practice Stand
Development of an electronic carillon practice stand with improved dynamic sensitivity and low construction cost.

The performance goals of this project will be considered achieved if a 4-octave digital instrument is built with superior and adjustable dynamic sensitivity compared to existing commercial solutions. Good control of tremelando must be possible. 
The cost optimization goals of this project will be considered complete if the construction is finished at a total cost under $1000 USD (including the cost of purchasing the tools).

The design uses dimensional lumber for the frame and #4 steel rebar for keyweights to reduce costs. 
Given my lack of woodworking or machining skills (and lack of space/money for tools to develop such skills), custom parts are designed to be 3D printable using any low-cost hobbyist 3D printer. All other parts are sourced either online (Ebay, Amazon, Aliexpress, etc.) or at Home Depot.

For the frame, no tools are strictly required other than a handsaw, hacksaw, screwdriver, and measuring tape (unless you count the 3D printer). However, an impact driver saves a lot of time when putting screws in, and 42" Harbor Freight bolt cutters rigged with a double tackle make much quicker work of cutting rebar than a hacksaw. A cheap plastic miter box ($10 at the time of writing) is also helpful.

The current electronic design uses an Arduino Mega 2560 development board, ADS1118 analog-to-digital converters, and SS49E Hall Effect sensors paired with magnets to sense velocity (using magnetic field strength measurements as a proxy for position). A soldering iron is necessary to assemble the electronic components (for now, until I get PCB designs set up after which "toaster oven reflow" might be possible).

The microcontroller sends out MIDI messages over serial-USB to an ancient netbook running virtual midi port software and a sequencer (SyFonOne loaded with a custom soundfont made with recorded samples).


