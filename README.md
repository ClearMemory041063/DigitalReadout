# Digital Readout DRO
 
An Arduino circuit that counts the pulses from incremental encoders, typically mounted on machine tools. The values are sent via Bluetooth to an Android application SDRO1

SDRO1 is an Android application that receives data from the previously mentioned circuit and displays the X, Y ,and Z coordinates of the machine tool. It can be used to create patterns of holes such as an angled line of holes or a circular arc of holes (flange holes). It can read a pattern from a CSV file as well.

Check out the PDF files in the TestRun, Software and Hardware directories.

mm/inch button initialization fixed 7Apr2021.

11Apr2021 Added SDRO1_H vesrion.
This modifys the read patterb from a file so that is uses a file picker application.
The suggested app id Lyesoft AppInventor. For links see the SDRO1H_03.pdf in the Software directory.


