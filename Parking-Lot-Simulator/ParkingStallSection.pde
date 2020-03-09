class ParkingStallSection {
  float xStart;
  float yStart;
  float yReset;
  float sectionWidth;
  float sectionHeight;
  ParkingStall [][] PStall = new ParkingStall[5][2];


  ParkingStallSection(float x, float y, float w, float h) {
    xStart = x;
    yStart = y;
    yReset = y;
    sectionWidth = w;
    sectionHeight = h;
  }



  void drawSection() {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 2; j++) {
        PStall[i][j] = new ParkingStall(xStart, yStart, (sectionWidth/5), (sectionHeight/2));
        PStall[i][j].drawStall();
        yStart += 100;

        if (PStall[i][j].occupied == true)
          Gate.open = false;
      }
      xStart += 140;
      yStart = yReset;
    }
  }
}