SerialPlot
==========

Serial plotter
As an aid in the testing of the detector, a simple simple plotter was developed for plotting the serial data from the
Virtual Serial Port using C++/Qt/QCustomPlot.

The plotter builds a dynamic plot from the receiver data, scaling the plot when necessary. 
The window is set to contain a maximum of 150 data points. When more data is presented the graph only shows the
150 most recent points. 
The data is plotted continuously using the Qt debug connection.

The plotter is set to use COM4, 115.200 Baud, but can easily be changed to use a different COM port or a
different communication setting. 
Using Qt has the advantage that the code can be converted to other operating systems easily (we used Windows 8.1).

QCustumPlot is a Qt C++ widget for plotting and data visualization developed by Emanuel Eichhammer (Germany) 

