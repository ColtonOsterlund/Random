class ParkingLot {
  float xpos;
  float ypos;
  float lotWidth;
  float lotHeight;
  ParkingStallSection [][] PSS = new ParkingStallSection[2][3];

  ParkingLot(float x, float y, float Width, float Height) {
    xpos = x;
    ypos = y;
    lotWidth = Width;
    lotHeight = Height;
  }

  void drawLot() {
    fill(129, 129, 129);
    stroke(255);
    strokeWeight(5);
    rect(xpos, ypos, lotWidth, lotHeight);

    float x = 300;
    float y = 400;
    float w = 700;
    float h = 200;

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        PSS[i][j] = new ParkingStallSection(x, y, w, h);
        PSS[i][j].drawSection();
        y += 300;
      }
      x += 900;
      y = 400;
    }
  }
}