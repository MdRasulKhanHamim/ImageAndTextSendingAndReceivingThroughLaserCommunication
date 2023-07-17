PImage img;
String str = "";

//str = "237 30 84 255 205 30 237 30 84 255 84 30 237 30 84 255 84 30 237 30 205 255 84 30 237 28 230 135 242 85 230 28 230 135 242 135 230 28 230 135 242 135 230 28 230 85 242 135 230 28 36 86 255 0 207 86 36 86 255 0 255 86 36 86 255 0 255 86 36 86 207 0 255 86 36";

void setup() 
{
  size(640, 360);
  //size(200,200); //make our canvas 200 x 200 pixels big
  
    img = loadImage("image3.png");
    img.loadPixels();
      int dimension = img.width * img.height;
      float[] red = new float[dimension];
      float[] green = new float[dimension];
      float[] blue = new float[dimension];
      
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      int loc = x + y*img.width;

      // The functions red(), green(), and blue() pull out the 3 color components from a pixel.
      float r = red(img.pixels[loc]);
      float g = green(img.pixels[loc]);
      float b = blue(img.pixels[loc]);
      //println(r,g,b);
      red[loc] = r;
      green[loc] = g;
      blue[loc] = b;
      // Image Processing would go here
      // If we were to change the RGB values, we would do it here,
      // before setting the pixel in the display window.

      // Set the display pixel to the image pixel
      //pixels[loc] =  color(r,g,b);
    }
  }
  
    float[] allpixels = new float[dimension*3];
  
    for (int i = 0; i < dimension; i++) {
  allpixels[i] = red[i];
}
    for (int i = dimension; i < dimension*2; i++) {
  allpixels[i] = green[i-dimension];
}
  for (int i = dimension*2; i < dimension*3; i++) {
  allpixels[i] = blue[i-dimension*2];
}

for (int i = 0; i < dimension*3; i++) {
  if (i<dimension*3-1)
  {
  str = str + str(int(allpixels[i])) + " ";
  }
  else
  {
  str = str + str(int(allpixels[i]));
  }
}
print(str);
image(img,0,0, img.width*50,img.height*50);
  
}


void draw() {
  
}
