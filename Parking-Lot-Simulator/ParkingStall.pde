class ParkingStall {
  // STALL ATTRIBUTES
  boolean occupied;
  Date timeTaken;

  // DIMENSIONS AND POSITION
  float stallWidth;
  float stallHeight;
  float posX;
  float posY;

  ParkingStall(float x, float y, float w, float h) {
    occupied = false;
    posX = x;
    posY = y;
    stallWidth = w;
    stallHeight = h;
  }

  void drawStall() {
    if (occupied == false) {
      fill(0, 255, 0);
    } else if (occupied == true) {
      fill(255, 0, 0);
    }

    stroke(255);
    strokeWeight(5);
    rect(posX, posY, stallWidth, stallHeight);
  }
}