# VizWiz

VizWiz is a VR Music Visualizer developed with C++ and UE4. It makes use of UE's TimeSynthComponent to perform spectral analysis on a given audio file. Although intended to be experienced in VR, the application can also run and build on any capable machine for a desktop FPS experience.

### Can I try it out? 

* Yes, you can
* It was created using UE4.6, so keep that in mind
* Clone the repository
* Right click on VizWiz.uproject file and generate VS files
* Build the newly created solution
* Run the .uproject
* Visualize away!


### Creating a new music visualization map

* Make a new map
* Expose the SpectralPlayer.cpp and SpectralVisualizer.cpp into Blueprint actors
* Create a TimeSynthClip from an audio file of your choice
* Select it in the player's audio properties
* Go into the visualizer actor's Blueprint and create your own custom spline points
* Have fun! 

### Credits
Reuben Ward's [tutorial](https://youtu.be/CwjOPrDPB7I)  on making a music visualizer with C++

Alex Peterson's [Spacescape](http://alexcpeterson.com/spacescape/) for an awesome skybox

Jason Shaw's [AudionautiX](https://audionautix.com/) for awesome music
