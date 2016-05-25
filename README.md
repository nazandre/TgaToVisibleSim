# TgaToVisibleSim

Convert a TGA image into a catoms2D configuration file supported by the VisibleSim simulator.

### Compilation

To compile TgaToVisibleSim, go into the `build/` folder and enter `make`.

```
$ cd build/
$ make
```

### Usage

TgaToVisibleSim works as following:

```
Usage: tgaToVisibleSim -i <input tga image> [options]
Options:
  -o <output xml file> : output configuration file for VisibleSim
  -h                   : print this usage and exit
```

### Example

Below is a full example of how to compile and use TgaToVisibleSim. In this example, `images/example-red-car.tga` is converted into  `build/example-red-car.xml`.

```
$ cd build/
$ make
$ ./tgaToVisibleSim -i ../images/example-red-car.tga 
Input: ../images/example-red-car.tga
Output: example-red-car.xml

Width: 304
Height: 93
../images/example-red-car.tga opened!
exporting to VisibleSim...
17687 modules 
../images/example-red-car.tga exported in example-red-car.xml
```

Below are the original picture `images/example-red-car.tga` and a screenshot of VisibleSim loaded with the generated configuration `build/example-red-car.xml`.

![](images/example-red-car.png?raw=true)
*`images/example-red-car.tga`*

![](screenshots/example-red-car-visiblesim.png?raw=true)
*"Screenshot of VisibleSim when loaded with the configuration file `build/example-red-car.xml`*