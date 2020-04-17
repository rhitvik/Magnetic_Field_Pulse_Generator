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
Where k = 0.0139, with fSW in MHz, tON in μs, and RON and
RINT (internal resistance, 5 kΩ) in kΩ (see the figure below).
<div align="center"> 

![Circuit Equations and Waveforms](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Images_and_Screenshots/CircuitEquations_and_Waveforms.png)
*Circuit Equations and Waveforms (Image taken from A6211 Datasheet)*
<div align="left"> 

## Schematic and PCB Layout
[Click Here](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/tree/master/Schematic%26PCB_layout)
## Firmware Codes

## Bill of Materials
Click here to view [BOM](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/tree/master/Bill_of_materials)

## Report and Datasheets
Click here to view [Report](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Report_and_Datasheets/MPPI_Report.pdf)

[A6211-Datasheet](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Report_and_Datasheets/A6211-Datasheet.pdf)

[A6211-Evaluation-Board](https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/blob/master/Report_and_Datasheets/A6211-Evaluation-Board.pdf)

## Considering IC LT8613
This was the Second best conteneder to drive the swithing circuit and the following data was obtained from running the smulations. The parallel appication allowed to obtain a high amount of current was an added flexibility along many safety features. 
The LT8613 is a compact, high efficiency, and high speed synchronous monolithic step-down switching regulator. The integrated power switches and inclusion of all necessary circuitry reduce the components count and solution size. Ultralow 3μA quiescent current in Burst Mode® operation achieves high efficiency at very light loads. Fast minimum on-time of 40ns enables high VIN to low VOUT conversion at high frequency.

**Datasheet** [Click Here]
**Evaluation Board** [Click Here]
**Simulation Report** [Click Here]https://github.com/rhitvik/Magnetic_Field_Pulse_Generator/tree/master/Consideraton_Report_for_IC_LT8613)

## 