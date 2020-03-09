class Street {
  float ypos;
  String location;

  Street(float y, String s) {
    ypos = y;
    location = s;
  }

  void drawStreet() {
    fill(129, 129, 129);
    stroke(255);
    strokeWeight(5);
    rect(-6, ypos, (width + 12), 100);

    fill(255);
    textSize(30);
    text(location + " City Street", 975, (ypos + 60));
  }
}