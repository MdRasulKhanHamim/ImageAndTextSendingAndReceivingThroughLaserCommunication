String str = "237 30 84 255 205 30 237 30 84 255 84 30 237 30 84 255 84 30 237 30 205 255 84 30 237 28 230 135 242 85 230 28 230 135 242 135 230 28 230 135 242 135 230 28 230 85 242 135 230 28 36 86 255 0 207 86 36 86 255 0 255 86 36 86 255 0 255 86 36 86 207 0 255 86 36";;     // Data received from the serial port
int dimension = 25;

void setup()
{
size(640,360);
}

void draw()
{

int[] allpixelsagain = int(split(str,' '));
//println(allpixelsagain);

  int[] redagain = new int[dimension];
  int[] greenagain = new int[dimension];
  int[] blueagain = new int[dimension];
    for (int i = 0; i < dimension; i++) {
  redagain[i] = allpixelsagain[i];
}
    for (int i = dimension; i < dimension*2; i++) {
  greenagain[i-dimension] = allpixelsagain[i];
}
  for (int i = dimension*2; i < dimension*3; i++) {
  blueagain[i-dimension*2] = allpixelsagain[i];
}

PImage newimg = createImage(5, 5, RGB);
newimg.loadPixels();
for (int i = 0; i < newimg.pixels.length; i++) {
  newimg.pixels[i] = color(redagain[i], greenagain[i], blueagain[i]); 
}
newimg.updatePixels();
image(newimg, 0, 0, newimg.width*50, newimg.height*50);

}
