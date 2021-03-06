# ProjectVictory

An interactive broadcast system that takes input from multiple types of cameras, 
mixes them, adds a graphical layer based on computer vision analysis of the live 
shot and allows for control of that layer via social network interaction.

# Development

## Setup your development environment

We use the _master_ branch of the [openFrameworks](https://github.com/openframeworks/openFrameworks)
repository, either from your own fork or directly from the main repository. The 
description below explains how to setup your development environment for 
ProjectVictory.

````sh

cd Documents

git clone git@github.com:openframeworks/openFrameworks.git nike

cd nike/apps

git clone git@github.com:HellicarAndLewis/ProjectVictory.git

````

## General OF development directory layout

_General guidelines_

- all applications should be compilable directly after cloning the ProjectVictory repository
- all addons that are used by the tests or final runtimes are stored in the ProjectVictory/addons repository (as copy or submodule)
- shared data like images, fonts, shared settings, shared _code_ go into the shared directory
- *final* applications get the prefix _Runtime_

````sh
of/apps/ProjectVictory 
of/apps/ProjectVictory/addons/     
of/apps/ProjectVictory/shared/ 
of/apps/ProjectVictory/shared/libs/ 
of/apps/ProjectVictory/shared/images/ 
of/apps/ProjectVictory/shared/fonts/ 
of/apps/ProjectVictory/Test_VideoStreamer
of/apps/ProjectVictory/Test_[your test]
of/apps/ProjectVictory/Runtime_VideoStreamer
of/apps/ProjectVictory/Runtime_VideoMixer
of/apps/ProjectVictory/Runtime_[your app]
````

## Includes for the addons
````sh
./../addons/ofxCv/libs/ofxCv/include/
./../addons/ofxFluid/src/
````

## Linker search paths for ofxVideoStreamer
Add a linker search path to the "root" where the subdirectory of `ofxVideoStreamer` can be found.
So if you put ofxVideoStreamer, inside addons/, then add a linker path to "addons". 

## Preprocessor flags

Make sure to add these to your OF projects

_Debug preprocessor flags_
````sh
YUV420P_GRABBER_GLSL_VERSION=120
VIDEO_STREAMER_LITTLE_ENDIAN
````

_Release preprocessor flags_
````sh
YUV420P_GRABBER_GLSL_VERSION=120
VIDEO_STREAMER_LITTLE_ENDIAN
NDEBUG
````

## Other linker flags

````sh
ofxVideoStreamer/lib/libx264.a
ofxVideoStreamer/lib/librtmp.a
ofxVideoStreamer/lib/libuv.a
ofxVideoStreamer/lib/libmp3lame.a
ofxVideoStreamer/lib/libfaac.a
````