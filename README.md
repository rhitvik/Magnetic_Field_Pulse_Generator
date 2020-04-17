# Magnetic_Field_Pulse_Generator

## About the project
This project entails the development of the power system of a novel medical device to inhibit preterm uterine contractions using a magnetic field pulse. Premature birth and the attendant complications are the main cause of neonatal death and mortality and a major cause of maternal complications from preterm labour. It is among the greatest health problems in the world. Inhibiting preterm uterine contractions and eventually preterm birth is still an unsolved major problem for medicine and society with costs more than 25 billion dollars per year in the United States alone. 

In order to achieve this effect, a high frequency switcing power-supply is required to provide pulsed current at low voltage (around 3.1 Volts) and high current (3 Amps). So, out of some very brilliant contenders, I ended up moving foward with Allegro A6211 IC.
<div align="center"> 

![](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Images_and_Screenshots/Buck_converter.png) ![](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Images_and_Screenshots/Buck_converter_states.png)
*Buck Converter Circuit and it's states during switching*
<div align="left"> 

The A6211 operates in fixed on-time mode during switching. The on-time (and hence switching frequency) is programmed using an external resistor connected between the VIN and TON pins, as given by the following equation:

*tON = k × (RON + RINT) × (VOUT / VIN)*
*fSW = 1 / [ k × (RON + RINT)]*

where k = 0.0139, with fSW in MHz, tON in μs, and RON and
RINT (internal resistance, 5 kΩ) in kΩ (see Figure 20).

## Schematic and PCB Layout
[Click Here](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/tree/master/Schematic%26PCB_layout)
## Firmware Codes

## Bill of Materials
Click here to view [BOM](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/tree/master/Bill_of_materials)

## Report and Datasheets
Click here to view [Report](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Report_and_Datasheets/MPPI_Report.pdf)

[A6211-Datasheet](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Report_and_Datasheets/A6211-Datasheet.pdf)

[A6211-Evaluation-Board](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Report_and_Datasheets/A6211-Evaluation-Board.pdf)


## Consideration Report for IC LT8613

## 