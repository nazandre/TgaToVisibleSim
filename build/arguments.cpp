#include <iostream>
#include <cstdlib>
#include "arguments.hpp"

using namespace std;

Arguments::Arguments() {}

Arguments::Arguments(int argc, char *argv[]) {

  argv++;
  argc--;

  while ((argc > 0) && (argv[0][0] == '-')) {
    switch(argv[0][1]) {
    case 'i':
      input = argv[1];
      argc--;
      argv++;
      break;
    case 'o':
      output = argv[1];
      argc--;
      argv++;
      break;
    case 'h':
      help();
      break;
    default:
      help();
    }
    argc--;
    argv++;
  }

  if (input == "") {
    cerr << "ERROR: No TGA input image specified." << endl;
    help();
  }

  size_t lastDot = input.find_last_of(".");
  string ext = input.substr(lastDot + 1);
  if (ext != "tga") {
    cerr << "ERROR: Input file is not a TGA image." << endl;
    help();
  }
  
  if (output == "") {
    size_t lastSlash = input.find_last_of("/\\");
    string n =  input.substr(0, lastDot).substr(lastSlash+1);
    output = n + ".xml";
  }
}

Arguments::Arguments(const Arguments &a) {
  input = a.input;
  output = a.output;
}

Arguments::~Arguments() { }

void Arguments::help() {
  //cerr << "TGA To VisibleSim Configuration File" << endl;
  cerr << "\nUsage: tgaToVisibleSim -i <input tga image> [options]"<< endl;
  cerr << "Options:" << endl;
  cerr << "  " << "-o <output xml file> : output configuration file for VisibleSim" << endl;
  cerr << "  " << "-h                   : print this usage and exit" << endl;
  exit(EXIT_SUCCESS);
} 
