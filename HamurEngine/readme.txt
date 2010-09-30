1) Run project from Visual Studio IDE
=====================================
You have to set up your "Working Directory" from your project properties.

Both "Debug" and "Release" mode set up this from "Debugging" tab:

"Working Directory" = $(OutDir)

In the subversion "Release" directory is not included, you should copy contents
of "Debug" directory to "Release" directory. 


2) WorkingDir
=====================================
All working project executables, binary and asset files are saved in this directory.
This directory should contain final release build of HamurTest project.
But you can also use this directory structure for your game projects.




