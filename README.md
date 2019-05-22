# Slic3rPE2Launcher
Slic3r Prusa Edition 2.0 doesn't have the --gui command line argument and the prusa-slicer-console.exe command line tool requires the --gcode argument in order not to launch the GUI.
To make Slic3r Prusa Edition 2.0 usable from within Repetier-Host 2.1.3, this little tool can patch the command line arguments repetier-host invokes when calling slic3r and either invoke prusa-slicer.exe or prusa-slicer-console.exe.

Has only been tested on Windows.

To use it, simply place prusa-launcher.exe in the same directory as prusa-slicer.exe and prusa-slicer-console.exe, then point "Slic3r Executable" in Repetier-Host's Slicer Manager to prusa-launcher.exe.

Slic3r Prusa Edition 2.0 release: https://github.com/prusa3d/PrusaSlicer/releases/tag/version_2.0.0