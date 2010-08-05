Run project from Visual Studio IDE
==================================
You have to set up your "Working Directory" from your project properties.

Both "Debug" and "Release" mode set up this from "Debugging" tab:

"Working Directory" = $(OutDir)

In the subversion "Release" directory is not included, you should copy contents
of "Debug" directory to "Release" directory. 



