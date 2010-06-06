Run project from Visual Studio IDE
==================================
You have to set up your "Working Directory" from your project properties.

Both "Debug" and "Release" mode set up this from "Debugging" tab:

"Working Directory" = $(OutDir)

In the subversion Debug directory is not included, you should copy contents
of Release directory to Debug directory inorder to run in Debug build mode. 



