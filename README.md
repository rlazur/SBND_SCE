# SBND_SCE
This is a collection of codes that fulfill various functions in the goal of validating and correcting for the space charge effects at SBND. 

the setup bash script can just be sourced raw from the GPVM

after souring the setup script, the .cpp file (gallery_SCEcorrections) can be edited then recompiled. To recompile, cd to the build directory then run the command "make". The executible will be made in the build directory and can be ran with ./gallery_SCEcorrections.

The output from the gallery script (output.root) can be used as input for the superimpose_dEdx script. Which must be edited in the .cpp script then rebuild by going to the initial_corrections/build directory and running the "make" command. 

The stuff in isotropic muons is kind of old

The stuff in WorkshopSept2019 is kinda old but is useful. Mike's forward/backward map tool is in there, but the gallery script is an older version of the gallery_SCEcorrections script.
