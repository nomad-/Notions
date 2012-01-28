// includes
#include "global.h"

// global variables.
vector<Triple> freePoints;
vector<Triple> velocities;
vector<GLdouble> velocity_magnitudes;

vector<Statistics> line_stats;
vector<Triple> line_segments;
vector<PolyLine> polyLines;

unsigned int windowWidth = 768;
unsigned int windowHeight = 970;
double multiplier;
GLdouble max;
GLdouble min;
GLdouble threshold;
GLdouble relative_threshold = 0.15;

int selected = -1;

unsigned char point_layer_status = PLAIN_POINTS;
bool line_segment_layer_status = 0;
bool line_strip_layer_status = 1;
bool grid_layer_status = 1;

GLdouble angle_step = PI/4;
GLdouble intercept_step = 10.0;



ofstream velocity_magnitudes_file("c:/velocity_magnitudes.txt");
ostream_iterator<GLdouble> outIter(velocity_magnitudes_file,"\n");